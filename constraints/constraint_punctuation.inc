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
function passphrase_policy_constraint_punctuation_description() {
  return array('name' => t('Punctuation'), 'description' => t('Password must contain the specified minimum number of punctuation (not whitespace or an alphanumeric) characters.'));
}

/**
 * Error message of the constraint.
 */
function passphrase_policy_constraint_punctuation_error() {
  return t('Password must contain at least one punctuation mark when less than 12 characters.');
}

/**
 * Password validation.
 */
function passphrase_policy_constraint_punctuation_validate($password, $account) {
  $chars = backdrop_strlen($password);
  $num = 0;
  if ($chars < 12) {
    for ($i = 0; $i < $chars; ++$i) {
      if (ctype_punct(backdrop_substr($password, $i, 1))) {
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
function passphrase_policy_constraint_punctuation_js($account) {
  return <<<JS

    var i = 0;
    var num = 0;
    var chr = "";
    if (value.length < 12) {
      while (i < value.length) {
        chr = value.charAt(i);
        if (chr.toUpperCase() == chr.toLowerCase() && "1234567890".indexOf(chr) == -1 && chr != ' ') {
          num++;
        }
        i++;
      }
      if (num < 1) {
        strength = "low";
        msg.push(translate.constraint_punctuation);
      }
    }
JS;
}
