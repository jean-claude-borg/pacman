#include "globals.h"
#include <stdlib.h>
#include <stdio.h>

bool ghostsGetCollision(int x, int y);

enum eDirection blinkyDir;
bool blinkyCrossedWall = false;
int blinkyMovCounter = 0;

enum eDirection clydeDir;
bool clydeCrossedWall = false;
int clydeMovCounter = 0;

enum eDirection inkyDir;
bool inkyCrossedWall = false;
int inkyMovCounter = 0;

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

void aiCalcDir()
{
    if(blinkyY <= ghostWallY - 33)   {blinkyCrossedWall = true;} 
    if(!blinkyCrossedWall)   blinkyDir = UP; 

    while(blinkyCrossedWall)
    {   
        int random = rand() % 4;
        if(random == 0 && !ghostsGetCollision(blinkyX - 1,blinkyY) && blinkyDir != RIGHT) {blinkyDir = LEFT; break;}
        else if(random == 1 && !ghostsGetCollision(blinkyX + 1,blinkyY) && blinkyDir != LEFT) {blinkyDir = RIGHT; break;}
        else if(random == 2 && !ghostsGetCollision(blinkyX,blinkyY - 1) && blinkyDir != DOWN) {blinkyDir = UP; break;}
        else if(random == 3 && !ghostsGetCollision(blinkyX,blinkyY + 1) && blinkyDir != UP) {blinkyDir = DOWN; break;}
    }
    blinkyMovCounter = 0;

    if(clydeY <= ghostWallY - 33)   {clydeCrossedWall = true;} 
    if(!clydeCrossedWall)   clydeDir = UP; 

    while(clydeCrossedWall)
    {   
        int random = rand() % 4;
        if(random == 0 && !ghostsGetCollision(clydeX - 1,clydeY) && clydeDir != RIGHT) {clydeDir = LEFT; break;}
        else if(random == 1 && !ghostsGetCollision(clydeX + 1,clydeY) && clydeDir != LEFT) {clydeDir = RIGHT; break;}
        else if(random == 2 && !ghostsGetCollision(clydeX,clydeY - 1) && clydeDir != DOWN) {clydeDir = UP; break;}
        else if(random == 3 && !ghostsGetCollision(clydeX,clydeY + 1) && clydeDir != UP) {clydeDir = DOWN; break;}
    }
    clydeMovCounter = 0;

    if(inkyY <= ghostWallY - 33)   {inkyCrossedWall = true;} 
    if(!inkyCrossedWall)   inkyDir = UP; 

    while(inkyCrossedWall)
    {   
        int random = rand() % 4;
        if(random == 0 && !ghostsGetCollision(inkyX - 1,inkyY) && inkyDir != RIGHT) {inkyDir = LEFT; break;}
        else if(random == 1 && !ghostsGetCollision(inkyX + 1,inkyY) && inkyDir != LEFT) {inkyDir = RIGHT; break;}
        else if(random == 2 && !ghostsGetCollision(inkyX,inkyY - 1) && inkyDir != DOWN) {inkyDir = UP; break;}
        else if(random == 3 && !ghostsGetCollision(inkyX,inkyY + 1) && inkyDir != UP) {inkyDir = DOWN; break;}
    }
    inkyMovCounter = 0;
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
        if(blinkyDir == LEFT        && ghostsGetCollision(blinkyX - 1,blinkyY) && blinkyMovCounter >=20) aiCalcDir();
        else if(blinkyDir == RIGHT  && ghostsGetCollision(blinkyX + 1,blinkyY) && blinkyMovCounter >=20) aiCalcDir();
        else if(blinkyDir == UP     && ghostsGetCollision(blinkyX,blinkyY - 1) && blinkyMovCounter >=20) aiCalcDir();
        else if(blinkyDir == DOWN   && ghostsGetCollision(blinkyX,blinkyY + 1) && blinkyMovCounter >=20) aiCalcDir();
        if     (blinkyDir == LEFT   && !ghostsGetCollision(blinkyX - 1,blinkyY)) blinkyX -= 1;
        else if(blinkyDir == RIGHT  && !ghostsGetCollision(blinkyX + 1,blinkyY)) blinkyX += 1;
        else if(blinkyDir == UP     && !ghostsGetCollision(blinkyX,blinkyY - 1)) blinkyY -= 1;
        else if(blinkyDir == DOWN   && !ghostsGetCollision(blinkyX,blinkyY + 1)) blinkyY += 1;
        if(atCrossRoad(blinkyX, blinkyY)) aiCalcDir();
        //iteration2
        if(blinkyDir == LEFT        && ghostsGetCollision(blinkyX - 1,blinkyY) && blinkyMovCounter >=20) aiCalcDir();
        else if(blinkyDir == RIGHT  && ghostsGetCollision(blinkyX + 1,blinkyY) && blinkyMovCounter >=20) aiCalcDir();
        else if(blinkyDir == UP     && ghostsGetCollision(blinkyX,blinkyY - 1) && blinkyMovCounter >=20) aiCalcDir();
        else if(blinkyDir == DOWN   && ghostsGetCollision(blinkyX,blinkyY + 1) && blinkyMovCounter >=20) aiCalcDir();
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
        if(clydeDir == LEFT        && ghostsGetCollision(clydeX - 1,clydeY) && clydeMovCounter >=20) aiCalcDir();
        else if(clydeDir == RIGHT  && ghostsGetCollision(clydeX + 1,clydeY) && clydeMovCounter >=20) aiCalcDir();
        else if(clydeDir == UP     && ghostsGetCollision(clydeX,clydeY - 1) && clydeMovCounter >=20) aiCalcDir();
        else if(clydeDir == DOWN   && ghostsGetCollision(clydeX,clydeY + 1) && clydeMovCounter >=20) aiCalcDir();
        if     (clydeDir == LEFT   && !ghostsGetCollision(clydeX - 1,clydeY)) clydeX -= 1;
        else if(clydeDir == RIGHT  && !ghostsGetCollision(clydeX + 1,clydeY)) clydeX += 1;
        else if(clydeDir == UP     && !ghostsGetCollision(clydeX,clydeY - 1)) clydeY -= 1;
        else if(clydeDir == DOWN   && !ghostsGetCollision(clydeX,clydeY + 1)) clydeY += 1;
        if(atCrossRoad(clydeX, clydeY)) aiCalcDir();
        //iteration2
        if(clydeDir == LEFT        && ghostsGetCollision(clydeX - 1,clydeY) && clydeMovCounter >=20) aiCalcDir();
        else if(clydeDir == RIGHT  && ghostsGetCollision(clydeX + 1,clydeY) && clydeMovCounter >=20) aiCalcDir();
        else if(clydeDir == UP     && ghostsGetCollision(clydeX,clydeY - 1) && clydeMovCounter >=20) aiCalcDir();
        else if(clydeDir == DOWN   && ghostsGetCollision(clydeX,clydeY + 1) && clydeMovCounter >=20) aiCalcDir();
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
        if(inkyDir == LEFT        && ghostsGetCollision(inkyX - 1,inkyY) && inkyMovCounter >=20) aiCalcDir();
        else if(inkyDir == RIGHT  && ghostsGetCollision(inkyX + 1,inkyY) && inkyMovCounter >=20) aiCalcDir();
        else if(inkyDir == UP     && ghostsGetCollision(inkyX,inkyY - 1) && inkyMovCounter >=20) aiCalcDir();
        else if(inkyDir == DOWN   && ghostsGetCollision(inkyX,inkyY + 1) && inkyMovCounter >=20) aiCalcDir();
        if     (inkyDir == LEFT   && !ghostsGetCollision(inkyX - 1,inkyY)) inkyX -= 1;
        else if(inkyDir == RIGHT  && !ghostsGetCollision(inkyX + 1,inkyY)) inkyX += 1;
        else if(inkyDir == UP     && !ghostsGetCollision(inkyX,inkyY - 1)) inkyY -= 1;
        else if(inkyDir == DOWN   && !ghostsGetCollision(inkyX,inkyY + 1)) inkyY += 1;
        if(atCrossRoad(inkyX, inkyY)) aiCalcDir();
        //iteration2
        if(inkyDir == LEFT        && ghostsGetCollision(inkyX - 1,inkyY) && inkyMovCounter >=20) aiCalcDir();
        else if(inkyDir == RIGHT  && ghostsGetCollision(inkyX + 1,inkyY) && inkyMovCounter >=20) aiCalcDir();
        else if(inkyDir == UP     && ghostsGetCollision(inkyX,inkyY - 1) && inkyMovCounter >=20) aiCalcDir();
        else if(inkyDir == DOWN   && ghostsGetCollision(inkyX,inkyY + 1) && inkyMovCounter >=20) aiCalcDir();
        if     (inkyDir == LEFT   && !ghostsGetCollision(inkyX - 1,inkyY)) inkyX -= 1;
        else if(inkyDir == RIGHT  && !ghostsGetCollision(inkyX + 1,inkyY)) inkyX += 1;
        else if(inkyDir == UP     && !ghostsGetCollision(inkyX,inkyY - 1)) inkyY -= 1;
        else if(inkyDir == DOWN   && !ghostsGetCollision(inkyX,inkyY + 1)) inkyY += 1;
        if(atCrossRoad(inkyX, inkyY)) aiCalcDir();
    }
    inkyMovCounter++;
};

void updateAi()
{
    updateBlinky();
    updateClyde();
    updateInky();
};

bool ghostsGetCollision(int x, int y)
{
    for(int i = 0; i < sizeOfWallArray; i++)
    {
        if((wallsX[i] >= x && wallsX[i] < x + blinkyWidth) && (wallsY[i] >= y && wallsY[i] < y + blinkyHeight))
            return true;
    }
    return false;
};
