
# get card number
def get_card_number(prompt):
    lenCard = [13, 15, 16]
    while True:
        try:
            cnumber = input(prompt)
            if cnumber.isdigit() and len(cnumber) in lenCard:
                return cnumber
            else:
                print("Invalid card number. Please try again")
        except ValueError:
            print("Invalid card number. Please try again.")

# validate if typen number is valid
def validation(cardNumber):
    total = 0
    even_digits = len(cardNumber) % 2 == 0 # even numbers ex: 2,4,6..
    # Iterates through card number and enumerates each digit
    for i, digit in enumerate(cardNumber):
        # Compute even digits
        if (i % 2 == even_digits):
            product = int(digit) * 2
            total += product // 10 + product % 10
        # Compute odd digits
        else:
            total += int(digit)
    # returns the last digit of total
    return total % 10
def identify_card_type(cardNumber):
    card_types = {
        "MasterCard": {"digits":[16], "start_with":[51, 52, 53, 54, 55]},
        "Amex": {"digits":[15], "start_with":[34, 37]},
        "Visa": {"digits":[13, 16], "start_with":[4]}
    }
    for card_type, properties in card_types.items():
        if validation(cardNumber) and len(cardNumber) in properties["digits"] and int(cardNumber[:len(str(properties["start_with"][0]))]) in properties["start_with"]:
            return card_type
    return "INVALID"
def main():
    c = get_card_number("Enter credit card number: ")
    print(identify_card_type(c))

if __name__ == "__main__":
    main()
