import math

def get_cents(prompt):
    while True:
        try:
            cents = float(input(prompt))
            if cents > 0:
                return cents * 100 # multiply by 100 to obtain in integer cents
            else:
                return get_cents(prompt)
        except ValueError:
            print("Invalid format. Please try again.")
# Compute quarters 25 ctvs
def calculate_quarters(cents):
    quarters = cents / 25
    quarters = math.floor(quarters) # math.floor() rounds down to the nearest integer
    return quarters

# Compute dimmes 10 ctvs
def calculate_dimmes(cents):
    dimmes = cents / 10
    dimmes = math.floor(dimmes)
    return dimmes

# Compute nickels 5 ctvs
def calculate_nickles(cents):
    nickles = cents / 5
    nickles = math.floor(nickles)
    return nickles

# Compute pennies 1 ctvs
def calculate_pennies(cents):
    pennies = cents / 1
    pennies = math.floor(pennies)
    return pennies

def main():
    cents = get_cents("Change owed: ")
    quarters = calculate_quarters(cents)
    cents = cents - quarters*25

    dimmes = calculate_dimmes(cents)
    cents = cents - dimmes*10

    nickles = calculate_nickles(cents)
    cents = cents - nickles*5

    pennies = calculate_pennies(cents)
    cents = cents - pennies*1

    coins = quarters + dimmes + nickles + pennies
    print(int(coins))
main()

