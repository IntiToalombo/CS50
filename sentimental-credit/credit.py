
# get card number
def card_number(prompt):
    lenCard = [13, 15, 16]
    while True:
        try:
            cnumber = input(prompt)
            if int(cnumber) > 0 and len(cnumber) in lenCard:
                return cnumber
            else:
                print("INVALID")
                break
        except ValueError:
            #print("Invalid card number. Please try again.")
            print("INVALID")

# validate if typen number is valid
def validation(n):
    skip = 0
    skip1= 0

    # Iteration through string card number
    for i in n[-2:None:-2]: # Starts from right to left skiping one position
         product = int(i) * 2 # Multply each digit by 2
         while product > 0: # Get each digit of product
             digit = product % 10
             product = product // 10 # take out one digit at the time
             skip += digit

    # Iteration through string card number
    for i in n[-1:None:-2]:
        skip1 += int(i)
    sum = skip + skip1

    # if sum ends in 0 returns True
    if sum % 10 == 0:
        return True
    else:
        return False
def main():
    c = card_number("Number: ")

    # Create a dictionary with MasterCard data
    MasterCard = {
            "digits":[16],
            "StartWith":[51, 52, 53, 54, 55]
            }

    # Create a dictionary with American Express data
    Amex = {
        "digits":[15],
        "StartWith":[34, 37]
    }
    # Create a dictionary with Visa data
    Visa = {
        "digits":[13, 16],
        "StartWith":[4]
    }
    # Master Card validation
    if validation(c) == True and len(c) in MasterCard["digits"] and int(c[:2]) in MasterCard["StartWith"]:
        print("MASTERCARD")

    # Amex validation
    elif validation(c) == True and len(c) in Amex["digits"] and int(c[:2]) in Amex["StartWith"]:
        print("AMEX")

    # Visa validation
    elif validation(c) == True and len(c) in Visa["digits"] and int(c[:1]) in Visa["StartWith"]:
        print("VISA")
    else:
        print("INVALID")
main()

