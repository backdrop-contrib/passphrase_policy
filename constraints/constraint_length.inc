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
function passphrase_policy_constraint_length_description() {
  return array('name' => t('Length'), 'description' => t('Password must be equal to or longer than the specified minimum length.'));
}

/**
 * Error message of the constraint.
 */
function passphrase_policy_constraint_length_error() {
  return t('Password must be at least 8 characters in length.');
}

/**
 * Password validation.
 */
function passphrase_policy_constraint_length_validate($password, $account) {
  $length = backdrop_strlen($password);
  return $length >= 8;
}

/**
 * Javascript portion.
 */
function passphrase_policy_constraint_length_js($account) {
  return <<<JS

    if (!value.length || value.length < 8) {
      strength = "low";
      msg.push(translate.constraint_length);
    }
JS;
}
