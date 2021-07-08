#include <raylib.h>
#include "mapGenerator.h"
#include "audio.h"
#include "logic.h"
#include "draw.h"
#include "ai.h"

void gameLoop(int sizeOfWallArray);

int main()
{
    float volume = 0.0f;
    InitWindow(700, 700, "Pacman");
    SetTargetFPS(60);
    loadTextures();
    sizeOfWallArray = loadMap();
    SetWindowSize(map.width, map.height);
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
        UpdateMusicStream(siren1);
        UpdateMusicStream(siren2);
        updateLogic(&pacX, &pacY);
        updateAi();
        
        BeginDrawing();
        ClearBackground(BLACK);
        generateMapFromImage();
        draw(pacX, pacY);
        DrawFPS(20,20);

        EndDrawing();
    }
    CloseAudioDevice();
}