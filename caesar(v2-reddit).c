#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Count command line arg
    if (argc == 2)
    {
        // Validate the key from user
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if(isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        int k = atoi(argv[1]);
        if (k >= 0)
        {
            // Prompt for plaintext
            string s = get_string("plaintext:  ");

            // Generate ciphertext
            printf("ciphertext: ");
            for (int i = 0, n = strlen(s); i < n; i++)
            {
                // If upper case
                if ((65 <= s[i]) && (s[i] <= 90))
                {
                    char x = s[i];
                    char ciphertext = (((x + k) - 65) % 26) + 65;
                    printf("%c", ciphertext);
                }
                // If lower case
                else if ((97 <= s[i]) && (s[i] <= 122))
                {
                    char x = s[i];
                    char ciphertext = (((x + k) - 97) % 26) + 97;
                    printf("%c", ciphertext);
                }
            }
            printf("\n");
            return 0;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 0;
}
