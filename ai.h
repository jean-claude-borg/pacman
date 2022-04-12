#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
#pragma once
#include "globals.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

bool ghostsGetCollision(int x, int y);
void blinkyChaseState();
void clydeChaseState();
void inkyChaseState();
void pinkyChaseState();
void blinkyRunState();
void clydeRunState();
void inkyRunState();
void pinkyRunState();
void blinkyEyesState();
void clydeEyesState();
void inkyEyesState();
void pinkyEyesState();

static int blinkyUpdateLimit = 0;
static int clydeUpdateLimit = 0;
static int inkyUpdateLimit = 0;
static int pinkyUpdateLimit = 0;

int ghostSpeed = 1;
int ghostUpdatesPerFrame = 1;
//eyes total updates = ghpstUpdatesPerFrame * eyesUpdatesPerFrame
int eyesUpdatesPerFrame = 2;

void initAi()
{    
    blinkyX = ghostStartX[0];
    blinkyY = ghostStartY[0];

    clydeX = ghostStartX[1];
    clydeY = ghostStartY[1];

    inkyX = ghostStartX[2];
    inkyY = ghostStartY[2];

    pinkyX = ghostStartX[3];
    pinkyY = ghostStartY[3];

    blinkyDir = STOP;
    clydeDir = STOP;
    inkyDir = STOP;
    pinkyDir = STOP;
};

bool atCrossRoad(int x, int y)
{
    int dirCounter = 0;

    if(!ghostsGetCollision(x-1, y) && !ghostsGetCollision(x-2, y) && !ghostsGetCollision(x-3, y) && !ghostsGetCollision(x-4, y) && !ghostsGetCollision(x-5, y) && !ghostsGetCollision(x-6, y) && !ghostsGetCollision(x-7, y))
        dirCounter++;

    if(!ghostsGetCollision(x+1, y) && !ghostsGetCollision(x+2, y) && !ghostsGetCollision(x+3, y) && !ghostsGetCollision(x+4, y) && !ghostsGetCollision(x+5, y) && !ghostsGetCollision(x+6, y) && !ghostsGetCollision(x+7, y))
        dirCounter++;

    if(!ghostsGetCollision(x, y-1) && !ghostsGetCollision(x, y-2) && !ghostsGetCollision(x, y-3) && !ghostsGetCollision(x, y-4) && !ghostsGetCollision(x, y-5) && !ghostsGetCollision(x, y-6) && !ghostsGetCollision(x, y-7))
        dirCounter++;
    
    if(!ghostsGetCollision(x, y+1) && !ghostsGetCollision(x, y+2) && !ghostsGetCollision(x, y+3) && !ghostsGetCollision(x, y+4) && !ghostsGetCollision(x, y+5) && !ghostsGetCollision(x, y+6) && !ghostsGetCollision(x, y+7))
        dirCounter++;

    if(dirCounter >= 3)
        return true;
    return false;
};

bool closerToPac(int oldX, int oldY, int newX, int newY)
{
    if((abs(pacX - oldX) > abs(pacX - newX)) || (abs(pacY - oldY) > abs(pacY - newY)))
        {
            return true;
        }

    return false;
}

bool closerToSpawn(int oldX, int oldY, int newX, int newY)
{
    if((abs(ghostStartX[0] - oldX) > abs(ghostStartX[0] - newX)) || (abs(ghostStartY[0] - oldY) > abs(ghostStartY[0] - newY)))
    {
        return true;
    }

    return false;
}

void aiCalcDir()
{
    //blinky
    if(blinkyY <= ghostWallY - 33)   {blinkyCrossedWall = true;} 
    if(!blinkyCrossedWall)
    {
        if(blinkyWait <=0)
            blinkyDir = UP;
        else if(blinkyWait > 0)
        {
            blinkyWait --;
            blinkyDir = STOP;
        }
    }
    if(blinkyDead) {
     for(int i = 0; i < eyesUpdatesPerFrame; i++)
         blinkyEyesState();
    }
    else if(!poweredUp)
        blinkyChaseState();
    else if(poweredUp)
        blinkyRunState();

    //clyde
    if(clydeY <= ghostWallY - 33)   {clydeCrossedWall = true;}
    if(!clydeCrossedWall)
    {
        if(clydeWait <=0)
        {
            if(clydeX < ghostStartX[2])
                clydeDir = RIGHT;
            else
                clydeDir = UP;
        }
        else if(clydeWait > 0)
        {
            clydeWait --;
            clydeDir = STOP;
        }
    }
    if(clydeDead) {
     for(int i = 0; i < eyesUpdatesPerFrame; i++)
         clydeEyesState();
    }
    else if(!poweredUp)
        clydeChaseState();
    else if(poweredUp)
        clydeRunState();

    //inky
    if(inkyY <= ghostWallY - 33)   {inkyCrossedWall = true;}
    if(!inkyCrossedWall)
    {
        if(inkyWait <=0)
            inkyDir = UP;
        else if(inkyWait > 0)
        {
            inkyWait --;
            inkyDir = STOP;
        }
    }
    if(inkyDead) {
     for(int i = 0; i < eyesUpdatesPerFrame; i++)
         inkyEyesState();
    }
    else if(!poweredUp)
        inkyChaseState();
    else if(poweredUp)
        inkyRunState();

    //pinky
    if(pinkyY <= ghostWallY - 33)   {pinkyCrossedWall = true;}
    if(!pinkyCrossedWall)
    {
        if(pinkyWait <=0) {
            if(pinkyX > ghostStartX[2])
                pinkyDir = LEFT;
            else
                pinkyDir = UP;
        }
        else if(pinkyWait > 0)
        {
            pinkyWait --;
            pinkyDir = STOP;
        }
    }
    if(pinkyDead) {
     for(int i = 0; i < eyesUpdatesPerFrame; i++)
         pinkyEyesState();
    }
    else if(!poweredUp)
        pinkyChaseState();
    else if(poweredUp)
        pinkyRunState();
};

void updateBlinky()
{
    if(blinkyCrossedWall == false){aiCalcDir();}

    if(blinkyCrossedWall == false)
    {
//        if(blinkyDir == LEFT      ) blinkyX -= 1;
//        else if(blinkyDir == RIGHT) blinkyX += 1;
        if(blinkyDir == UP   ) blinkyY -= 1;
      //  else if(blinkyDir == DOWN ) blinkyY += 1;
    }
    if(blinkyCrossedWall)
    {
        blinkyUpdateLimit++;
        if(blinkyX < 9) blinkyX = 440;
        else if(blinkyX >= 450) blinkyX = 15;

        if     (blinkyDir == LEFT ) blinkyX -= ghostSpeed;
        else if(blinkyDir == RIGHT) blinkyX += ghostSpeed;
        else if(blinkyDir == UP   ) blinkyY -= ghostSpeed;
        else if(blinkyDir == DOWN ) blinkyY += ghostSpeed;
        //iteration1
        if(atCrossRoad(blinkyX, blinkyY)) {aiCalcDir();}
        else if(blinkyDir == LEFT && ghostsGetCollision(blinkyX - 1,blinkyY)) {aiCalcDir();}
        else if(blinkyDir == RIGHT && ghostsGetCollision(blinkyX + 1,blinkyY)) {aiCalcDir();}
        else if(blinkyDir == UP && ghostsGetCollision(blinkyX,blinkyY - 1)) {aiCalcDir();}
        else if(blinkyDir == DOWN && ghostsGetCollision(blinkyX,blinkyY + 1)) {aiCalcDir();}
    }
};

void updateClyde()
{
    if(clydeCrossedWall == false){aiCalcDir();}

    if(clydeCrossedWall == false)
    {
//        if(clydeDir == LEFT      ) clydeX -= 1;
        if(clydeDir == RIGHT) clydeX += ghostSpeed;
        else if(clydeDir == UP   ) clydeY -= ghostSpeed;
       // else if(clydeDir == DOWN ) clydeY += 1;
    }
    if(clydeCrossedWall)
    {
        clydeUpdateLimit++;
        if(clydeX < 9) clydeX = 440;
        else if(clydeX >= 450) clydeX = 15;
        //iteration1
        if(atCrossRoad(clydeX, clydeY)) {aiCalcDir();}
        else if(clydeDir == LEFT && ghostsGetCollision(clydeX - ghostSpeed,clydeY)) {aiCalcDir();}
        else if(clydeDir == RIGHT && ghostsGetCollision(clydeX + ghostSpeed,clydeY)) {aiCalcDir();}
        else if(clydeDir == UP && ghostsGetCollision(clydeX,clydeY - ghostSpeed)) {aiCalcDir();}
        else if(clydeDir == DOWN && ghostsGetCollision(clydeX,clydeY + ghostSpeed)) {aiCalcDir();}

        if     (clydeDir == LEFT   && !ghostsGetCollision(clydeX-1, clydeY)) clydeX -= ghostSpeed;
        else if(clydeDir == RIGHT  && !ghostsGetCollision(clydeX+1, clydeY)) clydeX += ghostSpeed;
        else if(clydeDir == UP     && !ghostsGetCollision(clydeX, clydeY-1)) clydeY -= ghostSpeed;
        else if(clydeDir == DOWN   && !ghostsGetCollision(clydeX, clydeY+1)) clydeY += ghostSpeed;
    }
};

void updateInky()
{
    if(inkyCrossedWall == false){aiCalcDir();}

    if(inkyCrossedWall == false)
    {
       // if(inkyDir == LEFT      ) inkyX -= 1;
        //else if(inkyDir == RIGHT) inkyX += 1;
        if(inkyDir == UP   ) inkyY -= 1;
        //else if(inkyDir == DOWN ) inkyY += 1;
    }
    if(inkyCrossedWall)
    {
        inkyUpdateLimit++;
        if(inkyX < 9) inkyX = 440;
        else if(inkyX >= 450) inkyX = 15;
        //iteration1
        if(atCrossRoad(inkyX, inkyY)) {aiCalcDir();}
        else if(inkyDir == LEFT && ghostsGetCollision(inkyX - 1,inkyY)) {aiCalcDir();}
        else if(inkyDir == RIGHT && ghostsGetCollision(inkyX + 1,inkyY)) {aiCalcDir();}
        else if(inkyDir == UP && ghostsGetCollision(inkyX,inkyY - 1)) {aiCalcDir();}
        else if(inkyDir == DOWN && ghostsGetCollision(inkyX,inkyY + 1)) {aiCalcDir();}

        if     (inkyDir == LEFT   && !ghostsGetCollision(inkyX-1, inkyY)) inkyX -= ghostSpeed;
        else if(inkyDir == RIGHT  && !ghostsGetCollision(inkyX+1, inkyY)) inkyX += ghostSpeed;
        else if(inkyDir == UP     && !ghostsGetCollision(inkyX, inkyY-1)) inkyY -= ghostSpeed;
        else if(inkyDir == DOWN   && !ghostsGetCollision(inkyX, inkyY+1)) inkyY += ghostSpeed;
    }
};

void updatePinky()
{
    if(pinkyCrossedWall == false){aiCalcDir();}

    if(pinkyCrossedWall == false)
    {
        if(pinkyDir == LEFT      ) pinkyX -= 1;
        //else if(pinkyDir == RIGHT) pinkyX += 1;
        else if(pinkyDir == UP   ) pinkyY -= 1;
        //else if(pinkyDir == DOWN ) pinkyY += 1;
    }
    if(pinkyCrossedWall)
    {
        pinkyUpdateLimit++;
        if(pinkyX < 9) pinkyX = 440;
        else if(pinkyX >= 450) pinkyX = 15;
        //iteration1
        if(atCrossRoad(pinkyX, pinkyY)) {aiCalcDir();}
        else if(pinkyDir == LEFT && ghostsGetCollision(pinkyX - 1,pinkyY)) {aiCalcDir();}
        else if(pinkyDir == RIGHT && ghostsGetCollision(pinkyX + 1,pinkyY)) {aiCalcDir();}
        else if(pinkyDir == UP && ghostsGetCollision(pinkyX,pinkyY - 1)) {aiCalcDir();}
        else if(pinkyDir == DOWN && ghostsGetCollision(pinkyX,pinkyY + 1)) {aiCalcDir();}

        if     (pinkyDir == LEFT   && !ghostsGetCollision(pinkyX-1, pinkyY)) pinkyX -= ghostSpeed;
        else if(pinkyDir == RIGHT  && !ghostsGetCollision(pinkyX+1, pinkyY)) pinkyX += ghostSpeed;
        else if(pinkyDir == UP     && !ghostsGetCollision(pinkyX, pinkyY-1)) pinkyY -= ghostSpeed;
        else if(pinkyDir == DOWN   && !ghostsGetCollision(pinkyX, pinkyY+1)) pinkyY += ghostSpeed;
    }
};

void updateAi()
{
    if(!updateAiMovement)
        return;

    for(int i = 0; i < ghostUpdatesPerFrame; i++) {
        updateBlinky();
        updateClyde();
        updateInky();
        updatePinky();
    }
};

bool ghostsGetCollision(int x, int y)
{
    for(int i = 0; i < sizeOfWallArray; i++)
    {
        //32 is corridor width
        if((wallsX[i] >= x && wallsX[i] < x + 32) && (wallsY[i] >= y && wallsY[i] < y + 32))
            return true;
    }
    return false;
};

void blinkyChaseState()
{
//    if(blinkyUpdateLimit < ghostUpdatesPerFrame + 2){
//        return;
//    }
    enum eDirection previousDir = blinkyDir;

    int pointsLeft = 0 + abs(pacX - (blinkyX + 10)) * 10;
    int pointsRight = 0 + abs(pacX - (blinkyX - 10)) * 10;
    int pointsUp = 0 + abs(pacY - (blinkyY + 10)) * 10;
    int pointsDown = 0 + abs(pacY - (blinkyY - 10)) * 10;

    if(ghostsGetCollision(blinkyX - 1,blinkyY))    pointsLeft -= 150000;
    if(ghostsGetCollision(blinkyX + 1,blinkyY))    pointsRight -= 150000;
    if(ghostsGetCollision(blinkyX,blinkyY - 1))    pointsUp -= 150000;
    if(ghostsGetCollision(blinkyX,blinkyY + 1))    pointsDown -= 150000;

    if(closerToPac(blinkyX, blinkyY, blinkyX - 1, blinkyY)) pointsLeft += 500;
    if(closerToPac(blinkyX, blinkyY, blinkyX + 1, blinkyY)) pointsRight += 500;
    if(closerToPac(blinkyX, blinkyY, blinkyX, blinkyY + 1)) pointsDown += 500;
    if(closerToPac(blinkyX, blinkyY, blinkyX, blinkyY - 1)) pointsUp += 500;

    if(previousDir == RIGHT) pointsLeft-=100000;
    else if(previousDir == UP) pointsDown-=100000;
    else if(previousDir == DOWN) pointsUp-=100000;
    else if(previousDir == LEFT) { pointsRight-=100000; }

    if(pointsLeft >= pointsRight && pointsLeft >= pointsDown && pointsLeft >= pointsUp) blinkyDir = LEFT;
    else if(pointsDown >= pointsRight && pointsDown >= pointsUp) blinkyDir = DOWN;
    else if(pointsUp >= pointsRight) blinkyDir = UP;
    else{ blinkyDir = RIGHT; }

    if(blinkyDir == LEFT) blinkyX--;
    if(blinkyDir == RIGHT) blinkyX++;
    if(blinkyDir == UP) blinkyY--;
    if(blinkyDir == DOWN) blinkyY++;

    printf("\nLeft: %d", pointsLeft);
    printf("\nRight: %d", pointsRight);
    printf("\nUp: %d", pointsUp);
    printf("\nDown: %d", pointsDown);
    printf("\nDir: %d\n", blinkyDir);

    blinkyUpdateLimit = 0;

//    while(true)
//    {
//        int random = rand() % 4;
//        if(random == 0 && !ghostsGetCollision(blinkyX - 1,blinkyY) && blinkyDir != RIGHT) {blinkyDir = LEFT; break;}
//        else if(random == 1 && !ghostsGetCollision(blinkyX + 1,blinkyY) && blinkyDir != LEFT) {blinkyDir = RIGHT; break;}
//        else if(random == 2 && !ghostsGetCollision(blinkyX,blinkyY - 1) && blinkyDir != DOWN) {blinkyDir = UP; break;}
//        else if(random == 3 && !ghostsGetCollision(blinkyX,blinkyY + 1) && blinkyDir != UP) {blinkyDir = DOWN; break;}
//
////        else if((random == 14 || random == 15 || random == 16) && !ghostsGetCollision(blinkyX - 1,blinkyY) && blinkyDir != RIGHT && closerToPac(blinkyX, blinkyY, blinkyX - 1, blinkyY)) {blinkyDir = LEFT; break;}
////        else if((random == 5 || random == 6 || random == 7) && !ghostsGetCollision(blinkyX + 1,blinkyY) && blinkyDir != LEFT && closerToPac(blinkyX, blinkyY, blinkyX + 1, blinkyY)) {blinkyDir = RIGHT; break;}
////        else if((random == 8 || random == 9 || random == 10) && !ghostsGetCollision(blinkyX,blinkyY - 1) && blinkyDir != DOWN && closerToPac(blinkyX, blinkyY, blinkyX, blinkyY - 1)) {blinkyDir = UP; break;}
////        else if((random == 11 || random == 12 || random == 13) && !ghostsGetCollision(blinkyX,blinkyY + 1) && blinkyDir != UP && closerToPac(blinkyX, blinkyY, blinkyX, blinkyY + 1)) {blinkyDir = DOWN; break;}
//    }
}

void clydeChaseState()
{
    if(clydeUpdateLimit < 5){
        return;
    }
    while(clydeCrossedWall)
    {  
        int random = rand() % 17;
        if(random == 0 && !ghostsGetCollision(clydeX - 1,clydeY) && clydeDir != RIGHT) {clydeDir = LEFT; break;}
        else if(random == 1 && !ghostsGetCollision(clydeX + 1,clydeY) && clydeDir != LEFT) {clydeDir = RIGHT; break;}
        else if(random == 2 && !ghostsGetCollision(clydeX,clydeY - 1) && clydeDir != DOWN) {clydeDir = UP; break;}
        else if(random == 3 && !ghostsGetCollision(clydeX,clydeY + 1) && clydeDir != UP) {clydeDir = DOWN; break;}

        else if((random == 14 || random == 15 || random == 16) && !ghostsGetCollision(clydeX - 1,clydeY) && clydeDir != RIGHT && closerToPac(clydeX, clydeY, clydeX - 1, clydeY)) {clydeDir = LEFT; break;}
        else if((random == 5 || random == 6 || random == 7) && !ghostsGetCollision(clydeX + 1,clydeY) && clydeDir != LEFT && closerToPac(clydeX, clydeY, clydeX + 1, clydeY)) {clydeDir = RIGHT; break;}
        else if((random == 8 || random == 9 || random == 10) && !ghostsGetCollision(clydeX,clydeY - 1) && clydeDir != DOWN && closerToPac(clydeX, clydeY, clydeX, clydeY - 1)) {clydeDir = UP; break;}
        else if((random == 11 || random == 12 || random == 13) && !ghostsGetCollision(clydeX,clydeY + 1) && clydeDir != UP && closerToPac(clydeX, clydeY, clydeX, clydeY + 1)) {clydeDir = DOWN; break;}
    }
    clydeUpdateLimit=0;
}

void inkyChaseState()
{
    if(inkyUpdateLimit < 5){
        return;
    }
    while(inkyCrossedWall)
    {   
        int random = rand() % 17;
        if(random == 0 && !ghostsGetCollision(inkyX - 1,inkyY) && inkyDir != RIGHT) {inkyDir = LEFT; break;}
        else if(random == 1 && !ghostsGetCollision(inkyX + 1,inkyY) && inkyDir != LEFT) {inkyDir = RIGHT; break;}
        else if(random == 2 && !ghostsGetCollision(inkyX,inkyY - 1) && inkyDir != DOWN) {inkyDir = UP; break;}
        else if(random == 3 && !ghostsGetCollision(inkyX,inkyY + 1) && inkyDir != UP) {inkyDir = DOWN; break;}

        else if((random == 14 || random == 15 || random == 16) && !ghostsGetCollision(inkyX - 1,inkyY) && inkyDir != RIGHT && closerToPac(inkyX, inkyY, inkyX - 1, inkyY)) {inkyDir = LEFT; break;}
        else if((random == 5 || random == 6 || random == 7) && !ghostsGetCollision(inkyX + 1,inkyY) && inkyDir != LEFT && closerToPac(inkyX, inkyY, inkyX + 1, inkyY)) {inkyDir = RIGHT; break;}
        else if((random == 8 || random == 9 || random == 10) && !ghostsGetCollision(inkyX,inkyY - 1) && inkyDir != DOWN && closerToPac(inkyX, inkyY, inkyX, inkyY - 1)) {inkyDir = UP; break;}
        else if((random == 11 || random == 12 || random == 13) && !ghostsGetCollision(inkyX,inkyY + 1) && inkyDir != UP && closerToPac(inkyX, inkyY, inkyX, inkyY + 1)) {inkyDir = DOWN; break;}
    }
    inkyUpdateLimit=0;
}

void pinkyChaseState()
{
    if(pinkyUpdateLimit < 5){
        return;
    }
    while(pinkyCrossedWall)
    {   
        int random = rand() % 17;
        if(random == 0 && !ghostsGetCollision(pinkyX - 1,pinkyY) && pinkyDir != RIGHT) {pinkyDir = LEFT; break;}
        else if(random == 1 && !ghostsGetCollision(pinkyX + 1,pinkyY) && pinkyDir != LEFT) {pinkyDir = RIGHT; break;}
        else if(random == 2 && !ghostsGetCollision(pinkyX,pinkyY - 1) && pinkyDir != DOWN) {pinkyDir = UP; break;}
        else if(random == 3 && !ghostsGetCollision(pinkyX,pinkyY + 1) && pinkyDir != UP) {pinkyDir = DOWN; break;}

        else if((random == 14 || random == 15 || random == 16) && !ghostsGetCollision(pinkyX - 1,pinkyY) && pinkyDir != RIGHT && closerToPac(pinkyX, pinkyY, pinkyX - 1, pinkyY)) {pinkyDir = LEFT; break;}
        else if((random == 5 || random == 6 || random == 7) && !ghostsGetCollision(pinkyX + 1,pinkyY) && pinkyDir != LEFT && closerToPac(pinkyX, pinkyY, pinkyX + 1, pinkyY)) {pinkyDir = RIGHT; break;}
        else if((random == 8 || random == 9 || random == 10) && !ghostsGetCollision(pinkyX,pinkyY - 1) && pinkyDir != DOWN && closerToPac(pinkyX, pinkyY, pinkyX, pinkyY - 1)) {pinkyDir = UP; break;}
        else if((random == 11 || random == 12 || random == 13) && !ghostsGetCollision(pinkyX,pinkyY + 1) && pinkyDir != UP && closerToPac(pinkyX, pinkyY, pinkyX, pinkyY + 1)) {pinkyDir = DOWN; break;}
    }
    pinkyUpdateLimit=0;
}

void blinkyRunState()
{
    while(blinkyCrossedWall)
    {   
        int random = rand() % 17;
        if(random == 0 && !ghostsGetCollision(blinkyX - 1,blinkyY) && blinkyDir != RIGHT) {blinkyDir = LEFT; break;}
        else if(random == 1 && !ghostsGetCollision(blinkyX + 1,blinkyY) && blinkyDir != LEFT) {blinkyDir = RIGHT; break;}
        else if(random == 2 && !ghostsGetCollision(blinkyX,blinkyY - 1) && blinkyDir != DOWN) {blinkyDir = UP; break;}
        else if(random == 3 && !ghostsGetCollision(blinkyX,blinkyY + 1) && blinkyDir != UP) {blinkyDir = DOWN; break;}

        else if((random == 14 || random == 15 || random == 16) && !ghostsGetCollision(blinkyX - 1,blinkyY) && blinkyDir != RIGHT && !closerToPac(blinkyX, blinkyY, blinkyX - 1, blinkyY)) {blinkyDir = LEFT; break;}
        else if((random == 5 || random == 6 || random == 7) && !ghostsGetCollision(blinkyX + 1,blinkyY) && blinkyDir != LEFT && !closerToPac(blinkyX, blinkyY, blinkyX + 1, blinkyY)) {blinkyDir = RIGHT; break;}
        else if((random == 8 || random == 9 || random == 10) && !ghostsGetCollision(blinkyX,blinkyY - 1) && blinkyDir != DOWN && !closerToPac(blinkyX, blinkyY, blinkyX, blinkyY - 1)) {blinkyDir = UP; break;}
        else if((random == 11 || random == 12 || random == 13) && !ghostsGetCollision(blinkyX,blinkyY + 1) && blinkyDir != UP && !closerToPac(blinkyX, blinkyY, blinkyX, blinkyY + 1)) {blinkyDir = DOWN; break;}
    }
   // blinkyFrameCounter = 0;
}

void clydeRunState()
{
    while(clydeCrossedWall)
    {  
        int random = rand() % 17;
        if(random == 0 && !ghostsGetCollision(clydeX - 1,clydeY) && clydeDir != RIGHT) {clydeDir = LEFT; break;}
        else if(random == 1 && !ghostsGetCollision(clydeX + 1,clydeY) && clydeDir != LEFT) {clydeDir = RIGHT; break;}
        else if(random == 2 && !ghostsGetCollision(clydeX,clydeY - 1) && clydeDir != DOWN) {clydeDir = UP; break;}
        else if(random == 3 && !ghostsGetCollision(clydeX,clydeY + 1) && clydeDir != UP) {clydeDir = DOWN; break;}

        else if((random == 14 || random == 15 || random == 16) && !ghostsGetCollision(clydeX - 1,clydeY) && clydeDir != RIGHT && closerToPac(clydeX, clydeY, clydeX - 1, clydeY)) {clydeDir = LEFT; break;}
        else if((random == 5 || random == 6 || random == 7) && !ghostsGetCollision(clydeX + 1,clydeY) && clydeDir != LEFT && closerToPac(clydeX, clydeY, clydeX + 1, clydeY)) {clydeDir = RIGHT; break;}
        else if((random == 8 || random == 9 || random == 10) && !ghostsGetCollision(clydeX,clydeY - 1) && clydeDir != DOWN && closerToPac(clydeX, clydeY, clydeX, clydeY - 1)) {clydeDir = UP; break;}
        else if((random == 11 || random == 12 || random == 13) && !ghostsGetCollision(clydeX,clydeY + 1) && clydeDir != UP && closerToPac(clydeX, clydeY, clydeX, clydeY + 1)) {clydeDir = DOWN; break;}
    }
   // clydeFrameCounter = 0;
}

void inkyRunState()
{
    while(inkyCrossedWall)
    {   
        int random = rand() % 17;
        if(random == 0 && !ghostsGetCollision(inkyX - 1,inkyY) && inkyDir != RIGHT) {inkyDir = LEFT; break;}
        else if(random == 1 && !ghostsGetCollision(inkyX + 1,inkyY) && inkyDir != LEFT) {inkyDir = RIGHT; break;}
        else if(random == 2 && !ghostsGetCollision(inkyX,inkyY - 1) && inkyDir != DOWN) {inkyDir = UP; break;}
        else if(random == 3 && !ghostsGetCollision(inkyX,inkyY + 1) && inkyDir != UP) {inkyDir = DOWN; break;}

        else if((random == 14 || random == 15 || random == 16) && !ghostsGetCollision(inkyX - 1,inkyY) && inkyDir != RIGHT && closerToPac(inkyX, inkyY, inkyX - 1, inkyY)) {inkyDir = LEFT; break;}
        else if((random == 5 || random == 6 || random == 7) && !ghostsGetCollision(inkyX + 1,inkyY) && inkyDir != LEFT && closerToPac(inkyX, inkyY, inkyX + 1, inkyY)) {inkyDir = RIGHT; break;}
        else if((random == 8 || random == 9 || random == 10) && !ghostsGetCollision(inkyX,inkyY - 1) && inkyDir != DOWN && closerToPac(inkyX, inkyY, inkyX, inkyY - 1)) {inkyDir = UP; break;}
        else if((random == 11 || random == 12 || random == 13) && !ghostsGetCollision(inkyX,inkyY + 1) && inkyDir != UP && closerToPac(inkyX, inkyY, inkyX, inkyY + 1)) {inkyDir = DOWN; break;}
    }
   // inkyMovCounter = 0;
}

void pinkyRunState()
{
    while(pinkyCrossedWall)
    {   
        int random = rand() % 17;
        if(random == 0 && !ghostsGetCollision(pinkyX - 1,pinkyY) && pinkyDir != RIGHT) {pinkyDir = LEFT; break;}
        else if(random == 1 && !ghostsGetCollision(pinkyX + 1,pinkyY) && pinkyDir != LEFT) {pinkyDir = RIGHT; break;}
        else if(random == 2 && !ghostsGetCollision(pinkyX,pinkyY - 1) && pinkyDir != DOWN) {pinkyDir = UP; break;}
        else if(random == 3 && !ghostsGetCollision(pinkyX,pinkyY + 1) && pinkyDir != UP) {pinkyDir = DOWN; break;}

        else if((random == 14 || random == 15 || random == 16) && !ghostsGetCollision(pinkyX - 1,pinkyY) && pinkyDir != RIGHT && closerToPac(pinkyX, pinkyY, pinkyX - 1, pinkyY)) {pinkyDir = LEFT; break;}
        else if((random == 5 || random == 6 || random == 7) && !ghostsGetCollision(pinkyX + 1,pinkyY) && pinkyDir != LEFT && closerToPac(pinkyX, pinkyY, pinkyX + 1, pinkyY)) {pinkyDir = RIGHT; break;}
        else if((random == 8 || random == 9 || random == 10) && !ghostsGetCollision(pinkyX,pinkyY - 1) && pinkyDir != DOWN && closerToPac(pinkyX, pinkyY, pinkyX, pinkyY - 1)) {pinkyDir = UP; break;}
        else if((random == 11 || random == 12 || random == 13) && !ghostsGetCollision(pinkyX,pinkyY + 1) && pinkyDir != UP && closerToPac(pinkyX, pinkyY, pinkyX, pinkyY + 1)) {pinkyDir = DOWN; break;}
    }
 //   pinkyMovCounter = 0;
}

void blinkyEyesState()
{
    static bool startCrossingWall = false;
    if(blinkyX == ghostStartX[0] && blinkyY == ghostStartY[0]) { startCrossingWall = true;}
    if(startCrossingWall)
    {
        if(blinkyX != ghostStartX[2] && blinkyY != ghostStartY[2]) {
            blinkyDir = DOWN;
            return;
        }
        else {
            blinkyDead = false;
        startCrossingWall = false;
        blinkyCrossedWall = false;
        }
    }

    enum eDirection previousDir = blinkyDir;

    int pointsLeft = 0 + abs(ghostStartX[0] - (blinkyX + 1)) + rand() % 5;
    int pointsRight = 0 + abs(ghostStartX[0] - (blinkyX - 1)) + rand() % 5;
    int pointsUp = 0 + abs(ghostStartY[0] - (blinkyY + 1)) + rand() % 5;
    int pointsDown = 0 + abs(ghostStartY[0] - (blinkyY - 1)) + rand() % 5;

    if(ghostsGetCollision(blinkyX - 1,blinkyY))    pointsLeft -= 15000;
    if(ghostsGetCollision(blinkyX + 1,blinkyY))    pointsRight -= 15000;
    if(ghostsGetCollision(blinkyX,blinkyY - 1))    pointsUp -= 15000;
    if(ghostsGetCollision(blinkyX,blinkyY + 1))    pointsDown -= 15000;

    if(closerToSpawn(blinkyX, blinkyY, blinkyX - 1, blinkyY)) pointsLeft += 500;
    if(closerToSpawn(blinkyX, blinkyY, blinkyX + 1, blinkyY)) pointsRight += 500;
    if(closerToSpawn(blinkyX, blinkyY, blinkyX, blinkyY + 1)) pointsDown += 500;
    if(closerToSpawn(blinkyX, blinkyY, blinkyX, blinkyY - 1)) pointsUp += 500;

    if(previousDir == RIGHT) pointsLeft-=10000;
    else if(previousDir == UP) pointsDown-=10000;
    else if(previousDir == DOWN) pointsUp-=10000;
    else if(previousDir == LEFT) { pointsRight-=10000; }

    if(pointsLeft >= pointsRight && pointsLeft >= pointsDown && pointsLeft >= pointsUp) blinkyDir = LEFT;
    else if(pointsDown >= pointsRight && pointsDown >= pointsUp) blinkyDir = DOWN;
    else if(pointsUp >= pointsRight) blinkyDir = UP;
    else{ blinkyDir = RIGHT; }

    if(blinkyDir == LEFT) blinkyX--;
    if(blinkyDir == RIGHT) blinkyX++;
    if(blinkyDir == UP) blinkyY--;
    if(blinkyDir == DOWN) blinkyY++;
}

void clydeEyesState()
{
    if(clydeX == ghostStartX[0] && clydeY == ghostStartY[0]) { clydeDead = false; printf("\n\n\n\n HELLO \n\n\n\n"); }

    enum eDirection previousDir = clydeDir;

    int pointsLeft = 0 + abs(ghostStartX[0] - (clydeX + 1)) + rand() % 5;
    int pointsRight = 0 + abs(ghostStartX[0] - (clydeX - 1)) + rand() % 5;
    int pointsUp = 0 + abs(ghostStartY[0] - (clydeY + 1)) + rand() % 5;
    int pointsDown = 0 + abs(ghostStartY[0] - (clydeY - 1)) + rand() % 5;

    if(ghostsGetCollision(clydeX - 1,clydeY))    pointsLeft -= 15000;
    if(ghostsGetCollision(clydeX + 1,clydeY))    pointsRight -= 15000;
    if(ghostsGetCollision(clydeX,clydeY - 1))    pointsUp -= 15000;
    if(ghostsGetCollision(clydeX,clydeY + 1))    pointsDown -= 15000;

    if(closerToSpawn(clydeX, clydeY, clydeX - 1, clydeY)) pointsLeft += 500;
    if(closerToSpawn(clydeX, clydeY, clydeX + 1, clydeY)) pointsRight += 500;
    if(closerToSpawn(clydeX, clydeY, clydeX, clydeY + 1)) pointsDown += 500;
    if(closerToSpawn(clydeX, clydeY, clydeX, clydeY - 1)) pointsUp += 500;

    if(previousDir == RIGHT) pointsLeft-=10000;
    else if(previousDir == UP) pointsDown-=10000;
    else if(previousDir == DOWN) pointsUp-=10000;
    else if(previousDir == LEFT) { pointsRight-=10000; }

    if(pointsLeft >= pointsRight && pointsLeft >= pointsDown && pointsLeft >= pointsUp) clydeDir = LEFT;
    else if(pointsDown >= pointsRight && pointsDown >= pointsUp) clydeDir = DOWN;
    else if(pointsUp >= pointsRight) clydeDir = UP;
    else{ clydeDir = RIGHT; }

    if(clydeDir == LEFT) clydeX--;
    if(clydeDir == RIGHT) clydeX++;
    if(clydeDir == UP) clydeY--;
    if(clydeDir == DOWN) clydeY++;
}

void inkyEyesState()
{
    if(inkyX == ghostStartX[0] && inkyY == ghostStartY[0]) { inkyDead = false; printf("\n\n\n\n HELLO \n\n\n\n"); }

    enum eDirection previousDir = inkyDir;

    int pointsLeft = 0 + abs(ghostStartX[0] - (inkyX + 1)) + rand() % 5;
    int pointsRight = 0 + abs(ghostStartX[0] - (inkyX - 1)) + rand() % 5;
    int pointsUp = 0 + abs(ghostStartY[0] - (inkyY + 1)) + rand() % 5;
    int pointsDown = 0 + abs(ghostStartY[0] - (inkyY - 1)) + rand() % 5;

    if(ghostsGetCollision(inkyX - 1,inkyY))    pointsLeft -= 15000;
    if(ghostsGetCollision(inkyX + 1,inkyY))    pointsRight -= 15000;
    if(ghostsGetCollision(inkyX,inkyY - 1))    pointsUp -= 15000;
    if(ghostsGetCollision(inkyX,inkyY + 1))    pointsDown -= 15000;

    if(closerToSpawn(inkyX, inkyY, inkyX - 1, inkyY)) pointsLeft += 500;
    if(closerToSpawn(inkyX, inkyY, inkyX + 1, inkyY)) pointsRight += 500;
    if(closerToSpawn(inkyX, inkyY, inkyX, inkyY + 1)) pointsDown += 500;
    if(closerToSpawn(inkyX, inkyY, inkyX, inkyY - 1)) pointsUp += 500;

    if(previousDir == RIGHT) pointsLeft-=10000;
    else if(previousDir == UP) pointsDown-=10000;
    else if(previousDir == DOWN) pointsUp-=10000;
    else if(previousDir == LEFT) { pointsRight-=10000; }

    if(pointsLeft >= pointsRight && pointsLeft >= pointsDown && pointsLeft >= pointsUp) inkyDir = LEFT;
    else if(pointsDown >= pointsRight && pointsDown >= pointsUp) inkyDir = DOWN;
    else if(pointsUp >= pointsRight) inkyDir = UP;
    else{ inkyDir = RIGHT; }

    if(inkyDir == LEFT) inkyX--;
    if(inkyDir == RIGHT) inkyX++;
    if(inkyDir == UP) inkyY--;
    if(inkyDir == DOWN) inkyY++;
}

void pinkyEyesState()
{
    if(pinkyX == ghostStartX[0] && pinkyY == ghostStartY[0]) { pinkyDead = false; printf("\n\n\n\n HELLO \n\n\n\n"); }

    enum eDirection previousDir = pinkyDir;

    int pointsLeft = 0 + abs(ghostStartX[0] - (pinkyX + 1)) + rand() % 5;
    int pointsRight = 0 + abs(ghostStartX[0] - (pinkyX - 1)) + rand() % 5;
    int pointsUp = 0 + abs(ghostStartY[0] - (pinkyY + 1)) + rand() % 5;
    int pointsDown = 0 + abs(ghostStartY[0] - (pinkyY - 1)) + rand() % 5;

    if(ghostsGetCollision(pinkyX - 1,pinkyY))    pointsLeft -= 15000;
    if(ghostsGetCollision(pinkyX + 1,pinkyY))    pointsRight -= 15000;
    if(ghostsGetCollision(pinkyX,pinkyY - 1))    pointsUp -= 15000;
    if(ghostsGetCollision(pinkyX,pinkyY + 1))    pointsDown -= 15000;

    if(closerToSpawn(pinkyX, pinkyY, pinkyX - 1, pinkyY)) pointsLeft += 500;
    if(closerToSpawn(pinkyX, pinkyY, pinkyX + 1, pinkyY)) pointsRight += 500;
    if(closerToSpawn(pinkyX, pinkyY, pinkyX, pinkyY + 1)) pointsDown += 500;
    if(closerToSpawn(pinkyX, pinkyY, pinkyX, pinkyY - 1)) pointsUp += 500;

    if(previousDir == RIGHT) pointsLeft-=10000;
    else if(previousDir == UP) pointsDown-=10000;
    else if(previousDir == DOWN) pointsUp-=10000;
    else if(previousDir == LEFT) { pointsRight-=10000; }

    if(pointsLeft >= pointsRight && pointsLeft >= pointsDown && pointsLeft >= pointsUp) pinkyDir = LEFT;
    else if(pointsDown >= pointsRight && pointsDown >= pointsUp) pinkyDir = DOWN;
    else if(pointsUp >= pointsRight) pinkyDir = UP;
    else{ pinkyDir = RIGHT; }

    if(pinkyDir == LEFT) pinkyX--;
    if(pinkyDir == RIGHT) pinkyX++;
    if(pinkyDir == UP) pinkyY--;
    if(pinkyDir == DOWN) pinkyY++;
}

#pragma clang diagnostic pop