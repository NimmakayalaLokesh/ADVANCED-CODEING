#include <stdio.h>
#include <string.h>

int main()
{
    char s[20];
    int i;
    
    //Enter the string
    printf("Enter the string: ");
    scanf("%s", s);
    
    //Loop to check for duplicate characters
    for(i = 0; i < strlen(s); i++)
    {
        if(s[i] == s[i+1])
        {
            //Replace the duplicate characters with a null character
            s[i] = '\0';
            s[i+1] = '\0';
            i++;
        }
    }
    
    //Print the string after removing duplicates
    printf("String after removing duplicates: %s", s);
    
    return 0;
}

