#pragma once

#include <raylib.h>

enum eDirection{LEFT,RIGHT,UP,DOWN,STOP};
enum eDirection dir;

Texture2D pacWide;
Texture2D pacNarrow;

Texture2D pacWideUp;
Texture2D pacNarrowUp;
Texture2D pacWideDown;
Texture2D pacNarrowDown;
Texture2D pacWideLeft;
Texture2D pacNarrowLeft;
Texture2D pacWideRight;
Texture2D pacNarrowRight;
Texture2D pacClosed;

Texture2D blinky;
Texture2D clyde;
Texture2D inky;
Texture2D pinky;
Texture2D blueGhost;

Texture2D powerup;
Texture2D heart;

bool paused = false;

int windowWidth = 700, windowHeight = 700;

int animCounter = 0;
const int animMax = 4;
bool drawWide = true;
bool drawNarrow = false;

Image map;
Color* pixels;
int* wallsX;
int* wallsY;
int* visibleWallsX;
int* visibleWallsY;
int* foodsX;
int* foodsY;
bool* showFood;
int* powerUpX;
int* powerUpY;
bool* showPowerUp;
int pacX = 65, pacY = 13;

int sizeOfFoodArray;
int sizeOfWallArray;
int sizeOfVisibleWallArray;
int numPowerups = 0;
int score = 0;

Music start;
Sound credit;
Sound munch1;
Sound munch2;

Music siren1;
Music siren2;
Sound siren3;
Sound siren4;
Sound siren5;

int pacWidth = 31;
int pacHeight = 31;

int* ghostStartX;
int* ghostStartY;

int blinkyX;
int blinkyY;
int blinkyWidth = 24;
int blinkyHeight = 24;

int clydeX;
int clydeY;
int clydeWidth = 24;
int clydeHeight = 24;

int inkyX;
int inkyY;
int inkyWidth = 24;
int inkyHeight = 24;

int pinkyX;
int pinkyY;
int pinkyWidth = 24;
int pinkyHeight = 24;

int blinkyTimeInSpawn;
int clydeTimeInSpawn;
int inkyTimeInSpawn;
int pinkyTimeInSpawn;

int blinkyEaten = false;
int clydeEaten = false;
int inkyEaten = false;
int pinkyEaten = false;

int maxTimeInSpawn = 250;


bool blinkyCrossedWall = false;
bool clydeCrossedWall = false;
bool inkyCrossedWall = false;
bool pinkyCrossedWall = false;

int ghostWallX;
int ghostWallY;

bool poweredUp = false;
int poweredUpDuration = 0;
int poweredUpMaxDuration = 350;

int lives = 3;
bool collided = false;
