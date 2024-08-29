#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int cents;
    int coins = 0;

    while (1)
    {
        printf("Enter the amount of change in cents (positive integer): ");

        // Check if the input is a valide integer
        if (scanf("%d", &cents) != 1)
        {
            // Clear the input buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a positive integer.\n");
            continue;
        }

        // Check if the amount is non-negative
        if (cents < 0)
        {
            printf("Amount must be greater than or equal to 0. Please try again.\n");
            continue;
        }

        break; // Input is valid, exit loop
    }

    // Calculate the number of coins needed
    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents -= 25;
        }
        else if (cents >= 10)
        {
            cents -= 10;
        }
        else if (cents >= 5)
        {
            cents -= 5;
        }
        else
        {
            cents -= 1;
        }
        coins++;
    }

    // Output the result
    printf("Minimum number of coins needed: %d\n", coins);

    return 0;
}
