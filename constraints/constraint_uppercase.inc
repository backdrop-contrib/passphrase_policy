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
function passphrase_policy_constraint_uppercase_description() {
  return array('name' => t('Uppercase'), 'description' => t('Password must contain the specified minimum number of uppercase letters.'));
}

/**
 * Error message of the constraint.
 */
function passphrase_policy_constraint_uppercase_error() {
  return t('Password must contain at least one uppercase letter when less than 20 characters.');
}

/**
 * Password validation.
 */
function passphrase_policy_constraint_uppercase_validate($password, $account) {
  $chars = backdrop_strlen($password);
  $num = 0;
  if ($chars < 20) {
    for ($i = 0; $i < $chars; ++$i) {
      if (ctype_upper(backdrop_substr($password, $i, 1))) {
        $num++;
      }
    }
    return $num >= 1;
  }
  else
    return TRUE;
}

/**
 * Javascript portion.
 */
function passphrase_policy_constraint_uppercase_js($account) {
  return <<<JS

    var i = 0;
    var num = 0;
    var chr = "";
    if (value.length < 20) {
      while (i < value.length) {
        chr = value.charAt(i);
        if (chr.toUpperCase() != chr.toLowerCase()) {
          if (chr == chr.toUpperCase()) {
            num++;
          }
        }
        i++;
      }
      if (num < 1) {
        strength = "low";
        msg.push(translate.constraint_uppercase);
      }
    }
JS;
}
