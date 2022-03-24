#pragma once

#ifdef _WIN32
//#include <Windows.h>
#else
//#include <unistd.h>
#endif

#include "globals.h"
#include "stdio.h"
#include "ai.h"

enum eDirection bufferDir;
bool getGhostCollision();
bool atePowerUp(int x, int y);
void onPacCollision();
void resetGame();

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

void getInput()
{
    if(!allowUserInput)
        return;

    if(IsKeyPressed(KEY_P))
        paused = !paused;

    if(IsKeyPressed(KEY_R))
        resetGame();

    if(IsKeyPressed(KEY_SPACE))
        playStartScene = true;

        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        bufferDir = RIGHT;
    else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
        bufferDir = LEFT;
    else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        bufferDir = UP;
    else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
        bufferDir = DOWN;

    if (bufferDir == RIGHT && !getCollision(pacX+1, pacY) && !getCollision(pacX+2, pacY) && !getCollision(pacX+3, pacY))
        dir = RIGHT;
    else if (bufferDir == LEFT && !getCollision(pacX-1, pacY) && !getCollision(pacX-2, pacY) && !getCollision(pacX-3, pacY))
        dir = LEFT;
    else if (bufferDir == UP && !getCollision(pacX, pacY-1) && !getCollision(pacX, pacY-2) && !getCollision(pacX, pacY-3))
        dir = UP;
    else if (bufferDir == DOWN && !getCollision(pacX, pacY+1) && !getCollision(pacX, pacY+2) && !getCollision(pacX, pacY+3))
        dir = DOWN;
};

void updateLogic(int *x, int *y)
{
    if(startMenu)
        return;

    //i dont know why this works only when function is called twice
    getInput();
    getInput();

    if(dead)
    {
        dir = STOP;
        return;
    }

    if     (dir == LEFT)    *x-=3;
    else if(dir == RIGHT)   *x+=3;
    else if(dir == UP)      *y-=3;
    else if(dir == DOWN)    *y+=3;

    if(getCollision(*x,*y) && dir == LEFT)
    {
        while(getCollision(*x,*y))
            *x+=1;
        dir = STOP;
    }
    if(getCollision(*x,*y) && dir == RIGHT)
    {
        while(getCollision(*x,*y))
            *x-=1;
        dir = STOP;
    }
    if(getCollision(*x,*y) && dir == UP)
    {
        while(getCollision(*x,*y))
            *y+=1;
        dir = STOP;
    }
    if(getCollision(*x,*y) && dir == DOWN)
    {
        while(getCollision(*x,*y))
            *y-=1;
        dir = STOP;
    }

    if(pacX <= 7) pacX = 454;
    else if(pacX >= 454) pacX = 7;

    if(ateFood(*x, *y, sizeOfFoodArray)) score++;

    if(atePowerUp(pacX, pacY))
        poweredUp = true;

    if(poweredUp == true)
        poweredUpDuration++;

    updateAi();
    getGhostCollision();

    //blinky eaten while vulnerable
    static int powerEatMaxTime = 50;
    static int powerEatAnimCounter = 0;
    if(blinkyDead)
    {
        if(!showedPoints)
        {
            DrawText("200", pacX + 5, pacY + pacHeight/2, 15, WHITE);
            updateAiMovement = false;
            allowUserInput = false;
            showBlinky = false;
            powerEatAnimCounter++;
        }
        if(powerEatAnimCounter >= powerEatMaxTime)
        {
              showBlinky = true;
              updateAiMovement = true;
              allowUserInput = true;

              drawPac = true;
              powerEatAnimCounter = 0;
              showedPoints = true;
        }
    }
};

bool getGhostCollision()
{
    //colliion when powered up
    Rectangle pacHitBox = {pacX, pacY, pacWidth, pacHeight};
    Rectangle blinkyHitBox = {blinkyX, blinkyY, blinkyWidth * 0.5, blinkyHeight * 0.5};
    Rectangle clydeHitBox = {clydeX, clydeY, clydeWidth * 0.5, clydeHeight * 0.5};
    Rectangle inkyHitBox = {inkyX, inkyY, inkyWidth * 0.5, inkyHeight * 0.5};
    Rectangle pinkyHitBox = {pinkyX, pinkyY, pinkyWidth * 0.5, pinkyHeight * 0.5};

    if(CheckCollisionRecs(pacHitBox, blinkyHitBox) && poweredUp == true && !blinkyDead)
    {
        //blinkyX = ghostStartX[0]; blinkyY = ghostStartY[0]; blinkyCrossedWall = false;
        showBlinky = true;
        updateAiMovement = true;

        dir = STOP;
        bufferDir = STOP;
        drawPac = false;

        blinkyDead = true;
        showedPoints = false;
        score+=200;
    }
    if(CheckCollisionRecs(pacHitBox, clydeHitBox) && poweredUp == true)
    {
        clydeX = ghostStartX[1]; clydeY = ghostStartY[1]; clydeCrossedWall = false;
        clydeEaten = true;
        score+=25;
    }
    if(CheckCollisionRecs(pacHitBox, inkyHitBox) && poweredUp == true)
    {
        inkyX = ghostStartX[2]; inkyY = ghostStartY[2]; inkyCrossedWall = false;
        inkyEaten = true;
        score+=25;
    }
    if(CheckCollisionRecs(pacHitBox, pinkyHitBox) && poweredUp == true)
    {
        pinkyX = ghostStartX[3]; pinkyY = ghostStartY[3]; pinkyCrossedWall = false;
        pinkyEaten = true;
        score+=25;
   }

    //collision when not powered up, different implementation of collision used(circle hitboxes)
    int distXBlinky = abs(pacX - blinkyX);
    int distYBlinky = abs(pacY - blinkyY);

    int distXClyde = abs(pacX - clydeX);
    int distYClyde = abs(pacY - clydeY);

    int distXInky = abs(pacX - inkyX);
    int distYInky = abs(pacY - inkyY);

    int distXPinky = abs(pacX - pinkyX);
    int distYPinky = abs(pacY - pinkyY);

    int collisionDist = 25;

    if(distXBlinky < collisionDist && distYBlinky < collisionDist && poweredUp == false) {
        collided = true;
        onPacCollision();
    }
    if(distXClyde < collisionDist && distYClyde < collisionDist && poweredUp == false) {
        collided = true;
        onPacCollision();
    }
    if(distXInky < collisionDist && distYInky < collisionDist && poweredUp == false) {
        collided = true;
        onPacCollision();
    }
    if(distXPinky < collisionDist && distYPinky < collisionDist && poweredUp == false) {
        collided = true;
        onPacCollision();
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
                poweredUpDuration = 0;
                return true;
            }
        }
    }
    return false;
}

void resetGhostPositions()
{
    blinkyX = ghostStartX[0];
    blinkyY = ghostStartY[0];
    blinkyCrossedWall = false;

    clydeX = ghostStartX[1];
    clydeY = ghostStartY[1];
    clydeCrossedWall = false;

    inkyX = ghostStartX[2];
    inkyY = ghostStartY[2];
    inkyCrossedWall = false;

    pinkyX = ghostStartX[3];
    pinkyY = ghostStartY[3];
    pinkyCrossedWall = false;
}

void onPacCollision()
{
    //usleep(1500000);
    dir = STOP;
    dead = true;
    lives--;
}

void resetGame()
{
    for(int i = 0; i < sizeOfFoodArray; i++)
        showFood[i] = true;

    for(int i = 0; i < numPowerups; i++)
        showPowerUp[i] = true;

    resetGhostPositions();
    dead = false;
    deathFrameCounter = 0;
    blinkyWait = 100;
    clydeWait = 400;
    inkyWait = 800;
    pinkyWait = 1200;

    lives = 3;
    score = 0;
    pacX = 210;
    pacY = 265;
    dir = STOP;
    bufferDir = STOP;
}

