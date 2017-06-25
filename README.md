Passphrase Policy
=================

Enforce restrictions on user passwords by defining a password policy that encourages the use of pass phrases.

The password constraints are pre-defined and must be met before a user password change will be accepted. Each constraint has a parameter allowing for the minimum number of valid conditions which must be met before the constraint is satisfied.

The password rules follow the model from Stanford University's IT department. Stanford recommends "pass phrases" instead of passwords. Pass phrases are longer, but easier to remember than complex passwords, and if well-chosen can provide better protection against hackers.

Stanford's password rules change based on password length:

* 10-11: mixed case letters, numbers, & symbols
* 12-15: mixed case letters & numbers
* 16-19: mixed case letters
* 20+: no restrictions

It must not be equal to your previous password or contain your username.

The rules meet or exceed the following public standards:

* [PCI-DSS v3.2](https://www.pcisecuritystandards.org/documents/PCI-DSS-v3_2-SAQ-D_ServiceProvider.pdf) 8.2.3
* [PCI-DSS v3.2](https://www.pcisecuritystandards.org/documents/PCI-DSS-v3_2-SAQ-D_ServiceProvider.pdf) 8.2.5
* [NIST SP 800-63-2](http://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-63-2.pdf) Level 1
* [NIST SP 800-63-2](http://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-63-2.pdf) Level 2
  (if user [flood control](https://github.com/backdrop-contrib/flood_control) window is set to at least 13 hours)
* [Australian Government ISM](http://www.asd.gov.au/infosec/ism/)
  Control: 0421; Revision 4; Updated: Apr-15.
  Applicable up to SECRET information and systems.
* [Australian Government ISM](http://www.asd.gov.au/infosec/ism/)
  Control: 0422; Revision 4; Updated: Apr-15.
  Applicable up to TOP SECRET information and systems when combined with two-factor authentication.

Most of the [CWE-521: Weak Password Requirements](https://cwe.mitre.org/data/definitions/521.html) are also resolved by this.

![Stanford University IT Password Requirements Quick Guide](images/pwstrength.jpg)

Usage
-----

Enable the module for full functionality. There is no configuration.

Having no configuration is intentional because it prevents users from altering the password rules when they're annoyed by them. Disabling the module logs a high level alert for administrators to review.


Current Maintainer
------------------

* None


Credits
-------

* Drupal 4.7 version of Password Policy was written by David Ayre (https://www.drupal.org/user/67245)
* Refactored and maintained by Miglius Alaburda (https://www.drupal.org/user/18741)
* Edited over the years by a ton of people (https://www.drupal.org/node/85872/committers)
* Password rules by Stanford University IT (https://uit.stanford.edu/service/accounts/passwords)
* Selected parts ported to Backdrop as a renamed module by David Norman (https://github.com/deekayen)
