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
function passphrase_policy_constraint_digit_description() {
  return array('name' => t('Digit'), 'description' => t('Password must contain the specified minimum number of digits.'));
}

/**
 * Error message of the constraint.
 */
function passphrase_policy_constraint_digit_error() {
  return t('Password must contain at least one number when it is 15 characters or less.');
}

/**
 * Password validation.
 */
function passphrase_policy_constraint_digit_validate($password, $account) {
  $chars = backdrop_strlen($password);
  $num = 0;
  if ($chars < 16) {
    for ($i = 0; $i < $chars; ++$i) {
      if (ctype_digit(backdrop_substr($password, $i, 1))) {
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
function passphrase_policy_constraint_digit_js($account) {
  return <<<JS

    var i = 0;
    var num = 0;
    var chr = "";
    if (value.length < 16) {
      while (i < value.length) {
        chr = value.charAt(i);
        if ("1234567890".indexOf(chr) != -1) {
          num++;
        }
        i++;
      }
      if (num < 1) {
        strength = "low";
        msg.push(translate.constraint_digit);
      }      
    }
JS;
}
