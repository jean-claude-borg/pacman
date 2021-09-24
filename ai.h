#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
#include "globals.h"
#include <stdlib.h>
#include <stdio.h>

bool ghostsGetCollision(int x, int y);
void blinkyChaseState();
void clydeChaseState();
void inkyChaseState();
void pinkyChaseState();
void blinkyRunState();
void clydeRunState();
void inkyRunState();
void pinkyRunState();


enum eDirection blinkyDir;
int blinkyMovCounter = 0;

enum eDirection clydeDir;
int clydeMovCounter = 0;

enum eDirection inkyDir;
int inkyMovCounter = 0;

enum eDirection pinkyDir;
int pinkyMovCounter = 0;

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

void aiCalcDir()
{
    //blinky
    if(blinkyY <= ghostWallY - 33)   {blinkyCrossedWall = true;} 
    if(!blinkyCrossedWall)   blinkyDir = UP; 

    if(!poweredUp)
        blinkyChaseState();
    else if(poweredUp)
        blinkyRunState();

    //clyde
    if(clydeY <= ghostWallY - 33)   {clydeCrossedWall = true;} 
    if(!clydeCrossedWall)   clydeDir = UP; 

    clydeChaseState();

    //inky
    if(inkyY <= ghostWallY - 33)   {inkyCrossedWall = true;} 
    if(!inkyCrossedWall)   inkyDir = UP; 

    inkyChaseState();

    //pinky
    if(pinkyY <= ghostWallY - 33)   {pinkyCrossedWall = true;} 
    if(!pinkyCrossedWall)   pinkyDir = UP; 

    pinkyChaseState();
};

void updateBlinky()
{
    if(!blinkyCrossedWall){aiCalcDir();}
    
    if(!blinkyCrossedWall)
    {    
        if(blinkyDir == LEFT      ) blinkyX -= 1;
        else if(blinkyDir == RIGHT) blinkyX += 1;
        else if(blinkyDir == UP   ) blinkyY -= 1;
        else if(blinkyDir == DOWN ) blinkyY += 1;
    }
    if(blinkyCrossedWall) 
    {
        if(blinkyX < 7) blinkyX = 454;
        else if(blinkyX >= 454) blinkyX = 10;
        //iteration1
        if(blinkyDir == LEFT        && ghostsGetCollision(blinkyX - 1,blinkyY) && blinkyMovCounter >=0) aiCalcDir();
        else if(blinkyDir == RIGHT  && ghostsGetCollision(blinkyX + 1,blinkyY) && blinkyMovCounter >=0) aiCalcDir();
        else if(blinkyDir == UP     && ghostsGetCollision(blinkyX,blinkyY - 1) && blinkyMovCounter >=0) aiCalcDir();
        else if(blinkyDir == DOWN   && ghostsGetCollision(blinkyX,blinkyY + 1) && blinkyMovCounter >=0) aiCalcDir();
        if     (blinkyDir == LEFT   && !ghostsGetCollision(blinkyX - 1,blinkyY)) blinkyX -= 1;
        else if(blinkyDir == RIGHT  && !ghostsGetCollision(blinkyX + 1,blinkyY)) blinkyX += 1;
        else if(blinkyDir == UP     && !ghostsGetCollision(blinkyX,blinkyY - 1)) blinkyY -= 1;
        else if(blinkyDir == DOWN   && !ghostsGetCollision(blinkyX,blinkyY + 1)) blinkyY += 1;
        if(atCrossRoad(blinkyX, blinkyY)) aiCalcDir();
        //iteration2
        if(blinkyDir == LEFT        && ghostsGetCollision(blinkyX - 1,blinkyY) && blinkyMovCounter >=0) aiCalcDir();
        else if(blinkyDir == RIGHT  && ghostsGetCollision(blinkyX + 1,blinkyY) && blinkyMovCounter >=0) aiCalcDir();
        else if(blinkyDir == UP     && ghostsGetCollision(blinkyX,blinkyY - 1) && blinkyMovCounter >=0) aiCalcDir();
        else if(blinkyDir == DOWN   && ghostsGetCollision(blinkyX,blinkyY + 1) && blinkyMovCounter >=0) aiCalcDir();
        if     (blinkyDir == LEFT   && !ghostsGetCollision(blinkyX - 1,blinkyY)) blinkyX -= 1;
        else if(blinkyDir == RIGHT  && !ghostsGetCollision(blinkyX + 1,blinkyY)) blinkyX += 1;
        else if(blinkyDir == UP     && !ghostsGetCollision(blinkyX,blinkyY - 1)) blinkyY -= 1;
        else if(blinkyDir == DOWN   && !ghostsGetCollision(blinkyX,blinkyY + 1)) blinkyY += 1;
        if(atCrossRoad(blinkyX, blinkyY)) aiCalcDir();   
    }
    blinkyMovCounter++;
};

void updateClyde()
{
    if(!clydeCrossedWall){aiCalcDir();}
    
    if(!clydeCrossedWall)
    {    
        if(clydeDir == LEFT      ) clydeX -= 1;
        else if(clydeDir == RIGHT) clydeX += 1;
        else if(clydeDir == UP   ) clydeY -= 1;
        else if(clydeDir == DOWN ) clydeY += 1;
    }
    if(clydeCrossedWall) 
    {
        if(clydeX < 7) clydeX = 454;
        else if(clydeX >= 454) clydeX = 10;
        //iteration1
        if(clydeDir == LEFT        && ghostsGetCollision(clydeX - 1,clydeY) && clydeMovCounter >=0) aiCalcDir();
        else if(clydeDir == RIGHT  && ghostsGetCollision(clydeX + 1,clydeY) && clydeMovCounter >=0) aiCalcDir();
        else if(clydeDir == UP     && ghostsGetCollision(clydeX,clydeY - 1) && clydeMovCounter >=0) aiCalcDir();
        else if(clydeDir == DOWN   && ghostsGetCollision(clydeX,clydeY + 1) && clydeMovCounter >=0) aiCalcDir();
        if     (clydeDir == LEFT   && !ghostsGetCollision(clydeX - 1,clydeY)) clydeX -= 1;
        else if(clydeDir == RIGHT  && !ghostsGetCollision(clydeX + 1,clydeY)) clydeX += 1;
        else if(clydeDir == UP     && !ghostsGetCollision(clydeX,clydeY - 1)) clydeY -= 1;
        else if(clydeDir == DOWN   && !ghostsGetCollision(clydeX,clydeY + 1)) clydeY += 1;
        if(atCrossRoad(clydeX, clydeY)) aiCalcDir();
        //iteration2
        if(clydeDir == LEFT        && ghostsGetCollision(clydeX - 1,clydeY) && clydeMovCounter >=0) aiCalcDir();
        else if(clydeDir == RIGHT  && ghostsGetCollision(clydeX + 1,clydeY) && clydeMovCounter >=0) aiCalcDir();
        else if(clydeDir == UP     && ghostsGetCollision(clydeX,clydeY - 1) && clydeMovCounter >=0) aiCalcDir();
        else if(clydeDir == DOWN   && ghostsGetCollision(clydeX,clydeY + 1) && clydeMovCounter >=0) aiCalcDir();
        if     (clydeDir == LEFT   && !ghostsGetCollision(clydeX - 1,clydeY)) clydeX -= 1;
        else if(clydeDir == RIGHT  && !ghostsGetCollision(clydeX + 1,clydeY)) clydeX += 1;
        else if(clydeDir == UP     && !ghostsGetCollision(clydeX,clydeY - 1)) clydeY -= 1;
        else if(clydeDir == DOWN   && !ghostsGetCollision(clydeX,clydeY + 1)) clydeY += 1;
        if(atCrossRoad(clydeX, clydeY)) aiCalcDir();
    }
    clydeMovCounter++;
};

void updateInky()
{
    if(!inkyCrossedWall){aiCalcDir();}
    
    if(!inkyCrossedWall)
    {    
        if(inkyDir == LEFT      ) inkyX -= 1;
        else if(inkyDir == RIGHT) inkyX += 1;
        else if(inkyDir == UP   ) inkyY -= 1;
        else if(inkyDir == DOWN ) inkyY += 1;
    }
    if(inkyCrossedWall) 
    {
        if(inkyX < 7) inkyX = 454;
        else if(inkyX >= 454) inkyX = 10;
        //iteration1
        if(inkyDir == LEFT        && ghostsGetCollision(inkyX - 1,inkyY) && inkyMovCounter >=0) aiCalcDir();
        else if(inkyDir == RIGHT  && ghostsGetCollision(inkyX + 1,inkyY) && inkyMovCounter >=0) aiCalcDir();
        else if(inkyDir == UP     && ghostsGetCollision(inkyX,inkyY - 1) && inkyMovCounter >=0) aiCalcDir();
        else if(inkyDir == DOWN   && ghostsGetCollision(inkyX,inkyY + 1) && inkyMovCounter >=0) aiCalcDir();
        if     (inkyDir == LEFT   && !ghostsGetCollision(inkyX - 1,inkyY)) inkyX -= 1;
        else if(inkyDir == RIGHT  && !ghostsGetCollision(inkyX + 1,inkyY)) inkyX += 1;
        else if(inkyDir == UP     && !ghostsGetCollision(inkyX,inkyY - 1)) inkyY -= 1;
        else if(inkyDir == DOWN   && !ghostsGetCollision(inkyX,inkyY + 1)) inkyY += 1;
        if(atCrossRoad(inkyX, inkyY)) aiCalcDir();
        //iteration2
        if(inkyDir == LEFT        && ghostsGetCollision(inkyX - 1,inkyY) && inkyMovCounter >=0) aiCalcDir();
        else if(inkyDir == RIGHT  && ghostsGetCollision(inkyX + 1,inkyY) && inkyMovCounter >=0) aiCalcDir();
        else if(inkyDir == UP     && ghostsGetCollision(inkyX,inkyY - 1) && inkyMovCounter >=0) aiCalcDir();
        else if(inkyDir == DOWN   && ghostsGetCollision(inkyX,inkyY + 1) && inkyMovCounter >=0) aiCalcDir();
        if     (inkyDir == LEFT   && !ghostsGetCollision(inkyX - 1,inkyY)) inkyX -= 1;
        else if(inkyDir == RIGHT  && !ghostsGetCollision(inkyX + 1,inkyY)) inkyX += 1;
        else if(inkyDir == UP     && !ghostsGetCollision(inkyX,inkyY - 1)) inkyY -= 1;
        else if(inkyDir == DOWN   && !ghostsGetCollision(inkyX,inkyY + 1)) inkyY += 1;
        if(atCrossRoad(inkyX, inkyY)) aiCalcDir();
    }
    inkyMovCounter++;
};

void updatePinky()
{
    if(!pinkyCrossedWall){aiCalcDir();}
    
    if(!pinkyCrossedWall)
    {    
        if(pinkyDir == LEFT      ) pinkyX -= 1;
        else if(pinkyDir == RIGHT) pinkyX += 1;
        else if(pinkyDir == UP   ) pinkyY -= 1;
        else if(pinkyDir == DOWN ) pinkyY += 1;
    }
    if(pinkyCrossedWall) 
    {
        if(pinkyX < 7) pinkyX = 454;
        else if(pinkyX >= 454) pinkyX = 10;
        //iteration1
        if(pinkyDir == LEFT        && ghostsGetCollision(pinkyX - 1,pinkyY) && pinkyMovCounter >=0) aiCalcDir();
        else if(pinkyDir == RIGHT  && ghostsGetCollision(pinkyX + 1,pinkyY) && pinkyMovCounter >=0) aiCalcDir();
        else if(pinkyDir == UP     && ghostsGetCollision(pinkyX,pinkyY - 1) && pinkyMovCounter >=0) aiCalcDir();
        else if(pinkyDir == DOWN   && ghostsGetCollision(pinkyX,pinkyY + 1) && pinkyMovCounter >=0) aiCalcDir();
        if     (pinkyDir == LEFT   && !ghostsGetCollision(pinkyX - 1,pinkyY)) pinkyX -= 1;
        else if(pinkyDir == RIGHT  && !ghostsGetCollision(pinkyX + 1,pinkyY)) pinkyX += 1;
        else if(pinkyDir == UP     && !ghostsGetCollision(pinkyX,pinkyY - 1)) pinkyY -= 1;
        else if(pinkyDir == DOWN   && !ghostsGetCollision(pinkyX,pinkyY + 1)) pinkyY += 1;
        if(atCrossRoad(pinkyX, pinkyY)) aiCalcDir();
        //iteration2
        if(pinkyDir == LEFT        && ghostsGetCollision(pinkyX - 1,pinkyY) && pinkyMovCounter >=0) aiCalcDir();
        else if(pinkyDir == RIGHT  && ghostsGetCollision(pinkyX + 1,pinkyY) && pinkyMovCounter >=0) aiCalcDir();
        else if(pinkyDir == UP     && ghostsGetCollision(pinkyX,pinkyY - 1) && pinkyMovCounter >=0) aiCalcDir();
        else if(pinkyDir == DOWN   && ghostsGetCollision(pinkyX,pinkyY + 1) && pinkyMovCounter >=0) aiCalcDir();
        if     (pinkyDir == LEFT   && !ghostsGetCollision(pinkyX - 1,pinkyY)) pinkyX -= 1;
        else if(pinkyDir == RIGHT  && !ghostsGetCollision(pinkyX + 1,pinkyY)) pinkyX += 1;
        else if(pinkyDir == UP     && !ghostsGetCollision(pinkyX,pinkyY - 1)) pinkyY -= 1;
        else if(pinkyDir == DOWN   && !ghostsGetCollision(pinkyX,pinkyY + 1)) pinkyY += 1;
        if(atCrossRoad(pinkyX, pinkyY)) aiCalcDir();
    }
    pinkyMovCounter++;
};

void updateAi()
{
    updateBlinky();
    updateClyde();
    updateInky();
    updatePinky();
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
    while(blinkyCrossedWall)
    {   
        int random = rand() % 17;
        if(random == 0 && !ghostsGetCollision(blinkyX - 1,blinkyY) && blinkyDir != RIGHT) {blinkyDir = LEFT; break;}
        else if(random == 1 && !ghostsGetCollision(blinkyX + 1,blinkyY) && blinkyDir != LEFT) {blinkyDir = RIGHT; break;}
        else if(random == 2 && !ghostsGetCollision(blinkyX,blinkyY - 1) && blinkyDir != DOWN) {blinkyDir = UP; break;}
        else if(random == 3 && !ghostsGetCollision(blinkyX,blinkyY + 1) && blinkyDir != UP) {blinkyDir = DOWN; break;}

        else if((random == 14 || random == 15 || random == 16) && !ghostsGetCollision(blinkyX - 1,blinkyY) && blinkyDir != RIGHT && closerToPac(blinkyX, blinkyY, blinkyX - 1, blinkyY)) {blinkyDir = LEFT; break;}
        else if((random == 5 || random == 6 || random == 7) && !ghostsGetCollision(blinkyX + 1,blinkyY) && blinkyDir != LEFT && closerToPac(blinkyX, blinkyY, blinkyX + 1, blinkyY)) {blinkyDir = RIGHT; break;}
        else if((random == 8 || random == 9 || random == 10) && !ghostsGetCollision(blinkyX,blinkyY - 1) && blinkyDir != DOWN && closerToPac(blinkyX, blinkyY, blinkyX, blinkyY - 1)) {blinkyDir = UP; break;}
        else if((random == 11 || random == 12 || random == 13) && !ghostsGetCollision(blinkyX,blinkyY + 1) && blinkyDir != UP && closerToPac(blinkyX, blinkyY, blinkyX, blinkyY + 1)) {blinkyDir = DOWN; break;}
    }
    blinkyMovCounter = 0;
}

void clydeChaseState()
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
    clydeMovCounter = 0;
}

void inkyChaseState()
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
    inkyMovCounter = 0;
}

void pinkyChaseState()
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
    pinkyMovCounter = 0;
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
    blinkyMovCounter = 0;
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
    clydeMovCounter = 0;
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
    inkyMovCounter = 0;
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
    pinkyMovCounter = 0;
}
#pragma clang diagnostic pop