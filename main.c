#include <raylib.h>
#include "mapGenerator.h"
#include "audio.h"
#include "logic.h"
#include "draw.h"
#include "ai.h"
#include "save.h"

#define SCALE 1.0f
#define HUD_EXTENSION_LENGTH 35*SCALE
void gameLoop(int sizeOfWallArray);

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    float volume = 0.0f;
    InitWindow(windowWidth, windowHeight, "Pacman");
    SetTargetFPS(50);
    loadTextures();
    sizeOfWallArray = loadMap();
    pacX = 210;
    pacY = 265;
    SetWindowSize(map.width*SCALE, map.height*SCALE + HUD_EXTENSION_LENGTH);
    playAudio(volume);
    dir = STOP;
    bufferDir = STOP;

    initAi();
    getHighScoreFromFile(&highScore);
    gameLoop(sizeOfWallArray);

    return 0;
}

void gameLoop(int sizeOfWallArray)
{
    // Create a RenderTexture2D to be used for render to texture
    RenderTexture2D target = LoadRenderTexture(windowWidth, windowHeight + HUD_EXTENSION_LENGTH);
    RenderTexture2D targetFlipped = LoadRenderTexture(windowWidth, windowHeight + HUD_EXTENSION_LENGTH);
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        frame++;
        UpdateMusicStream(siren1);
        UpdateMusicStream(siren2);

        getInput();

        ClearBackground(BLACK);  // Clear texture background

        BeginTextureMode(target);       // Enable drawing to texture
           // ClearBackground(BLACK);  // Clear texture background
                BeginDrawing();
                    ClearBackground(BLACK);
                    if(!paused)
                        updateLogic(&pacX, &pacY);
                    draw(pacX, pacY);
                    DrawFPS(20,20);
                EndDrawing();
        EndTextureMode();

        Vector2 position;
        position.x = 0;
        position.y = 0;
        BeginTextureMode(targetFlipped);
            //ClearBackground(BLACK);
            DrawTexture(target.texture, 0,0,WHITE);
        EndTextureMode();

        DrawTextureEx(targetFlipped.texture, position, 0, SCALE, WHITE);

        //DrawTexturePro(target.texture, (Rectangle){(0, 0, target.texture.width, -target.texture.height)}, (Rectangle){(0, 0, target.texture.width, target.texture.height)}, position, 0, WHITE);
    }
    saveScoreToFile(score, highScore);
    CloseAudioDevice();
}