#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void NowYouFuckedUp(void);
int upperKeyFinder(int c);
int lowerKeyFinder(int c);
int cipherUpperCase(int c, int k);
int cipherLowerCase(int c, int k);

int main(int argc, char* argv[])
{
    if(argc < 2 || argc > 2)
    {
        NowYouFuckedUp();
        return 1;
    }
    
    int keyLen = strlen(argv[1]);
    int keyArray[keyLen]; //create an array of key values to be used in caesar ciphering
    for(int i = 0; i < keyLen; i++) //loop through the characters in the key and determine their key values
    {
        if(!(isalpha(argv[1][i]))) //if any character in the key is not alpha, MDK the script
        {
            NowYouFuckedUp();
            return 1;
        }
        if(isupper(argv[1][i]))
        {
            keyArray[i] = upperKeyFinder(argv[1][i]);
        }
        if(islower(argv[1][i]))
        {
            keyArray[i] = lowerKeyFinder(argv[1][i]);
        }
    
    }
    
    //bug detection stuffs
    printf("The key array values are: ");
    for(int i = 0; i < keyLen; i++)
    {
        printf("%i,", keyArray[i]);
    }
    printf("\n");
    //end bug detection stuffs */
    //printf("Enter the text to be encrypted:\n"); //hide before running cs50 check
    string inputString = GetString();
    int inputStringLen = strlen(inputString);
    if(inputStringLen <= 0)
    {
        printf("You did not enter a string to encrypt. Restart the script, please!\n");
        return 1;
    }


    
    int j = 0;
    for(int i = 0; i < inputStringLen ; i++) //loop through the text to encrypt
    {
        if(isalpha(inputString[i]))
        {
            if(isupper(inputString[i]))
            {
                printf("%c", cipherUpperCase(inputString[i], keyArray[j % keyLen]));
            }
            if(islower(inputString[i]))
            {
                printf("%c", cipherLowerCase(inputString[i], keyArray[j % keyLen]));
            }
            j++;
        }
        else
        {
            printf("%c", inputString[i]);
        }
    }
    printf("\n");
    return 0;
}

void NowYouFuckedUp(void)
{
    printf("Now you fucked up!\nNow you fucked up!\nYou have fucked up now!\n");
    printf("When initializing this program please be sure to provide an encryption key argument comprised exclusively of alphabetical characters.\n");
    
}

int upperKeyFinder(int c) //finds the alpha index (ie A = 1, B = 2, Z = 26)
{
    return c - 65;
}

int lowerKeyFinder(int c) //find the alpha index (a = 1, f = 6, z = 26)
{
    return c - 97;
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