from cs50 import get_float


def main():
    # Prompt user for the amount of change owed
    while True:
        change = get_float("Change owed: ")
        if change > 0:
            break

    # Convert dollars to cents
    cents = round(change * 100)

    # Initialize coin count
    coins = 0

    # Calculate the number of quarters
    coins += cents // 25
    cents %= 25

    # Calculate the number of dimes
    coins += cents // 10
    cents %= 10

    # Calculate the number of nickels
    coins += cents // 5
    cents %= 5

    # Calculate the number of pennies
    coins += cents // 1
    cents %= 1

    # Print the total number of coins
    print(coins)


if __name__ == "__main__":
    main()
