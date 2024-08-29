from cs50 import get_string
import math


def main():
    # Get the user's input
    text = get_string("Text: ")

    # Initialize counts
    letters = 0
    words = 1  # Start with 1 because there's always at least one word
    sentences = 0

    # Count letters, words, and sentences
    for char in text:
        if char.isalpha():
            letters += 1
        elif char == ' ':
            words += 1
        elif char in '.!?':
            sentences += 1

    # Calculate L and S
    L = (letters / words) * 100
    S = (sentences / words) * 100

    # Calculate the Coleman-Liau index
    index = 0.0588 * L - 0.296 * S - 15.8

    # Determine the grade level
    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {round(index)}")


if __name__ == "__main__":
    main()
