#pragma once

#include "globals.h"

void drawGhosts();
void drawPauseMenu();
void drawHud();

void loadTextures()
{
    //blinky(red)
    Image tempBlinkyL1 = LoadImage("../assets/sprites/ghosts/red/blinkyL1.png");
    Image tempBlinkyL2 = LoadImage("../assets/sprites/ghosts/red/blinkyL2.png");
    Image tempBlinkyR1 = LoadImage("../assets/sprites/ghosts/red/blinkyR1.png");
    Image tempBlinkyR2 = LoadImage("../assets/sprites/ghosts/red/blinkyR2.png");
    Image tempBlinkyU1 = LoadImage("../assets/sprites/ghosts/red/blinkyU1.png");
    Image tempBlinkyU2 = LoadImage("../assets/sprites/ghosts/red/blinkyU2.png");
    Image tempBlinkyD1 = LoadImage("../assets/sprites/ghosts/red/blinkyD1.png");
    Image tempBlinkyD2 = LoadImage("../assets/sprites/ghosts/red/blinkyD2.png");

    Image tempClyde = LoadImage("../assets/sprites/clyde.png");
    Image tempInky = LoadImage("../assets/sprites/inky.png");
    Image tempPinky = LoadImage("../assets/sprites/pinky.png");
    Image tempBlueGhost = LoadImage("../assets/sprites/blue_ghost.png");

    Image tempPacWideRight = LoadImage("../assets/sprites/pacWide.png");
    Image tempPacNarrowRight = LoadImage("../assets/sprites/pacNarrow.png");
    Image tempPacClosed = LoadImage("../assets/sprites/pacClosed.png");

    Image tempHeart = LoadImage("../assets/sprites/heart.png");

    Image tempPowerup = LoadImage("../assets/sprites/powerup.png");

    ImageResize(&tempPacWideRight, pacWidth, pacHeight);
    ImageResize(&tempPacNarrowRight, pacWidth, pacHeight);
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

    // ImageResize(&tempPacClosed, 20, 20);
    // pacClosed = LoadTextureFromImage(tempPacClosed);

    ImageResize(&tempPowerup, 21, 14);
    powerup = LoadTextureFromImage(tempPowerup);
    
    //blinky(red)
    ImageResize(&tempBlinkyL1,blinkyWidth,blinkyHeight);
    ImageResize(&tempBlinkyL2,blinkyWidth,blinkyHeight);
    ImageResize(&tempBlinkyR1,blinkyWidth,blinkyHeight);
    ImageResize(&tempBlinkyR2,blinkyWidth,blinkyHeight);
    ImageResize(&tempBlinkyU1,blinkyWidth,blinkyHeight);
    ImageResize(&tempBlinkyU2,blinkyWidth,blinkyHeight);
    ImageResize(&tempBlinkyD1,blinkyWidth,blinkyHeight);
    ImageResize(&tempBlinkyD2,blinkyWidth,blinkyHeight);

    ImageResize(&tempClyde,clydeWidth,clydeHeight);
    ImageResize(&tempInky,inkyWidth,inkyHeight);
    ImageResize(&tempPinky,pinkyWidth,pinkyHeight);
    //resized to the size of any ghost since they are all the same size
    ImageResize(&tempBlueGhost,pinkyWidth,pinkyHeight);

    ImageResize(&tempHeart, 40,40);
    heart = LoadTextureFromImage(tempHeart);

    blinkyL1 = LoadTextureFromImage(tempBlinkyL1);
    blinkyL2 = LoadTextureFromImage(tempBlinkyL2);
    blinkyR1 = LoadTextureFromImage(tempBlinkyR1);
    blinkyR2 = LoadTextureFromImage(tempBlinkyR2);
    blinkyU1 = LoadTextureFromImage(tempBlinkyU1);
    blinkyU2 = LoadTextureFromImage(tempBlinkyU2);
    blinkyD1 = LoadTextureFromImage(tempBlinkyD1);
    blinkyD2 = LoadTextureFromImage(tempBlinkyD2);

    clyde = LoadTextureFromImage(tempClyde);
    inky = LoadTextureFromImage(tempInky);
    pinky = LoadTextureFromImage(tempPinky);
    blueGhost = LoadTextureFromImage(tempBlueGhost);
};

void drawMap()
{
    for(int i = 0; i < sizeOfVisibleWallArray; i++)
        DrawRectangle(visibleWallsX[i], visibleWallsY[i], 1,1, DARKBLUE);

    // for(int i = 0; i < sizeOfWallArray; i++)
    //     DrawRectangle(wallsX[i], wallsY[i], 1,1, GREEN);

    for(int i = 0; i < sizeOfFoodArray; i++)
        if(showFood[i])
            DrawCircle(foodsX[i], foodsY[i], 2.5f, WHITE);
};

void drawPauseMenu()
{
    double menuX = GetScreenWidth() * 0.1;
    double menuY = GetScreenHeight() * 0.3;
    double menuWidth = GetScreenWidth() * 0.8;
    double menuHeight = GetScreenHeight() * 0.3;

    //DrawRectangle((int)menuX, (int)menuY, (int)menuWidth, (int)menuHeight, (Color){41,37,39,235});
    Rectangle rec;
    rec.x = menuX;
    rec.y = menuY;
    rec.width = menuWidth;
    rec.height = menuHeight;

    DrawRectangleRounded(rec, 0.5f, 1, (Color){51,0,51,235});
    DrawText("Paused", (int)menuX + (menuWidth*0.33), (int)menuY + (menuHeight*0.35), 35, WHITE);
}

void drawHud()
{
    double scoreX = 15, scoreY = map.height + 3;
    DrawText(TextFormat("Score: %i", score), scoreX, scoreY, 20, WHITE);

    double heartX = map.width - 75, heartY = map.height - 7;
    DrawTexture(heart, heartX, heartY, WHITE);
    DrawText(TextFormat("x%i", lives), heartX+30, heartY+15, 20, WHITE);
}

void drawGameOverScreen()
{
    double menuX = GetScreenWidth() * 0.1;
    double menuY = GetScreenHeight() * 0.3;
    double menuWidth = GetScreenWidth() * 0.8;
    double menuHeight = GetScreenHeight() * 0.3;
    Rectangle rec;
    rec.x = menuX;
    rec.y = menuY;
    rec.width = menuWidth;
    rec.height = menuHeight;

    //DrawRectangle((int)menuX, (int)menuY, (int)menuWidth, (int)menuHeight, (Color){0,0,102,235});
    DrawRectangleRounded(rec, 0.5f, 1, (Color){0,0,102,235});
    DrawText("Game Over!", (int)menuX + (menuWidth*0.20), (int)menuY + (menuHeight*0.18), 37, WHITE);
    DrawText(TextFormat("Score: %i", score), (int)menuX + (menuWidth*0.20), (int)menuY + (menuHeight*0.49), 25, GRAY);
    DrawText("Press R to Retry", (int)menuX + (menuWidth*0.20), (int)menuY + (menuHeight*0.75), 20, GRAY);
}

void draw(int pacX, int pacY)
{
    if(lives <= 0) {
        drawGameOverScreen();
        return;
    }

    drawMap();

    for(int i = 0; i < numPowerups; i++)
        if(showPowerUp[i])
            DrawTexture(powerup, powerUpX[i] - powerup.width / 2 + 1, powerUpY[i] - powerup.height / 2, CLITERAL(Color){ 255, 188, 180, 225});

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
    if(animCounter >= animMax && paused == false && dir != STOP)
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
    drawGhosts();

    drawHud();

    if(paused)
        drawPauseMenu();
};

bool usingBlinkyL1 = true;

void drawBlinky()
{
    blinkyFrameCounter++;
    Texture2D blinkyLeft = blinkyL1;
    Texture2D blinkyRight = blinkyR1;
    Texture2D blinkyUp = blinkyU1;
    Texture2D blinkyDown = blinkyD1;

    //swapping between blinky left sprites
    if(blinkyFrameCounter >= 10)
    {
        if(usingBlinkyL1)
        {
            blinkyLeft = blinkyL2;
            blinkyRight = blinkyR2;
            blinkyUp = blinkyU2;
            blinkyDown = blinkyD2;

            usingBlinkyL1 = false;
        }
        else {
            blinkyLeft = blinkyL1;
            blinkyRight = blinkyR1;
            blinkyUp = blinkyU1;
            blinkyDown = blinkyD1;

            usingBlinkyL1 = true;
        }
        blinkyFrameCounter = 0;
    }

    if(blinkyDir == LEFT)
        DrawTexture(blinkyLeft, blinkyX+4 , blinkyY+4 ,WHITE);
    if(blinkyDir == RIGHT)
        DrawTexture(blinkyRight, blinkyX+4 , blinkyY+4 ,WHITE);
    if(blinkyDir == UP)
        DrawTexture(blinkyUp, blinkyX+4 , blinkyY+4 ,WHITE);
    if(blinkyDir == DOWN)
        DrawTexture(blinkyDown, blinkyX+4 , blinkyY+4 ,WHITE);

}

void drawGhosts()
{
    //offset by 4 to centre the ghosts
    if(!poweredUp)
    {
        drawBlinky();
        DrawTexture(clyde, clydeX+4 , clydeY+4 ,WHITE);
        DrawTexture(inky, inkyX+4 , inkyY+4 ,WHITE);
        DrawTexture(pinky, pinkyX+4 , pinkyY+4 ,WHITE);
    }
    else if(poweredUp)
    {
        DrawTexture(blueGhost, blinkyX+4 , blinkyY+4, WHITE);
        DrawTexture(blueGhost, clydeX+4 , clydeY+4 ,WHITE);
        DrawTexture(blueGhost, inkyX+4 , inkyY+4 ,WHITE);
        DrawTexture(blueGhost, pinkyX+4 , pinkyY+4 ,WHITE);
        if(poweredUpDuration >= poweredUpMaxDuration)
        {
            poweredUp = false;
            poweredUpDuration = 0;
        }
    }
}