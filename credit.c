/*
Credit (Problem Set 1 for CS50 - Instructions)

A credit (or debit) card, of course, is a plastic card with which you can pay for goods and services. Printed on that card is a number that’s also stored in a database somewhere, so that when your card is used to buy something, the creditor knows whom to bill. There are a lot of people with credit cards in this world, so those numbers are pretty long: American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers. And those are decimal numbers (0 through 9), not binary, which means, for instance, that American Express could print as many as 10^15 = 1,000,000,000,000,000 unique cards! (That’s, um, a quadrillion.)

Actually, that’s a bit of an exaggeration, because credit card numbers actually have some structure to them. All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55; and all Visa numbers start with 4. But credit card numbers also have a “checksum” built into them, a mathematical relationship between at least one number and others. That checksum enables computers (or humans who like math) to detect typos (e.g., transpositions), if not fraudulent numbers, without having to query a database, which can be slow. Of course, a dishonest mathematician could certainly craft a fake number that nonetheless respects the mathematical constraint, so a database lookup is still necessary for more rigorous checks.

Luhn’s Algorithm
So what’s the secret formula? Well, most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:

Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
Add the sum to the sum of the digits that weren’t multiplied by 2.
If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
That’s kind of confusing, so let’s try an example with David’s Visa: 4003600000000014.

For the sake of discussion, let’s first underline every other digit, starting with the number’s second-to-last digit:

4003600000000014

Okay, let’s multiply each of the underlined digits by 2:

1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2

That gives us:

2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

Now let’s add those products’ digits (i.e., not the products themselves) together:

2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13

Now let’s add that sum (13) to the sum of the digits that weren’t multiplied by 2 (starting from the end):

13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20

Yup, the last digit in that sum (20) is a 0, so David’s card is legit!

So, validating credit card numbers isn’t hard, but it does get a bit tedious by hand. Let’s write a program.

Implementation Details
In credit.c at right, write a program that prompts the user for a credit card number and then reports (via printf) whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein. So that we can automate some tests of your code, we ask that your program’s last line of output be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n, nothing more, nothing less. For simplicity, you may assume that the user’s input will be entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card). But do not assume that the user’s input will fit in an int! Best to use get_long from CS50’s library to get users’ input. (Why?)

Consider the below representative of how your own program should behave when passed a valid credit card number (sans hyphens).

$ ./credit
Number: 4003600000000014
VISA
Now, get_long itself will reject hyphens (and more) anyway:

$ ./credit
Number: 4003-6000-0000-0014
Number: foo
Number: 4003600000000014
VISA
But it’s up to you to catch inputs that are not credit card numbers (e.g., a phone number), even if numeric:

$ ./credit
Number: 6176292929
INVALID
Test out your program with a whole bunch of inputs, both valid and invalid. (We certainly will!) Here are a few card numbers that PayPal recommends for testing.

If your program behaves incorrectly on some inputs (or doesn’t compile at all), time to debug!
*/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long long ccNum;
    // Prompt user to enter ccNum
    ccNum = get_long("Number: ");
    // Prompt user to enter ccNum again if input was zero or negative
    while (ccNum <= 0)
    {
        printf("Number: foo\n");
        ccNum = get_long("Number: ");
    }
    // Verify validity of ccNum
    int length = 0;
    long long validcheck = ccNum;
    while (validcheck > 0)
    {
        validcheck = validcheck/10;
        length++;
    }
    if (length != 13 && length != 15 && length != 16)
    {
        printf("Invalid\n");
    }
    // Checksum digits
    // Had problems with overflow at first - needed to reconfigure variables to long long
    // pow would return a float; double is a float; % is an operator that only accepts int therefore must use long
    int sum = 0;
    long long int realsum = 0;
    long long int x = 0;
    long y = 0;
    int n = 0;
    do
    {
        n++;
        // This section multiplies every other digit by 2, starting with the number's
        // second-last digit (i.e. 4_0_0_1; _ will be selected); add those product's
        // digits (i.e. 1*2 + 6*2 = 2 + 12 becomes 2 + 1 + 2) together; then add on the
        // total sum of all other digits that weren't multiplied by 2
        if (n%2==0)
        {
            // putting (long long int) before pow changes it from a float to an int
            x = (ccNum%(long long int)pow(10, n)) - realsum;
            y = (2*x/pow(10,n-1));
            if (y>10)
            {
                sum = sum + 1 + (y%10);
            }
            else
            {
                sum = sum + y;
            }
            realsum = realsum + x;
        }
        // This section isolates digits that need not be multiplied and add it on to the
        // total sum
        else
        {
            x = (ccNum%(long long int)pow(10, n)) - realsum;
            sum = sum + (x/pow(10,n-1));
            realsum = realsum + x;
        }
    }
    while (n<length);
    if (sum%10 != 0)
    {
        printf("INVALID\n");
    }
    // Store first digit of ccNum in x
    x = 0;
    n = 0;
    do
    {
        n++;
        x = (ccNum%(long long int)pow(10, n))/pow(10,n-1);
        // The above works because integer division truncates and throws out the remainder (e.g. 12/10 == 1)
    }
    while (n<length);
    // Store second digit of ccNum in y
    y = 0;
    n = 0;
    do
    {
        n++;
        y = (ccNum%(long long int)pow(10, n))/pow(10,n-1);
    }
    while (n<length-1);
    // Categorizing the ccNum
    if (length == 15)
    {
        if (((x == 3)&&(y==4)) || ((x == 3)&&(y==7)))
        {
           printf("AMEX\n");
        }
        else
        {
           printf("INVALID\n");
        }
    }
    else if (length == 16)
    {
        if (((x == 5)&&(y==1)) || ((x == 5)&&(y==2)) || ((x == 5)&&(y==3)) || ((x == 5)&&(y==4)) || ((x == 5)&&(y==5)))
        {
            printf("MASTERCARD\n");
        }
        else if (x == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (length == 13)
    {
        if (x == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
