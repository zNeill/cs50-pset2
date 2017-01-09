#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int main(void)
{

    int NumberOfInitials = 0;
    //printf("please enter your Name: ");
    string Name = GetString(); //Collect the name
    
    int LenOfName = strlen(Name); //Store the legnth of the name in a variable
    
    if(LenOfName > 0)  // if you entered something the first letter is an initial
    {
        NumberOfInitials++;
    }
    
    for (int i = 1; i < LenOfName ; i++) //find spaces to find the number of initials
    {
         if(Name[i] == ' ')
         {
             //printf("I found a space at position %i\n", i);
             //printf("That means that the letter in position %i must be an initial!\n", i+1);
             NumberOfInitials++;
         }

    }

    //printf("%i initials found\n", NumberOfInitials);

    
    char InitialsArray[NumberOfInitials];
    
    int CurrentInitialsArrayPosition = 0;
    
    for (int i = 0; i < LenOfName ; i++)
    {
         if(i == 0)
         {
             InitialsArray[CurrentInitialsArrayPosition] = Name[i];
             CurrentInitialsArrayPosition++;
             //printf("script is putting the character in position %i into the initials array.", i);
             //printf(" Now the current intials array position is %i\n", CurrentInitialsArrayPosition);
         }
         if(Name[i-1] == ' ')
         {
            InitialsArray[CurrentInitialsArrayPosition] = Name[i];
            CurrentInitialsArrayPosition++;
            //printf("script is putting the character in position %i into the initials array\n", i);
         }

    }
    //printf("%i is the final array position\n", CurrentInitialsArrayPosition);
    for (int i = 0; i < CurrentInitialsArrayPosition; i++)
    {
        InitialsArray[i] = toupper(InitialsArray[i]);
        printf("%c", InitialsArray[i]);
    }
    printf("\n");
    return 0;
    
}