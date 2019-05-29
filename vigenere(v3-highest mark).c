#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int shift(char c);

int main(int argc, string argv[])
{
    // Count command line arg
    if (argc == 2)
    {
        // Validate the key from user
        int y = strlen(argv[1]);
        for (int i = 0; i < y; i++)
        {
            if(!isalpha(argv[1][i]))
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }
        }
        // Shift Key
        string key = argv[1];
        // Execute
        if (key >= 0)
        {
            // Prompt for plaintext
            string s = get_string("plaintext:  ");

            // Generate ciphertext
            for (int j = 0, n = strlen(s); j < n; j++)
            {
                if (!isalpha(s[j]))
                {
                    printf("Usage: ./vigenere key\n");
                    return 1;
                }
            }
            printf("ciphertext: ");
            for (int i = 0, n = strlen(s); i < n; i++)
            {
                // If upper case
                if (isupper(s[i]))
                {
                    char x = s[i];
                    char ciphertext = (((x + shift(key[i % y])) - 65) % 26) + 65;
                    printf("%c", ciphertext);
                }
                // If lower case
                else if (islower(s[i]))
                {
                    char x = s[i];
                    int ciphertext = (((x + shift(key[i % y])) - 97) % 26) + 97;
                    printf("%c", ciphertext);
                }
            }
            printf("\n");
            return 0;
        }
        else
        {
            printf("Usage: ./vigenere key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./vigenere key\n");
        return 1;
    }
    return 0;
}

int shift(char c)
{
    // If upper case
    if (isupper(c))
    {
        c = (c - 65) % 26;
    }
    // If lower case
    else if (islower(c))
    {
        c = (c - 97) % 26;
    }
    return c;
}
