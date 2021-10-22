#pragma once

#include "globals.h"

void drawGhosts();
void drawPauseMenu();
void drawHud();

void loadTextures()
{
    Image tempBlinky = LoadImage("../assets/sprites/blinky.png");
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
    
    //ghosts
    ImageResize(&tempBlinky,blinkyWidth,blinkyHeight);
    ImageResize(&tempClyde,clydeWidth,clydeHeight);
    ImageResize(&tempInky,inkyWidth,inkyHeight);
    ImageResize(&tempPinky,pinkyWidth,pinkyHeight);
    //resized to the size of any ghost since they are all the same size
    ImageResize(&tempBlueGhost,pinkyWidth,pinkyHeight);

    ImageResize(&tempHeart, 40,40);
    heart = LoadTextureFromImage(tempHeart);

    blinky = LoadTextureFromImage(tempBlinky);
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
            DrawRectangle(foodsX[i], foodsY[i], 4, 4, WHITE);
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
    if(animCounter >= animMax && paused == false)
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

void drawGhosts()
{
    //offset by 4 to centre the ghosts
    if(!poweredUp)
    {
        DrawTexture(blinky, blinkyX+4 , blinkyY+4, WHITE);
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