#include <stdio.h>
#include <ctype.h>

// func to check if input is valid (only numbers)
int checkNum(char stringNum[])
{
    int secondSum, notCheckedSum, i, single;
	secondSum = notCheckedSum = 0;
// check if characters are numbers
    for (i = 0; stringNum[i] != '\0'; i++)
	{
		if (! isdigit(stringNum[i]))
		{
            return 0;
        }
    }
// set the i at the last character in a string
	i--;
// multiply every second number from the right
	int j;
	for (j = 1; i != -1; i--, j++)
	{
		single = stringNum[i] - '0';
		if (j % 2 == 0)
		{
			single *= 2;
// seperate two digit numbers
			if (single > 9)
			{
				int twoDigit = single;
				while (twoDigit > 0)
				{
        			single = twoDigit % 10;
        			twoDigit /= 10;
					secondSum += single;
    			}
			}
			else
			{
				secondSum += single;
			}
		}
		else
		{
			notCheckedSum += single;
		}
	}

// Return the final sum of two sums
	int finalSum = notCheckedSum + secondSum;
    return finalSum;
}

int main(void)
{
    char stringNum1[64], ch;
	int status = 0;
    int firstDigit, secondDigit, cardNums;

	int finalSum = 0;
    do
	{
        int i = 0;
        printf("Number: ");
// prompt for re-input if the number contains invalid characters
        while ( (ch = getchar()) != '\n')
		{
            stringNum1[i] = ch;
            i++;
        }
        finalSum = checkNum(stringNum1);
		cardNums = i;
    }
	while (finalSum == 0);
// get the first identifier digit
	firstDigit = stringNum1[0] - '0';
// get the first two identifier digits
	int firstTwo = (stringNum1[0] - '0') * 10 + stringNum1[1] - '0';
// check if the conditions are valid
	if (finalSum % 10 == 0)
	{
		if (cardNums >= 13 && cardNums <= 16)
		{
			status = 1;
		}
	}
// if the conditions are valid execute
	if (status)
	{

		if (firstTwo == 34 || firstTwo == 37)
		{
			printf("AMEX\n");
		}
		else if (firstDigit == 4)
		{
			printf("VISA\n");
		}
		else if (firstTwo >= 51 && firstTwo <= 55)
		{
			printf("MASTERCARD\n");
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
