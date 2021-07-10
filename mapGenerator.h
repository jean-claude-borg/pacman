#pragma once

#include "globals.h"
#include <stdlib.h>

int getWallPositions();
int getVisibleWallPositions();
int getFoodPositions();
void getGhostStartPositions();

int loadMap()
{
    map = LoadImage("../assets/maps/map3-12.png");
    pixels = LoadImageColors(map);

    wallsX = (int*)malloc(map.width * map.height * sizeof (int));
    wallsY = (int*)malloc(map.width * map.height * sizeof (int));

    visibleWallsX = (int*)malloc(map.width * map.height * sizeof (int));
    visibleWallsY = (int*)malloc(map.width * map.height * sizeof (int));

    foodsX = (int*)malloc(map.width * map.height * sizeof (int));
    foodsY = (int*)malloc(map.width * map.height * sizeof (int));
    showFood = (bool*)malloc(map.width * map.height * sizeof (bool));

    ghostStartX = (int*)malloc(sizeof(int) * 4);
    ghostStartY = (int*)malloc(sizeof(int) * 4);

    int counter = getWallPositions();
    sizeOfFoodArray = getFoodPositions();
    sizeOfVisibleWallArray = getVisibleWallPositions();
    getGhostStartPositions();
    return counter;
};

void generateMapFromImage()
{
    for(int i = 0; i < sizeOfVisibleWallArray; i++)
        DrawRectangle(visibleWallsX[i], visibleWallsY[i], 1,1, DARKBLUE);

    // for(int i = 0; i < sizeOfWallArray; i++)
    //     DrawRectangle(wallsX[i], wallsY[i], 1,1, GREEN);

    for(int i = 0; i < sizeOfFoodArray; i++)
        if(showFood[i])
            DrawRectangle(foodsX[i], foodsY[i], 4, 4, WHITE);
};

int getVisibleWallPositions()
{
    int counter = 0;
    for(int i = 0; i < map.height; i++)
    {
        for(int j = 0; j < map.width; j++)
        {
             if(pixels[(i*map.width) + j].r == 25)
            {
                if(pixels[(i*map.width) + j].g == 29 || pixels[(i*map.width) + j].g == 30)
                {
                    if(pixels[(i*map.width) + j].b == 214)
                    {
                        visibleWallsX[counter] = j;
                        visibleWallsY[counter] = i;
                        counter++;
                    }
                }
            }
        }
    }
    visibleWallsX = (int *)realloc(visibleWallsX, sizeof(int) * counter);
    visibleWallsY = (int *)realloc(visibleWallsY, sizeof(int) * counter);

    return counter;
}

int getWallPositions()
{
    int counter = 0;
    int skip = pacWideRight.width;
    int skip2 = pacWideRight.width / 2;
    int skip4 = pacWideRight.width / 4;
    int skip8 = pacWideRight.width / 8;
    int skip12 = pacWideRight.width / 12;

    for(int i = 0; i < map.height; i++)
    {
        for(int j = 0; j < map.width; j++)
        {
            //vertical optimisation
            if(pixels[((i+1)*map.width) + j].b == 214 || pixels[((i+1)*map.width) + j].b == 5)
                if(pixels[((i-1)*map.width) + j].b == 214 || pixels[((i-1)*map.width) + j].b == 5)
                    if(i%2 == 0 || i%3 == 0 || i%5 == 0 || i%7 == 0 || i%11 == 0 || i%13 == 0 || i%17 == 0 || i%19 == 0 || i%23 == 0 || i%29 == 0)
                        continue;
                        
            //detect walls
            if(pixels[(i*map.width) + j].r == 25 || pixels[(i*map.width) + j].r == 91)
            {
                if(pixels[(i*map.width) + j].g == 29 || pixels[(i*map.width) + j].g == 238 || pixels[(i*map.width) + j].g == 30)
                {
                    if(pixels[(i*map.width) + j].b == 214 || pixels[(i*map.width) + j].b == 5)
                    {
                        //Add wall to wall array
                        wallsX[counter] = j;
                        wallsY[counter] = i;
                        counter++;
                        //horizontal optimisation
                        if(pixels[(i*map.width) + j + skip].b == 214 || pixels[(i*map.width) + j + skip].b == 5)    j+=skip - 1;
                        else if(pixels[(i*map.width) + j + skip2].b == 214 || pixels[(i*map.width) + j + skip2].b == 5)    j+=skip2 - 1;
                        else if(pixels[(i*map.width) + j + skip4].b == 214 || pixels[(i*map.width) + j + skip4].b == 5)    j+=skip4 - 1;
                        else if(pixels[(i*map.width) + j + skip8].b == 214 || pixels[(i*map.width) + j + skip8].b == 5)    j+=skip8 - 1;
                        else if(pixels[(i*map.width) + j + skip12].b == 214 || pixels[(i*map.width) + j + skip12].b == 5)    j+=skip12 - 1;
                    }
                }
            }
        }
    }
    wallsX = (int *)realloc(wallsX, sizeof(int) * counter);
    wallsY = (int *)realloc(wallsY, sizeof(int) * counter);

    return counter;
}

void getGhostStartPositions()
{
    int counter = 0;
    bool foundWall = false;

    for(int i = 0; i < map.height; i++)
    {
        for(int j = 0; j < map.width; j++)
        {
            //ghosts
            if(pixels[(i*map.width) + j].r == 146)
            {
                if(pixels[(i*map.width) + j].g == 30)
                {
                    if(pixels[(i*map.width) + j].b == 64)
                    {
                        ghostStartX[counter] = j;
                        ghostStartY[counter] = i;
                        counter++;
                    }
                }
            }
            //ghostWalls
            if(pixels[(i*map.width) + j].r == 183 && foundWall == false)
            {
                if(pixels[(i*map.width) + j].g == 144)
                {
                    if(pixels[(i*map.width) + j].b == 156)
                    {
                        ghostWallX = j;
                        ghostWallY = i;
                        foundWall = true;
                    }
                }
            }
        }
    }
}

int getFoodPositions()
{
    int counter = 0;

    for(int i = 0; i < map.height; i++)
    {
        for(int j = 0; j < map.width; j++)
        {
            if(pixels[(i*map.width) + j].r == 155)
            {
                if(pixels[(i*map.width) + j].g == 151)
                {
                    if(pixels[(i*map.width) + j].b == 0)
                    {
                        foodsX[counter] = j;
                        foodsY[counter] = i;
                        showFood[counter] = true;
                        counter++;

                        j+=4;
                    }
                }
            }
        }
        i+=3;
    }
    foodsX = (int *)realloc(foodsX, sizeof(int) * counter);
    foodsY = (int *)realloc(foodsY, sizeof(int) * counter);
    showFood = (bool *)realloc(showFood, sizeof(bool) * counter);

    return counter;
};