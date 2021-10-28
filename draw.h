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

    //clyde(blue)
    Image tempClydeL1 = LoadImage("../assets/sprites/ghosts/blue/clydeL1.png");
    Image tempClydeL2 = LoadImage("../assets/sprites/ghosts/blue/clydeL2.png");
    Image tempClydeR1 = LoadImage("../assets/sprites/ghosts/blue/clydeR1.png");
    Image tempClydeR2 = LoadImage("../assets/sprites/ghosts/blue/clydeR2.png");
    Image tempClydeU1 = LoadImage("../assets/sprites/ghosts/blue/clydeU1.png");
    Image tempClydeU2 = LoadImage("../assets/sprites/ghosts/blue/clydeU2.png");
    Image tempClydeD1 = LoadImage("../assets/sprites/ghosts/blue/clydeD1.png");
    Image tempClydeD2 = LoadImage("../assets/sprites/ghosts/blue/clydeD2.png");

    //inky(orange)
    Image tempInkyL1 = LoadImage("../assets/sprites/ghosts/orange/inkyL1.png");
    Image tempInkyL2 = LoadImage("../assets/sprites/ghosts/orange/inkyL2.png");
    Image tempInkyR1 = LoadImage("../assets/sprites/ghosts/orange/inkyR1.png");
    Image tempInkyR2 = LoadImage("../assets/sprites/ghosts/orange/inkyR2.png");
    Image tempInkyU1 = LoadImage("../assets/sprites/ghosts/orange/inkyU1.png");
    Image tempInkyU2 = LoadImage("../assets/sprites/ghosts/orange/inkyU2.png");
    Image tempInkyD1 = LoadImage("../assets/sprites/ghosts/orange/inkyD1.png");
    Image tempInkyD2 = LoadImage("../assets/sprites/ghosts/orange/inkyD2.png");

    //pinky(pink)
    Image tempPinkyL1 = LoadImage("../assets/sprites/ghosts/pink/pinkyL1.png");
    Image tempPinkyL2 = LoadImage("../assets/sprites/ghosts/pink/pinkyL2.png");
    Image tempPinkyR1 = LoadImage("../assets/sprites/ghosts/pink/pinkyR1.png");
    Image tempPinkyR2 = LoadImage("../assets/sprites/ghosts/pink/pinkyR2.png");
    Image tempPinkyU1 = LoadImage("../assets/sprites/ghosts/pink/pinkyU1.png");
    Image tempPinkyU2 = LoadImage("../assets/sprites/ghosts/pink/pinkyU2.png");
    Image tempPinkyD1 = LoadImage("../assets/sprites/ghosts/pink/pinkyD1.png");
    Image tempPinkyD2 = LoadImage("../assets/sprites/ghosts/pink/pinkyD2.png");
    
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

    //clyde(blue)
    ImageResize(&tempClydeL1,clydeWidth,clydeHeight);
    ImageResize(&tempClydeL2,clydeWidth,clydeHeight);
    ImageResize(&tempClydeR1,clydeWidth,clydeHeight);
    ImageResize(&tempClydeR2,clydeWidth,clydeHeight);
    ImageResize(&tempClydeU1,clydeWidth,clydeHeight);
    ImageResize(&tempClydeU2,clydeWidth,clydeHeight);
    ImageResize(&tempClydeD1,clydeWidth,clydeHeight);
    ImageResize(&tempClydeD2,clydeWidth,clydeHeight);

    //inky(orange)
    ImageResize(&tempInkyL1,inkyWidth,inkyHeight);
    ImageResize(&tempInkyL2,inkyWidth,inkyHeight);
    ImageResize(&tempInkyR1,inkyWidth,inkyHeight);
    ImageResize(&tempInkyR2,inkyWidth,inkyHeight);
    ImageResize(&tempInkyU1,inkyWidth,inkyHeight);
    ImageResize(&tempInkyU2,inkyWidth,inkyHeight);
    ImageResize(&tempInkyD1,inkyWidth,inkyHeight);
    ImageResize(&tempInkyD2,inkyWidth,inkyHeight);

    //pinky(pink)
    ImageResize(&tempPinkyL1,pinkyWidth,pinkyHeight);
    ImageResize(&tempPinkyL2,pinkyWidth,pinkyHeight);
    ImageResize(&tempPinkyR1,pinkyWidth,pinkyHeight);
    ImageResize(&tempPinkyR2,pinkyWidth,pinkyHeight);
    ImageResize(&tempPinkyU1,pinkyWidth,pinkyHeight);
    ImageResize(&tempPinkyU2,pinkyWidth,pinkyHeight);
    ImageResize(&tempPinkyD1,pinkyWidth,pinkyHeight);
    ImageResize(&tempPinkyD2,pinkyWidth,pinkyHeight);

    //resized to the size of any ghost since they are all the same size
    ImageResize(&tempBlueGhost,pinkyWidth,pinkyHeight);

    ImageResize(&tempHeart, 40,40);
    heart = LoadTextureFromImage(tempHeart);

    //blinky
    blinkyL1 = LoadTextureFromImage(tempBlinkyL1);
    blinkyL2 = LoadTextureFromImage(tempBlinkyL2);
    blinkyR1 = LoadTextureFromImage(tempBlinkyR1);
    blinkyR2 = LoadTextureFromImage(tempBlinkyR2);
    blinkyU1 = LoadTextureFromImage(tempBlinkyU1);
    blinkyU2 = LoadTextureFromImage(tempBlinkyU2);
    blinkyD1 = LoadTextureFromImage(tempBlinkyD1);
    blinkyD2 = LoadTextureFromImage(tempBlinkyD2);

    //clyde
    clydeL1 = LoadTextureFromImage(tempClydeL1);
    clydeL2 = LoadTextureFromImage(tempClydeL2);
    clydeR1 = LoadTextureFromImage(tempClydeR1);
    clydeR2 = LoadTextureFromImage(tempClydeR2);
    clydeU1 = LoadTextureFromImage(tempClydeU1);
    clydeU2 = LoadTextureFromImage(tempClydeU2);
    clydeD1 = LoadTextureFromImage(tempClydeD1);
    clydeD2 = LoadTextureFromImage(tempClydeD2);

    //inky
    inkyL1 = LoadTextureFromImage(tempInkyL1);
    inkyL2 = LoadTextureFromImage(tempInkyL2);
    inkyR1 = LoadTextureFromImage(tempInkyR1);
    inkyR2 = LoadTextureFromImage(tempInkyR2);
    inkyU1 = LoadTextureFromImage(tempInkyU1);
    inkyU2 = LoadTextureFromImage(tempInkyU2);
    inkyD1 = LoadTextureFromImage(tempInkyD1);
    inkyD2 = LoadTextureFromImage(tempInkyD2);

    //pinky
    pinkyL1 = LoadTextureFromImage(tempPinkyL1);
    pinkyL2 = LoadTextureFromImage(tempPinkyL2);
    pinkyR1 = LoadTextureFromImage(tempPinkyR1);
    pinkyR2 = LoadTextureFromImage(tempPinkyR2);
    pinkyU1 = LoadTextureFromImage(tempPinkyU1);
    pinkyU2 = LoadTextureFromImage(tempPinkyU2);
    pinkyD1 = LoadTextureFromImage(tempPinkyD1);
    pinkyD2 = LoadTextureFromImage(tempPinkyD2);

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
    if(blinkyFrameCounter >= 5)
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

bool usingClydeL1 = true;

void drawClyde()
{
    clydeFrameCounter++;
    Texture2D clydeLeft = clydeL1;
    Texture2D clydeRight = clydeR1;
    Texture2D clydeUp = clydeU1;
    Texture2D clydeDown = clydeD1;

    //swapping between clyde left sprites
    if(clydeFrameCounter >= 5)
    {
        if(usingClydeL1)
        {
            clydeLeft = clydeL2;
            clydeRight = clydeR2;
            clydeUp = clydeU2;
            clydeDown = clydeD2;

            usingClydeL1 = false;
        }
        else {
            clydeLeft = clydeL1;
            clydeRight = clydeR1;
            clydeUp = clydeU1;
            clydeDown = clydeD1;

            usingClydeL1 = true;
        }
        clydeFrameCounter = 0;
    }

    if(clydeDir == LEFT)
        DrawTexture(clydeLeft, clydeX+4 , clydeY+4 ,WHITE);
    if(clydeDir == RIGHT)
        DrawTexture(clydeRight, clydeX+4 , clydeY+4 ,WHITE);
    if(clydeDir == UP)
        DrawTexture(clydeUp, clydeX+4 , clydeY+4 ,WHITE);
    if(clydeDir == DOWN)
        DrawTexture(clydeDown, clydeX+4 , clydeY+4 ,WHITE);

}

bool usingInkyL1 = true;

void drawInky() {
    inkyFrameCounter++;
    Texture2D inkyLeft = inkyL1;
    Texture2D inkyRight = inkyR1;
    Texture2D inkyUp = inkyU1;
    Texture2D inkyDown = inkyD1;

    //swapping between inky left sprites
    if (inkyFrameCounter >= 5) {
        if (usingInkyL1) {
            inkyLeft = inkyL2;
            inkyRight = inkyR2;
            inkyUp = inkyU2;
            inkyDown = inkyD2;

            usingInkyL1 = false;
        } else {
            inkyLeft = inkyL1;
            inkyRight = inkyR1;
            inkyUp = inkyU1;
            inkyDown = inkyD1;

            usingInkyL1 = true;
        }
        inkyFrameCounter = 0;
    }

    if(inkyDir == LEFT)
        DrawTexture(inkyLeft, inkyX+4 , inkyY+4 ,WHITE);
    if(inkyDir == RIGHT)
        DrawTexture(inkyRight, inkyX+4 , inkyY+4 ,WHITE);
    if(inkyDir == UP)
        DrawTexture(inkyUp, inkyX+4 , inkyY+4 ,WHITE);
    if(inkyDir == DOWN)
        DrawTexture(inkyDown, inkyX+4 , inkyY+4 ,WHITE);
}

bool usingPinkyL1 = true;

void drawPinky()
{
    pinkyFrameCounter++;
    Texture2D pinkyLeft = pinkyL1;
    Texture2D pinkyRight = pinkyR1;
    Texture2D pinkyUp = pinkyU1;
    Texture2D pinkyDown = pinkyD1;

    //swapping between pinky left sprites
    if(pinkyFrameCounter >= 5)
    {
        if(usingPinkyL1)
        {
            pinkyLeft = pinkyL2;
            pinkyRight = pinkyR2;
            pinkyUp = pinkyU2;
            pinkyDown = pinkyD2;

            usingPinkyL1 = false;
        }
        else {
            pinkyLeft = pinkyL1;
            pinkyRight = pinkyR1;
            pinkyUp = pinkyU1;
            pinkyDown = pinkyD1;

            usingPinkyL1 = true;
        }
        pinkyFrameCounter = 0;
    }

    if(pinkyDir == LEFT)
        DrawTexture(pinkyLeft, pinkyX+4 , pinkyY+4 ,WHITE);
    if(pinkyDir == RIGHT)
        DrawTexture(pinkyRight, pinkyX+4 , pinkyY+4 ,WHITE);
    if(pinkyDir == UP)
        DrawTexture(pinkyUp, pinkyX+4 , pinkyY+4 ,WHITE);
    if(pinkyDir == DOWN)
        DrawTexture(pinkyDown, pinkyX+4 , pinkyY+4 ,WHITE);
}

void drawGhosts()
{
    //offset by 4 to centre the ghosts
    if(!poweredUp)
    {
        drawBlinky();
        drawClyde();
        drawInky();
        drawPinky();
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