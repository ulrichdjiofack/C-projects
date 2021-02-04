/*C program to count the occurrences of all the distinct words in a file.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

struct wordss{
    int count;
    char words[50];
};

int main(){

    struct wordss *ptr;
    int max;

    FILE *fp1, *fp2;
    int i, j, temp, length, Distinct;
    char ch[50];
    int index = 0;


    printf("Enter a number greater than the number of words in the file else program crashes\n");
    scanf("%d", &max);
    printf("Scanning file...");

    ptr = (struct wordss*)malloc( max * sizeof(struct wordss));
    if (ptr == NULL)
    {
       printf("File was not opened\n");
       printf("Verify the path and try again\n");
       getchar();
       exit(EXIT_FAILURE);
    }

    //array of words
    char word[50];

    /*opening file*/
    fp1 = fopen("complete-shakespeare.txt", "r");
    fp2 = fopen("FE19A021_asgn_1.txt", "w");

    /*checking if the file was opened*/
    if (fp1 == NULL || fp2 == NULL)
    {
       printf("File was not opened\n");
       printf("Verify the path and try again\n");
       getchar();
       exit(EXIT_FAILURE);
    }

    for ( i = 0; i < max; i++)
    {
        (ptr + i)->count=0;
    }

    while (fscanf(fp1, "%s", word) != EOF)
    {
        /* convert word to lowercase */
        strlwr(word);

        //removin punctuation character
        length = strlen(word);
        if (ispunct(word[length - 1]))
        {
            word[length - 1] = '\0';
        }
        if (ispunct(word[0]))
        {
            word[0] = '\0';
        }

        //check if word exist in array of words
        Distinct = 1;
        for ( i = 0; i < index && Distinct; i++)
        {
            /*if strings are equal*/
            if (strcmp((ptr + i)->words, word) == 0)
            {
                Distinct = 0;
            }

        }
        //if distinct, add word to array of words
        //increment index
        //else increment occurrence by incrementing count of word
        if (Distinct)
        {
            memcpy((ptr + index)->words, word, sizeof(word));
            (ptr + index)->count++;

            index++;//for new word to be read
        }
        else
        {
            (ptr + (i-1))->count++;
        }

    }
    fclose(fp1);
    printf("\nRead succesful, press any key to display the occurrences");
    getchar();

   //print all words
    system("cls");
    printf("\nOccurrences of all distinct words in the file\n");
    printf("\n");
    printf("Printing content to output.txt file...");

    for ( i = 0; i < index; i++)
    {
        //sorting the occurrence from highest to least
        for ( j = i+1 ; j < index; j++)
        {
            // swaping position from highest to least
            if ((ptr + i)->count < (ptr + j)->count)
            {
                temp = (ptr + i)->count;//holds count temporarily
                strcpy(ch, (ptr + i)->words);//ch holds words temporarily
                (ptr + i)->count = (ptr + j)->count;
                strcpy((ptr + i)->words, (ptr + j)->words);
                (ptr + j)->count = temp;
                strcpy((ptr + j)->words, ch);
            }

        }
    }

    fprintf(fp2, "\nS/N \t WORD \t\t FREQUENCY\n");

    for ( i = 0; i < index; i++)
    {
        //%-10s print string in 10 character width and left justified
        //%d makes number printed right justified
        fprintf(fp2, "\n%d \t %-10s \t %d \n", i+1, (ptr + i)->words, (ptr + i)->count);
    }
    printf("\nPrinting content to file successful\n");
    printf("\n");
    printf("Press any key to exit\n");

getchar();
return 0;
}
