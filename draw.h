#pragma once

#include "globals.h"

void drawGhosts();
void drawPauseMenu();
void drawHud();
void pacDeathAnimation();
void drawEyes();
void playStartSceneAnimation();

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

    //vulnerable ghosts
    Image tempBlueGhost1 = LoadImage("../assets/sprites/ghosts/vulnerable/blue1.png");
    Image tempBlueGhost2 = LoadImage("../assets/sprites/ghosts/vulnerable/blue2.png");
    Image tempWhiteGhost1 = LoadImage("../assets/sprites/ghosts/vulnerable/white1.png");
    Image tempWhiteGhost2 = LoadImage("../assets/sprites/ghosts/vulnerable/white2.png");

    ImageResize(&tempBlueGhost1,pinkyWidth,pinkyHeight); //resized to the size of any ghost since they are all the same size
    ImageResize(&tempBlueGhost2,pinkyWidth,pinkyHeight); //resized to the size of any ghost since they are all the same size
    ImageResize(&tempWhiteGhost1,pinkyWidth,pinkyHeight); //resized to the size of any ghost since they are all the same size
    ImageResize(&tempWhiteGhost2,pinkyWidth,pinkyHeight); //resized to the size of any ghost since they are all the same size

    blueGhost1 = LoadTextureFromImage(tempBlueGhost1);
    blueGhost2 = LoadTextureFromImage(tempBlueGhost2);
    whiteGhost1 = LoadTextureFromImage(tempWhiteGhost1);
    whiteGhost2 = LoadTextureFromImage(tempWhiteGhost2);

    //heart
    Image tempHeart = LoadImage("../assets/sprites/heart.png");
    ImageResize(&tempHeart, 40,40);
    heart = LoadTextureFromImage(tempHeart);

    //powerup
    Image tempPowerup = LoadImage("../assets/sprites/powerup.png");
    ImageResize(&tempPowerup, 21, 14);
    powerup = LoadTextureFromImage(tempPowerup);

    //pacman
    Image tempPacWideRight = LoadImage("../assets/sprites/pac/pacWide2.png");
    Image tempPacNarrowRight = LoadImage("../assets/sprites/pac/pacNarrow2.png");
    Image tempPacClosed = LoadImage("../assets/sprites/pac/pacClosed.png");

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

    ImageResize(&tempPacClosed, pacWidth, pacHeight);
    pacClosed = LoadTextureFromImage(tempPacClosed);

    //pacman death sprites
    Image tempDeath1 = LoadImage("../assets/sprites/pac/deathAnim/death1.png");
    Image tempDeath2 = LoadImage("../assets/sprites/pac/deathAnim/death2.png");
    Image tempDeath3 = LoadImage("../assets/sprites/pac/deathAnim/death3.png");
    Image tempDeath4 = LoadImage("../assets/sprites/pac/deathAnim/death4.png");
    Image tempDeath5 = LoadImage("../assets/sprites/pac/deathAnim/death5.png");
    Image tempDeath6 = LoadImage("../assets/sprites/pac/deathAnim/death6.png");
    Image tempDeath7 = LoadImage("../assets/sprites/pac/deathAnim/death7.png");
    Image tempDeath8 = LoadImage("../assets/sprites/pac/deathAnim/death8.png");
    Image tempDeath9 = LoadImage("../assets/sprites/pac/deathAnim/death9.png");
    Image tempDeath10 = LoadImage("../assets/sprites/pac/deathAnim/death10.png");
    Image tempDeath11 = LoadImage("../assets/sprites/pac/deathAnim/death11.png");

    ImageResize(&tempDeath1, pacWidth, pacHeight);
    ImageResize(&tempDeath2, pacWidth, pacHeight);
    ImageResize(&tempDeath3, pacWidth, pacHeight);
    ImageResize(&tempDeath4, pacWidth, pacHeight);
    ImageResize(&tempDeath5, pacWidth, pacHeight);
    ImageResize(&tempDeath6, pacWidth, pacHeight);
    ImageResize(&tempDeath7, pacWidth, pacHeight);
    ImageResize(&tempDeath8, pacWidth, pacHeight);
    ImageResize(&tempDeath9, pacWidth, pacHeight);
    ImageResize(&tempDeath10, pacWidth, pacHeight);
    ImageResize(&tempDeath11, pacWidth, pacHeight);

    pacDeath1 = LoadTextureFromImage(tempDeath1);
    pacDeath2 = LoadTextureFromImage(tempDeath2);
    pacDeath3 = LoadTextureFromImage(tempDeath3);
    pacDeath4 = LoadTextureFromImage(tempDeath4);
    pacDeath5 = LoadTextureFromImage(tempDeath5);
    pacDeath6 = LoadTextureFromImage(tempDeath6);
    pacDeath7 = LoadTextureFromImage(tempDeath7);
    pacDeath8 = LoadTextureFromImage(tempDeath8);
    pacDeath9 = LoadTextureFromImage(tempDeath9);
    pacDeath10 = LoadTextureFromImage(tempDeath10);
    pacDeath11 = LoadTextureFromImage(tempDeath11);

    Image tempFont200 = LoadImage("../assets/fonts/200.png");
    ImageResize(&tempFont200, 20, 10);
    font200 = LoadTextureFromImage(tempFont200);

    //eyes
    Image tempEyesLeft = LoadImage("../assets/sprites/ghosts/eyes/leftEyes.png");
    Image tempEyesRight = LoadImage("../assets/sprites/ghosts/eyes/rightEyes.png");
    Image tempEyesUp = LoadImage("../assets/sprites/ghosts/eyes/upEyes.png");
    Image tempEyesDown = LoadImage("../assets/sprites/ghosts/eyes/downEyes.png");

    ImageResize(&tempEyesLeft, blinkyWidth, blinkyHeight);
    ImageResize(&tempEyesRight, blinkyWidth, blinkyHeight);
    ImageResize(&tempEyesUp, blinkyWidth, blinkyHeight);
    ImageResize(&tempEyesDown, blinkyWidth, blinkyHeight);

    eyesLeft = LoadTextureFromImage(tempEyesLeft);
    eyesRight = LoadTextureFromImage(tempEyesRight);
    eyesUp = LoadTextureFromImage(tempEyesUp);
    eyesDown = LoadTextureFromImage(tempEyesDown);
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
    double menuX = windowWidth * 0.1;
    double menuY = windowHeight * 0.3;
    double menuWidth = windowWidth * 0.8;
    double menuHeight = windowHeight * 0.3;

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
    int scoreX = 10, scoreY = map.height + 10;
    DrawText(TextFormat("Score: %i", score), scoreX, scoreY, 20, WHITE);

    int highScoreX = 160, highScoreY = map.height + 10;
    DrawText(TextFormat("High Score: %i", highScore), highScoreX, highScoreY, 20, WHITE);

    double heartX = map.width - 75, heartY = map.height - 4;
    DrawTexture(heart, heartX, heartY, WHITE);
    DrawText(TextFormat("x%i", lives), heartX+35, heartY+15, 20, WHITE);
}

void drawGameOverScreen()
{
    double menuX = windowWidth * 0.1;
    double menuY = windowHeight * 0.3;
    double menuWidth = windowWidth * 0.8;
    double menuHeight = windowHeight * 0.3;
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

void drawPacMan()
{
    if(!drawPac)
        return;

    if(dir == LEFT)          {pacWide = pacWideLeft;     pacNarrow = pacNarrowLeft;}
    else if(dir == RIGHT)    {pacWide = pacWideRight;    pacNarrow = pacNarrowRight;}
    else if(dir == UP)       {pacWide = pacWideUp;       pacNarrow = pacNarrowUp;}
    else if(dir == DOWN)     {pacWide = pacWideDown;     pacNarrow = pacNarrowDown;}

    else if(dir == STOP)     {pacWide = pacClosed;       pacNarrow = pacClosed;}

    if(drawWide && !dead)
    {
        DrawTexture(pacWide, pacX ,pacY ,WHITE);
        animCounter++;
    }
    else if(drawNarrow && !dead)
    {
        DrawTexture(pacNarrow, pacX ,pacY ,WHITE);
        animCounter++;
    }
    else if(drawClosed && !dead)
    {
        DrawTexture(pacClosed, pacX ,pacY ,WHITE);
        animCounter++;
    }
    else if(drawNarrow2 && !dead)
    {
        DrawTexture(pacNarrow, pacX ,pacY ,WHITE);
        animCounter++;
    }

    //alternates drawWide and drawNarrow flags
    if(animCounter >= animMax && paused == false && dir != STOP)
    {
        if(drawWide)
        {
            drawWide = false;
            drawNarrow = true;
        }
        else if(drawNarrow)
        {
            drawNarrow = false;
            drawClosed = true;
        }
        else if(drawClosed)
        {
            drawNarrow2 = true;
            drawClosed = false;
        }
        else if(drawNarrow2)
        {
            drawNarrow2 = false;
            drawWide = true;
        }
        animCounter = 0;
    }
}

void drawPowerups()
{
    static int flashLength = 40;
    static int flashCounter = 0;
    static bool flash = false;
    for(int i = 0; i < numPowerups; i++)
        if(showPowerUp[i]) {
            if (frame % 30 == 0 || flash) {

                flash = true;

                //DrawTexture(powerup, powerUpX[i] - powerup.width / 2 + 1, powerUpY[i] - powerup.height / 2,CLITERAL(Color) {255, 255, 255, 255});
                if (flash && flashCounter <= flashLength) {
                    DrawCircle(powerUpX[i], powerUpY[i], 7, WHITE);
                    flashCounter++;
                }
                if (flashCounter > flashLength) {
                    flash = false;
                    flashCounter = 0;
                }
            }
        }
}

void drawStartMenu()
{
    double menuX = windowWidth * 0.05;
    double menuY = windowHeight * 0.15;
    double menuWidth = windowWidth * 0.9;
    double menuHeight = windowHeight * 0.7;

    //DrawRectangle((int)menuX, (int)menuY, (int)menuWidth, (int)menuHeight, (Color){41,37,39,235});
    Rectangle rec;
    rec.x = menuX;
    rec.y = menuY;
    rec.width = menuWidth;
    rec.height = menuHeight;

    DrawRectangleRounded(rec, 0.5f, 1, (Color){51,0,51,255});
    DrawText("Pacman Needs Help ", (int)menuX + (menuWidth*0.12), (int)menuY + (menuHeight*0.15), 30, WHITE);
    DrawText("Slapping the Ghosts!", (int)menuX + (menuWidth*0.12), (int)menuY + (menuHeight*0.25), 30, WHITE);
    DrawText("Press Space to Help Pacman", (int)menuX + (menuWidth*0.04), (int)menuY + (menuHeight*0.45), 20, WHITE);
    DrawText("Press P to Pause", (int)menuX + (menuWidth*0.04), (int)menuY + (menuHeight*0.55), 20, WHITE);
    DrawText("Press Esc to Ditch Pacman", (int)menuX + (menuWidth*0.04), (int)menuY + (menuHeight*0.65), 20, WHITE);
    DrawText("Use the Arrow Keys to Move", (int)menuX + (menuWidth*0.04), (int)menuY + (menuHeight*0.75), 20, WHITE);
}

void draw(int pacX, int pacY)
{
    if(lives <= 0) {
        drawGameOverScreen();
        return;
    }

    if(startMenu)
    {
        drawMap();
        drawStartMenu();
        if(playStartScene)
            playStartSceneAnimation();
        return;

    }

    drawMap();
    drawPacMan();
    drawPowerups();

    if(blinkyEaten || clydeEaten || pinkyEaten || inkyEaten)
        drawEyes();

    DrawRectangle(ghostWallX,ghostWallY, 37, 4, CLITERAL(Color){ 255, 203, 164, 255 }); 

    if(!dead)
        drawGhosts();

    drawHud();

    if(paused)
        drawPauseMenu();

    if(dead)
        pacDeathAnimation();
};

bool usingBlinkyL1 = true;
void drawBlinky()
{
    if(!showBlinky)
        return;

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
    if(blinkyDir == STOP)
        DrawTexture(blinkyUp, blinkyX+4 , blinkyY+4 ,WHITE);
}

bool usingClydeL1 = true;
void drawClyde()
{
    if(!showClyde)
        return;

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
    if(clydeDir == STOP)
        DrawTexture(clydeUp, clydeX+4 , clydeY+4 ,WHITE);
}

bool usingInkyL1 = true;
void drawInky()
{
    if(!showInky)
        return;

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
    if(inkyDir == STOP)
        DrawTexture(inkyUp, inkyX+4 , inkyY+4 ,WHITE);
}

bool usingPinkyL1 = true;
void drawPinky()
{
    if(!showPinky)
        return;

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
    if(pinkyDir == STOP)
        DrawTexture(pinkyUp, pinkyX+4 , pinkyY+4 ,WHITE);
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
        static Texture2D blueGhost;

        static bool usingBlueSprite1 = true;
        static bool usingWhiteSprite1 = true;
        static bool showingWhite = false;
        static int vulnerableFrameCounter = 0;
        static int vulnerableFrameLimit = 5;
        static int blinkLength = 10;
        static int blinkCounter = 0;
        //swapping sprites
        vulnerableFrameCounter++;
        if(vulnerableFrameCounter > vulnerableFrameLimit)
        {
            if(showingWhite == false)
            {
                if (usingBlueSprite1 == true) {
                    blueGhost = blueGhost2;
                    usingBlueSprite1 = false;
                } else {
                    blueGhost = blueGhost1;
                    usingBlueSprite1 = true;
                }
            }
            if(showingWhite == true)
            {
                if (usingWhiteSprite1 == true) {
                    blueGhost = whiteGhost2;
                    usingWhiteSprite1 = false;
                }
                else
                {
                    blueGhost = whiteGhost1;
                    usingWhiteSprite1 = true;
                }
            }
            vulnerableFrameCounter = 0;
        }

        if(poweredUpDuration >= 0.6*poweredUpMaxDuration)
        {
            blinkCounter++;
           if(blinkCounter > blinkLength)
           {
               //alternate Colour
               showingWhite = !showingWhite;
               blinkCounter = 0;
           }
        }

        if(showBlinky)
            DrawTexture(blueGhost, blinkyX+4 , blinkyY+4, WHITE);
        if(showClyde)
            DrawTexture(blueGhost, clydeX+4 , clydeY+4 ,WHITE);
        if(showInky)
            DrawTexture(blueGhost, inkyX+4 , inkyY+4 ,WHITE);
        if(showPinky)
            DrawTexture(blueGhost, pinkyX+4 , pinkyY+4 ,WHITE);

        if(poweredUpDuration >= poweredUpMaxDuration)
        {
            poweredUp = false;
            poweredUpDuration = 0;
        }

    }
}

void drawEyes()
{
    if(blinkyEaten)
    {
        if(eyesDir == LEFT)
        {
            DrawTexture(eyesLeft, blinkyX, blinkyY, WHITE);
        }
        else if(eyesDir == RIGHT)
        {
            DrawTexture(eyesRight, blinkyX, blinkyY, WHITE);
        }
        else if(eyesDir == UP)
        {
            DrawTexture(eyesUp, blinkyX, blinkyY, WHITE);
        }
        else if(eyesDir == DOWN)
        {
            DrawTexture(eyesDown, blinkyX, blinkyY, WHITE);
        }
    }
}

void pacDeathAnimation()
{
    if(deathFrameCounter <= 1*deathAnimMax)
    {
        DrawTexture(pacDeath1, pacX, pacY, WHITE);
        deathFrameCounter++;
        return;
    }
    if(deathFrameCounter <= 2*deathAnimMax)
    {
        DrawTexture(pacDeath2, pacX, pacY, WHITE);
        deathFrameCounter++;
        return;
    }
    if(deathFrameCounter <= 3*deathAnimMax)
    {
        DrawTexture(pacDeath3, pacX, pacY, WHITE);
        deathFrameCounter++;
        return;
    }
    if(deathFrameCounter <= 4*deathAnimMax)
    {
        DrawTexture(pacDeath4, pacX, pacY, WHITE);
        deathFrameCounter++;
        return;
    }
    if(deathFrameCounter <= 5*deathAnimMax)
    {
        DrawTexture(pacDeath5, pacX, pacY, WHITE);
        deathFrameCounter++;
        return;
    }
    if(deathFrameCounter <= 6*deathAnimMax)
    {
        DrawTexture(pacDeath6, pacX, pacY, WHITE);
        deathFrameCounter++;
        return;
    }
    if(deathFrameCounter <= 7*deathAnimMax)
    {
        DrawTexture(pacDeath7, pacX, pacY, WHITE);
        deathFrameCounter++;
        return;
    }
    if(deathFrameCounter <= 8*deathAnimMax)
    {
        DrawTexture(pacDeath8, pacX, pacY, WHITE);
        deathFrameCounter++;
        return;
    }
    if(deathFrameCounter <= 9*deathAnimMax)
    {
        DrawTexture(pacDeath9, pacX, pacY, WHITE);
        deathFrameCounter++;
        return;
    }
    if(deathFrameCounter <= 10*deathAnimMax)
    {
        DrawTexture(pacDeath10, pacX, pacY, WHITE);
        deathFrameCounter++;
        return;
    }
    if(deathFrameCounter <= 11*deathAnimMax)
    {
        DrawTexture(pacDeath11, pacX, pacY, WHITE);
        deathFrameCounter++;
        return;
    }
    if(deathFrameCounter > 20*deathAnimMax)
    {
        deathFrameCounter = 0;
        dead = false;
        pacX = 210;
        pacY = 265;
        dir = STOP;
        bufferDir = STOP;
        blinkyWait = 100;
        clydeWait = 400;
        inkyWait = 800;
        pinkyWait = 1200;
        resetGhostPositions();
        return;
    }
    else
        deathFrameCounter++;
}
void playStartSceneAnimation()
{
    double backgroundX = windowWidth * 0;
    double backgroundY = windowHeight * 0;
    double backgroundWidth = windowWidth * 1;
    double backgroundHeight = windowHeight * 1;

    Rectangle rec;
    rec.x = backgroundX;
    rec.y = backgroundY;
    rec.width = backgroundWidth;
    rec.height = backgroundHeight;

    if(pacX < windowWidth)
    {
        DrawRectangleRounded(rec, 0.0f, 1, (Color){0,0,0,255});
        dir = RIGHT;
        pacX+=2;
        pacY = 150;
        drawPacMan();
        blinkyY = pacY;
        blinkyX = pacX - 50;
        blinkyDir = RIGHT;
        drawBlinky();
        clydeY = pacY;
        clydeX = pacX - 100;
        clydeDir = RIGHT;
        drawClyde();
        inkyY = pacY;
        inkyX = pacX - 150;
        inkyDir = RIGHT;
        drawInky();
        pinkyY = pacY;
        pinkyX = pacX - 200;
        pinkyDir = RIGHT;
        drawPinky();
    }

    else{
        startMenu = false;
        dir = STOP;
        blinkyDir = STOP;
        blinkyX = ghostStartX[0];
        blinkyY = ghostStartY[0];

        clydeDir = STOP;
        clydeX = ghostStartX[1];
        clydeY = ghostStartY[1];

        inkyDir = STOP;
        inkyX = ghostStartX[2];
        inkyY = ghostStartY[2];

        pinkyDir = STOP;
        pinkyX = ghostStartX[3];
        pinkyY = ghostStartY[3];

        pacX = 210;
        pacY = 265;
    }
}