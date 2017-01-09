#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int cipherUpperCase(int c, int k);
int cipherLowerCase(int c, int k);
void NowYouFuckedUp(void);


int main(int argc, char* argv[])
{
    if(argc < 2 || argc > 2)
    {
        NowYouFuckedUp();
        return 1;
    }
    
    int k = atoi(argv[1]);
    if(k < 1)
    {
        NowYouFuckedUp();
        return 1;
    }
    
    

    //printf("%i is the key before modulo\n", k);

    k = k % 26;
    
    //printf("%i is the key post modulo\n", k);
    string inputString = GetString(); // get a string from the user, save it in the inputString variable
    
    for(int i = 0; i < strlen(inputString); i++)
    {
        if(isalpha(inputString[i]))
        {
            if(isupper(inputString[i]))
            {
                printf("%c", cipherUpperCase(inputString[i], k));
            }
            if(islower(inputString[i]))
            {
                printf("%c", cipherLowerCase(inputString[i], k));
            }
        }
        else
        {
            printf("%c", inputString[i]);
        }
    }
    printf("\n");
    return 0;
}

int cipherUpperCase(int p, int k)
{
    if((p + k) > 90)
    {
        return ((p + k) - 90) + 64; // Loop around the ascii UPPERCASE values if necessary
    }
    else
    {
        return (p + k);
    }
}

int cipherLowerCase(int p, int k)
{
    if((p + k) > 122)
    {
        return ((p + k) - 122) + 96; // Loop around the ascii lowercase values if necessary
    }
    else
    {
        return p + k;
    }
    
}

void NowYouFuckedUp(void)
{
    printf("Now you fucked up!\nNow you fucked up!\nYou have fucked up now!\n");
    printf("When initializing this program please be sure to provide an interger greater than 0 as the second command line argument\nNo additional command line arguments are allowed.\n");
    
}