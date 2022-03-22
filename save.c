#include "save.h"
#include "stdio.h"
#include "stdlib.h"

void saveScoreToFile(int score)
{
    FILE *filePointer;
    filePointer = fopen("../save/save.txt", "w");

    if(filePointer == NULL)
    {
        printf("\nError while opening save file\n");
        exit(1);
    }
    //fwrite(&score, sizeof(int) , 1, filePointer);
    fprintf(filePointer, "%d", score);
};

void getHighScoreFromFile(int *score1)
{
    FILE *filePointer;
    filePointer = fopen("../save/save.txt", "w");
    int tempScore;

    fscanf("%d", &tempScore);
    *score1 = tempScore;

}