#include "save.h"
#include "stdio.h"
#include "stdlib.h"

void saveScoreToFile(int score, int highScore)
{
    FILE *filePointer;

    if(score > highScore)
    {
        filePointer = fopen("../save/save.txt", "w");

        if(filePointer == NULL)
        {
            printf("\nError while opening save file\n");
            exit(1);
        }

        fprintf(filePointer, "%d", score);
    }
    fclose(filePointer);
};

void getHighScoreFromFile(int *highScore)
{
    FILE *filePointer;
    filePointer = fopen("../save/save.txt", "r");
    if(filePointer == NULL)
    {
        printf("\nError while opening save file\n");
        exit(1);
    }
    fscanf(filePointer, "%d", highScore);
    fclose(filePointer);
}