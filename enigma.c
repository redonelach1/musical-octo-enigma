#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    int i=0, j=0;
    // checks for arguments count
    if ( argc!=2)
    {
                // Returns 1 , and prints Error msg when not true
        printf("ERROR (ARGS)\n");
        return 1;
    }
    if (argv[argc-1][26]!='\0')
    {
                // Returns 1 , and prints Error msg when not true
        printf("ERROR\n");
        return 1;
    }
    for(i=0;;i++)
    {
        if(argv[argc-1][i] == '\0')
        {
            // when end of string break the loop.
            break;
        }
        if (!isalpha(argv[argc-1][i]))
        {
            // checks every single character if its alphabetic.
            printf("ERROR (NONALPHA)\n");
            return 1;
            break;
        }
        for (j=0;;j++)
        {
            if (argv[argc-1][j] == argv[argc-1][i])
            {
                if(j==i)
                {
                    // exclude the case when comparing array element with itself.
                    continue;
                }
                // compare array item with other items to see if any is repeated.
                printf("%c = %c",argv[argc-1][i],argv[argc-1][j]);
                printf("ERROR (NOT ONCE)\n");
                return 1;
                break;
            }
            else if (argv[argc-1][j] == '\0')
            {
                //stops the loop when end of string reached
                break;
            }
        }
    }
    //alphabets string
    string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // gets a string from user
    string plaintext = get_string("plaintext:");
    // string length
    int len = strlen(plaintext);
    // array to hold ciphertext
    char ciphertext[len];
    // reset i and j values to 0.
    i=0;
    j=0;
    while (plaintext[i] != '\0')
    {
            // if element isnt alphabetic we keep it.
            if (isalpha(plaintext[i]) == 0)
            {
                ciphertext[i] = plaintext[i];
            }
            //otherwise we replace it with its equivalent in the given key.
        for(j=0;j<=25;j++)
        {
            if (tolower(plaintext[i]) == tolower(alphabets[j]) )
            {
                //save element start (upper to upper / lower to lower)
                if (isupper(plaintext[i]))
                {
                ciphertext[i] = toupper(argv[argc-1][j]);
                }
                else
                {
                    ciphertext[i] = tolower(argv[argc-1][j]);
                }
                break;
            }
        }
    i++;
    }
    //finally prints the result.
    printf("ciphertext: %s",ciphertext);
    printf("\n");
    return 0;
    //and this comment is to reach the 100th line.
}