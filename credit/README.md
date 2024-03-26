# Credit Card Verifier
## Funtionality
This Python script verifies the genuinity of a credit card number using [Lunh's algorithm](https://en.wikipedia.org/wiki/Luhn_algorithm) and identifies the type of credit card(e.g., MasterCard, Amex, Visa)
## How to use
1. Run the script usin Python interpreter:
```
python credit.py
```
2. Enter the credit card number when prompted.
3. The script will validate the credit card number an identify its type(MasterCard, Amex or Visa).
## Example:
```
Enter credit credit card number: 4111111111111111
Visa
```
[Here](https://developer.paypal.com/api/nvp-soap/payflow/integration-guide/test-transactions/#standard-test-cards) you can find examples of genuine card numbers to test this script
# License
This project is licensed under the MIT license.
# Acknowledgments
* This script is based on the [Luhn's algorithm](https://en.wikipedia.org/wiki/Luhn_algorithm) for credit card validation.
* Credit card number genuinity verification inspored by problem set 6 [credit](https://cs50.harvard.edu/x/2024/psets/6/credit/).
