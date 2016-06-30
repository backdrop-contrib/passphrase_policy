<?php
/**
 * @file
 * Password policy constraint callbacks.
 */

/****************************************************************************/
/* Constraint API                                                           */
/****************************************************************************/

/**
 * Description of the constraint.
 */
function passphrase_policy_constraint_history_description() {
  return array('name' => t("History"), 'description' => t("Password must not match any of the user's previous X passwords.") . " <br/><b>" . t("Note:") . " </b>" . t("This constraint can only compare a new password with the previous passwords recorded since the password policy module was enabled.  For example, if the number of previous passwords is set to 3, the module may have only recorded 2 password changes since the module was enabled.  If the recorded password history is not large enough to support the constraint history size, the history size for the constraint will be reduced (temporarily during the constraint check) to match the available recorded history. Also note that a history size of 1 means that the user is unable to change their password to their current password.  This can be useful in certain situations, but a setting of 2+ will likely be more useful.  Enter 'all' to compare all previous passwords"));
}

/**
 * Error message of the constraint.
 */
function passphrase_policy_constraint_history_error() {
  return t('Password must not match any previous password.');
}

/**
 * Password validation.
 */
function passphrase_policy_constraint_history_validate($password, $account) {
  require_once BACKDROP_ROOT . '/' . settings_get('password_inc', 'core/includes/password.inc');
  $temporary_account = clone $account;
  $old_passwords = _passphrase_policy_constraint_history_old_passwords($account->uid);
  foreach ($old_passwords as $old_password) {
    $temporary_account->pass = $old_password;
    if (user_check_password($password, $temporary_account)) {
      return FALSE;
    }
  }

  return TRUE;
}

/****************************************************************************/
/* Auxiliary                                                                */
/****************************************************************************/


/**
 * Gets old password hashes.
 */
function _passphrase_policy_constraint_history_old_passwords($uid) {
  $pass = array();
  if (!empty($uid)) {
    $query = db_select('passphrase_policy_history', 'p', array('fetch' => PDO::FETCH_ASSOC, 'target' => 'slave'));
    $query->fields('p', array('pass'))
      ->condition('p.uid', $uid);
    $result = $query->execute();

    while ($row = $result->fetchAssoc()) {
      $pass[] = $row['pass'];
    }
  }
  return $pass;
}
