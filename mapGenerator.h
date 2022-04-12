#pragma once

#include "globals.h"
#include <stdlib.h>
#include <stdio.h>

int getWallPositions();
int getVisibleWallPositions();
int getFoodPositions();
void getGhostStartPositions();
int getPowerUpPositions();

int loadMap()
{
    map = LoadImage("../assets/maps/map4-8.png");
    windowWidth = map.width;
    windowHeight = map.height;
    pixels = LoadImageColors(map);

    wallsX = (int*)malloc(map.width * map.height * sizeof (int));
    wallsY = (int*)malloc(map.width * map.height * sizeof (int));

    visibleWallsX = (int*)malloc(map.width * map.height * sizeof (int));
    visibleWallsY = (int*)malloc(map.width * map.height * sizeof (int));

    foodsX = (int*)malloc(map.width * map.height * sizeof (int));
    foodsY = (int*)malloc(map.width * map.height * sizeof (int));
    showFood = (bool*)malloc(map.width * map.height * sizeof (bool));
    
    powerUpX = (int*)malloc(map.width * map.height * sizeof (int));
    powerUpY = (int*)malloc(map.width * map.height * sizeof (int));
    showPowerUp = (bool*)malloc(map.width * map.height * sizeof (bool));

    ghostStartX = (int*)malloc(sizeof(int) * 4);
    ghostStartY = (int*)malloc(sizeof(int) * 4);

    int counter = getWallPositions();
    sizeOfFoodArray = getFoodPositions();
    sizeOfVisibleWallArray = getVisibleWallPositions();
    numPowerups = getPowerUpPositions();
    getGhostStartPositions();
    return counter;
};

int getVisibleWallPositions()
{
    int counter = 0;
    for(int i = 0; i < map.height; i++)
    {
        for(int j = 0; j < map.width; j++)
        {
             if(pixels[(i*map.width) + j].r == 24 || pixels[(i*map.width) + j].r == 158)
            {
                if(pixels[(i*map.width) + j].g == 29 || pixels[(i*map.width) + j].g == 66)
                {
                    if(pixels[(i*map.width) + j].b == 215 || pixels[(i*map.width) + j].b == 137)
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
            if(pixels[((i+1)*map.width) + j].b == 215 || pixels[((i+1)*map.width) + j].b == 5)
                if(pixels[((i-1)*map.width) + j].b == 215 || pixels[((i-1)*map.width) + j].b == 5)
                    if(i%2 == 0 || i%3 == 0 || i%5 == 0 || i%7 == 0 || i%11 == 0 || i%13 == 0 || i%17 == 0 || i%19 == 0 || i%23 == 0 || i%29 == 0)
                        continue;
                        
            //detect walls
            if(pixels[(i*map.width) + j].r == 24 || pixels[(i*map.width) + j].r == 91 || pixels[(i*map.width) + j].r == 90)
            {
                if(pixels[(i*map.width) + j].g == 29 || pixels[(i*map.width) + j].g == 238 || pixels[(i*map.width) + j].g == 30)
                {
                    if(pixels[(i*map.width) + j].b == 215 || pixels[(i*map.width) + j].b == 5)
                    {
                        //Add wall to wall array
                        wallsX[counter] = j;
                        wallsY[counter] = i;
                        counter++;
                        //horizontal optimisation
                        if(pixels[(i*map.width) + j + skip].b == 215 || pixels[(i*map.width) + j + skip].b == 5)    j+=skip - 1;
                        else if(pixels[(i*map.width) + j + skip2].b == 215 || pixels[(i*map.width) + j + skip2].b == 5)    j+=skip2 - 1;
                        else if(pixels[(i*map.width) + j + skip4].b == 215 || pixels[(i*map.width) + j + skip4].b == 5)    j+=skip4 - 1;
                        else if(pixels[(i*map.width) + j + skip8].b == 215 || pixels[(i*map.width) + j + skip8].b == 5)    j+=skip8 - 1;
                        else if(pixels[(i*map.width) + j + skip12].b == 215 || pixels[(i*map.width) + j + skip12].b == 5)    j+=skip12 - 1;
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

int getPowerUpPositions()
{
    int counter = 0;

    for(int i = 0; i < map.height; i++)
    {
        for(int j = 0; j < map.width; j++)
        {
            if(pixels[(i*map.width) + j].r == 235)
            {
                if(pixels[(i*map.width) + j].g == 22)
                {
                    if(pixels[(i*map.width) + j].b == 18)
                    {
                        powerUpX[counter] = j;
                        powerUpY[counter] = i;
                        showPowerUp[counter] = true;
                        counter++;

                        j+=4;
                    }
                }
            }
        }
        i+=3;
    }
    powerUpX = (int *)realloc(powerUpX, sizeof(int) * counter);
    powerUpY = (int *)realloc(powerUpY, sizeof(int) * counter);
    showPowerUp = (bool *)realloc(showPowerUp, sizeof(bool) * counter);

    return counter;
};