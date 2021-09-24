#pragma once

#include "globals.h"
#include "stdio.h"

enum eDirection bufferDir;
bool getGhostCollision();
bool atePowerUp(int x, int y);

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
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        bufferDir = RIGHT;
    else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
        bufferDir = LEFT;
    else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        bufferDir = UP;
    else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
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
    //printf("Score: %d\n", score);

    if(atePowerUp(pacX, pacY))
        poweredUp = true;

    if(poweredUp == true)
        poweredUpDuration++;

    getGhostCollision();
}; 

bool getGhostCollision()
{
    Rectangle pacHitBox = {pacX, pacY, pacWidth, pacHeight};
    Rectangle blinkyHitBox = {blinkyX, blinkyY, blinkyWidth * 0.5, blinkyHeight * 0.5};
    Rectangle clydeHitBox = {clydeX, clydeY, clydeWidth * 0.5, clydeHeight * 0.5};
    Rectangle inkyHitBox = {inkyX, inkyY, inkyWidth * 0.5, inkyHeight * 0.5};
    Rectangle pinkyHitBox = {pinkyX, pinkyY, pinkyWidth * 0.5, pinkyHeight * 0.5};

    if(CheckCollisionRecs(pacHitBox, blinkyHitBox) && poweredUp == true)
    {
        blinkyX = ghostStartX[0]; blinkyY = ghostStartY[0]; blinkyCrossedWall = false;
    }
    if(CheckCollisionRecs(pacHitBox, clydeHitBox) && poweredUp == true)
    {
        clydeX = ghostStartX[1]; clydeY = ghostStartY[1]; clydeCrossedWall = false;
    }
    if(CheckCollisionRecs(pacHitBox, inkyHitBox) && poweredUp == true)
    {
        inkyX = ghostStartX[2]; inkyY = ghostStartY[2]; inkyCrossedWall = false;
    }
    if(CheckCollisionRecs(pacHitBox, pinkyHitBox) && poweredUp == true)
    {
        pinkyX = ghostStartX[3]; pinkyY = ghostStartY[3]; pinkyCrossedWall = false;
    }
}

bool atePowerUp(int pacX, int pacY)
{
    for(int i = 0; i < numPowerups; i++)
    {
        if(powerUpX[i] >= pacX && powerUpX[i] <= pacX + pacWideLeft.width && powerUpY[i] >= pacY && powerUpY[i] <= pacY + pacWideLeft.height)
        {
            if(showPowerUp[i])
            {
                showPowerUp[i] = false;
                return true;
            }
        }
    }
    return false;
}
