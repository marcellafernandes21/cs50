#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to validate if a string represents a positive integer
int is_positive_integer(const char *str)
{
    while (*str)
    {
        if (!isdigit(*str))
        {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to encrypt plaintext using Caesar cipher
void encrypt(char *plaintext, int key)
{
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            plaintext[i] = (c - base + key) % 26 + base;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <key>\n", argv[0]);
        return 1;
    }

    // Get the key from the command-line argument
    char *key_str = argv[1];
    if (!is_positive_integer(key_str))
    {
        printf("Key must be a positive integer.\n");
        return 1;
    }

    int key = atoi(key_str);

    if (key <= 0)
    {
        printf("Key must be a positive integer.\n");
        return 1;
    }

    // Get plaintext from the user
    char plaintext[MAX_LENGTH];
    printf("Enter the plaintext: ");
    if (fgets(plaintext, sizeof(plaintext), stdin) == NULL)
    {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove newline character from fgets, if present
    plaintext[strcspn(plaintext, "\n")] = '\0';

    // Encrypt the plaintext
    encrypt(plaintext, key);

    // Print the encrypted message
    printf("ciphertext: %s\n", plaintext);

    return 0;
}
