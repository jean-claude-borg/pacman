#include <raylib.h>
#include "mapGenerator.h"
#include "audio.h"
#include "logic.h"
#include "draw.h"
#include "ai.h"

#define HUD_EXTENSION_LENGTH 30

void gameLoop(int sizeOfWallArray);

int main()
{
    //SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    float volume = 0.0f;
    InitWindow(windowWidth, windowHeight, "Pacman");
    SetTargetFPS(50);
    loadTextures();
    sizeOfWallArray = loadMap();
    pacX = 213;
    pacY = 270;
    SetWindowSize(map.width, map.height + HUD_EXTENSION_LENGTH);
    playAudio(volume);
    dir = STOP;

    initAi();
    gameLoop(sizeOfWallArray);    

    return 0;
}

void gameLoop(int sizeOfWallArray)
{
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        frame++;
        UpdateMusicStream(siren1);
        UpdateMusicStream(siren2);

        getInput();
        if(!paused)
        {
            updateLogic(&pacX, &pacY);
            updateAi();
        }

        BeginDrawing();
        ClearBackground(BLACK);
        draw(pacX, pacY);
        DrawFPS(20,20);

        //printf("X: %d, Y: %d\n", pacX, pacY);

        EndDrawing();
    }
    CloseAudioDevice();
}