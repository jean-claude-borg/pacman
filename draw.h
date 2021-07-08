#pragma once

#include "globals.h"

Texture2D pacWide;
Texture2D pacNarrow;

void loadTextures()
{
    Image tempBlinky = LoadImage("../assets/sprites/blinky.png");
    Image tempClyde = LoadImage("../assets/sprites/clyde.png");
    Image tempInky = LoadImage("../assets/sprites/inky.png");
    Image tempPinky = LoadImage("../assets/sprites/pinky.png");
    Image tempBlueGhost = LoadImage("../assets/sprites/blueGhost.png");

    Image tempPacWideRight = LoadImage("../assets/sprites/pacWide.png");
    Image tempPacNarrowRight = LoadImage("../assets/sprites/pacNarrow.png");
    Image tempPacClosed = LoadImage("../assets/sprites/pacClosed.png");

    ImageResize(&tempPacWideRight, 31, 31);
    ImageResize(&tempPacNarrowRight, 31, 31);

    pacWideRight = LoadTextureFromImage(tempPacWideRight);
    pacNarrowRight = LoadTextureFromImage(tempPacNarrowRight);

    ImageRotateCW(&tempPacWideRight);
    ImageRotateCW(&tempPacNarrowRight);

    pacWideDown = LoadTextureFromImage(tempPacWideRight);
    pacNarrowDown = LoadTextureFromImage(tempPacNarrowRight);

    ImageRotateCW(&tempPacWideRight);
    ImageRotateCW(&tempPacNarrowRight);

    pacWideLeft = LoadTextureFromImage(tempPacWideRight);
    pacNarrowLeft = LoadTextureFromImage(tempPacNarrowRight);

    ImageRotateCW(&tempPacWideRight);
    ImageRotateCW(&tempPacNarrowRight);

    pacWideUp = LoadTextureFromImage(tempPacWideRight);
    pacNarrowUp = LoadTextureFromImage(tempPacNarrowRight);

    ImageResize(&tempPacClosed, 20, 20);

    pacClosed = LoadTextureFromImage(tempPacClosed);

    //ghosts
    ImageResize(&tempBlinky,blinkyWidth,blinkyHeight);
    ImageResize(&tempClyde,clydeWidth,clydeHeight);
    ImageResize(&tempInky,25,25);
    ImageResize(&tempPinky,25,25);

    blinky = LoadTextureFromImage(tempBlinky);
    clyde = LoadTextureFromImage(tempClyde);
    inky = LoadTextureFromImage(tempInky);
    pinky = LoadTextureFromImage(tempPinky);
    blueGhost = LoadTextureFromImage(tempBlueGhost);
};

void draw(int pacX, int pacY)
{
    if(dir == LEFT)          {pacWide = pacWideLeft;     pacNarrow = pacNarrowLeft;}
    else if(dir == RIGHT)    {pacWide = pacWideRight;    pacNarrow = pacNarrowRight;}
    else if(dir == UP)       {pacWide = pacWideUp;       pacNarrow = pacNarrowUp;}
    else if(dir == DOWN)     {pacWide = pacWideDown;     pacNarrow = pacNarrowDown;}

    if(drawWide)
    {
        DrawTexture(pacWide, pacX ,pacY ,WHITE);
        animCounter++;
    }
    else if(drawNarrow)
    {
        DrawTexture(pacNarrow, pacX ,pacY ,WHITE);
        animCounter++;
    }
    if(animCounter == animMax)
    {
        if(drawWide)
        {
            drawWide = false;
            drawNarrow = true;
        }
        else if(drawNarrow)
        {
            drawWide = true;
            drawNarrow = false;
        }
        animCounter = 0;
    }
    DrawRectangle(ghostWallX,ghostWallY, 37, 4, CLITERAL(Color){ 255, 203, 164, 255 }); 
    DrawTexture(blinky, blinkyX , blinkyY, WHITE);
    DrawTexture(clyde, clydeX , clydeY ,WHITE);
    DrawTexture(inky, inkyX , inkyY ,WHITE);
    DrawTexture(pinky, pinkyX , pinkyY ,WHITE);
};