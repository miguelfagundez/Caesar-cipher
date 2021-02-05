#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, string args[])
{
    // Validation to handle only 2 entries
    if (argc == 2)
    {

        string argument = args[1];
        int n = strlen(argument);
        bool validNumber = true;
        char number[10];

        // Checking if argument is a number
        for (int i = 0; i < n; i++)
        {
            if (argument[i] < '0' || argument[i] > '9')
            {
                validNumber = false;
            }
            else
            {
                number[i] = argument[i];
            }
        }

        // Output
        if (validNumber)
        {
            string plainText = get_string("Insert plain text: ");
            printf("plaintext: %s\n", plainText);
            n = strlen(plainText);
            printf("ciphertext: ");
            int key = atoi(number);

            // A/Z and a/z in integer value
            int upperMax = 90;
            int upperMin = 65;
            int lowerMax = 122;
            int lowerMin = 97;

            // Checking if value is > 25, we need only the reminder <=25
            do
            {
                if (key > 25)
                {
                    key -= 26;
                }
            }
            while (key > 25);

            for (int i = 0; i < n; i++)
            {
                // Check if upeercase or lowercase
                int value = (int)plainText[i];
                if ((value >= upperMin && value <= upperMax) || (value >= lowerMin && value <= lowerMax))
                {
                    // Check if is A or a
                    if (value < upperMax)
                    {
                        // Uppercase
                        if ((value + key) > upperMax)
                        {
                            value = upperMin + (value + key - upperMax) - 1;
                            plainText[i] = value;
                        }
                        else
                        {
                            plainText[i] += key;
                        }
                    }
                    else
                    {
                        // Lowercase
                        if ((value + key) > lowerMax)
                        {
                            value = lowerMin + (value + key - lowerMax) - 1;
                            plainText[i] = value;
                        }
                        else
                        {
                            plainText[i] += key;
                        }
                    }
                }
                else
                {
                    // Nothing to do
                }
            }
            printf("%s\n", plainText);
            printf("\n");
        }
        else
        {
            // Error return 1 if not a number
            printf("Usage: ./caesar key");
            return 1;
        }

    }
    else
    {
        // Error return 1 if not entries or too many entries
        printf("Usage: ./caesar key");
        return 1;
    }

    return 0;
}