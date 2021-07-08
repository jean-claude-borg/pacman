#pragma once

#include "globals.h"
#include "stdio.h"

enum eDirection bufferDir;
bool getGhostCollision(int x, int y);

bool getCollision(int x, int y)
{
    for(int i = 0; i < sizeOfWallArray; i++)
    {
        if((wallsX[i] >= x && wallsX[i] < x + pacWideRight.width) && (wallsY[i] >= y && wallsY[i] < y + pacWideRight.height))
            return true;
    }
    return false;
};

bool ateFood(int x, int y, int sizeOfFoodArray)
{
    for(int i = 0; i < sizeOfFoodArray; i++)
    {
        if((foodsX[i] >= x && foodsX[i] < x + pacWideRight.width) && (foodsY[i] >= y && foodsY[i] < y + pacWideRight.height) && showFood[i])
            {showFood[i] = false; return true;}
    }
    return false;
}

void getInput(int sizeOfWallArray)
{    
    if (IsKeyDown(KEY_RIGHT))
        bufferDir = RIGHT;
    else if (IsKeyDown(KEY_LEFT))
        bufferDir = LEFT;
    else if (IsKeyDown(KEY_UP))
        bufferDir = UP;
    else if (IsKeyDown(KEY_DOWN))
        bufferDir = DOWN;

    if (bufferDir == RIGHT && !getCollision(pacX+1, pacY) && !getCollision(pacX+2, pacY) && !getCollision(pacX+3, pacY) && !getCollision(pacX+4, pacY))
        dir = RIGHT;
    else if (bufferDir == LEFT && !getCollision(pacX-1, pacY) && !getCollision(pacX-2, pacY) && !getCollision(pacX-3, pacY) && !getCollision(pacX-4, pacY))
        dir = LEFT;
    else if (bufferDir == UP && !getCollision(pacX, pacY-1) && !getCollision(pacX, pacY-2) && !getCollision(pacX, pacY-3) && !getCollision(pacX, pacY-4))
        dir = UP;
    else if (bufferDir == DOWN && !getCollision(pacX, pacY+1) && !getCollision(pacX, pacY+2) && !getCollision(pacX, pacY+3) && !getCollision(pacX, pacY+4))
        dir = DOWN;
};

void updateLogic(int *x, int *y)
{
    getInput(sizeOfWallArray);

    if     (dir == LEFT)    *x-=1;
    else if(dir == RIGHT)   *x+=1;
    else if(dir == UP)      *y-=1;
    else if(dir == DOWN)    *y+=1;

    if(getCollision(*x,*y) && dir == LEFT)    *x+=1;
    if(getCollision(*x,*y) && dir == RIGHT)   *x-=1;

    if(getCollision(*x,*y) && dir == UP)      *y+=1;
    if(getCollision(*x,*y) && dir == DOWN)    *y-=1;

    getInput(sizeOfWallArray);

    if     (dir == LEFT)    *x-=1;
    else if(dir == RIGHT)   *x+=1;
    else if(dir == UP)      *y-=1;
    else if(dir == DOWN)    *y+=1;

    if(getCollision(*x,*y) && dir == LEFT)    *x+=1;
    if(getCollision(*x,*y) && dir == RIGHT)   *x-=1;

    if(getCollision(*x,*y) && dir == UP)      *y+=1;
    if(getCollision(*x,*y) && dir == DOWN)    *y-=1;

    getInput(sizeOfWallArray);

    if     (dir == LEFT)    *x-=1;
    else if(dir == RIGHT)   *x+=1;
    else if(dir == UP)      *y-=1;
    else if(dir == DOWN)    *y+=1;

    if(getCollision(*x,*y) && dir == LEFT)    *x+=1;
    if(getCollision(*x,*y) && dir == RIGHT)   *x-=1;

    if(getCollision(*x,*y) && dir == UP)      *y+=1;
    if(getCollision(*x,*y) && dir == DOWN)    *y-=1;

    if(pacX <= 7) pacX = 454;
    else if(pacX >= 454) pacX = 7;

    if(ateFood(*x, *y, sizeOfFoodArray)) score++;
    printf("Score: %d\n", score);

    if(getGhostCollision(pacX, pacY))
        CloseWindow();
}; 

bool getGhostCollision(int x, int y)
{
    // if((x >= blinkyX && x + pacWideRight.width < blinkyX + blinkyWidth) &&
    //    (y >= blinkyY && y + pacWideRight.height < blinkyY + blinkyHeight))
    //    return true;
    
    // return false;
}
