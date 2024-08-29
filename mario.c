#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int height;

    while (1)
    {
        printf("Enter the hright of the pyramid (positive integer): ");

        // Check if the input is a valid integer
        if (scanf("%d", &height) != 1)
        {
            // Clear the input buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a positive integer.\n");
            continue;
        }

        // Check if the height is greater than 0
        if (height <= 0)
        {
            printf("Height must be greater than 0. Please try again.\n");
            continue;
        }
        break; // Input is valid, exit the loop
    }

    //Print the pyramud
    for (int i = 1; i <= height; i++)
    {
    // Print leading spaces
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        // Print hashes
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        // Print new line
        printf("\n");
    }
    return 0;
}
