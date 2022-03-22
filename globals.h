#pragma once

#include <raylib.h>

enum eDirection{LEFT,RIGHT,UP,DOWN,STOP};
enum eDirection dir;
enum eDirection eyesDir;

int windowWidth = 700, windowHeight = 700;

//sound
Music start;
Sound credit;
Sound munch1;
Sound munch2;

Music siren1;
Music siren2;
Sound siren3;
Sound siren4;
Sound siren5;

//pacman
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

//pacman deaths
Texture2D pacDeath1;
Texture2D pacDeath2;
Texture2D pacDeath3;
Texture2D pacDeath4;
Texture2D pacDeath5;
Texture2D pacDeath6;
Texture2D pacDeath7;
Texture2D pacDeath8;
Texture2D pacDeath9;
Texture2D pacDeath10;
Texture2D pacDeath11;

//blinky
Texture2D blinkyL1;
Texture2D blinkyL2;
Texture2D blinkyR1;
Texture2D blinkyR2;
Texture2D blinkyU1;
Texture2D blinkyU2;
Texture2D blinkyD1;
Texture2D blinkyD2;

//clyde
Texture2D clydeL1;
Texture2D clydeL2;
Texture2D clydeR1;
Texture2D clydeR2;
Texture2D clydeU1;
Texture2D clydeU2;
Texture2D clydeD1;
Texture2D clydeD2;

//inky
Texture2D inkyL1;
Texture2D inkyL2;
Texture2D inkyR1;
Texture2D inkyR2;
Texture2D inkyU1;
Texture2D inkyU2;
Texture2D inkyD1;
Texture2D inkyD2;

//pinky
Texture2D pinkyL1;
Texture2D pinkyL2;
Texture2D pinkyR1;
Texture2D pinkyR2;
Texture2D pinkyU1;
Texture2D pinkyU2;
Texture2D pinkyD1;
Texture2D pinkyD2;

Texture2D blueGhost1;
Texture2D blueGhost2;
Texture2D whiteGhost1;
Texture2D whiteGhost2;

Texture2D powerup;
Texture2D heart;
Texture2D font200;

Texture2D eyesLeft;
Texture2D eyesRight;
Texture2D eyesUp;
Texture2D eyesDown;

bool updateAiMovement = true;

int blinkyFrameCounter = 0;
int clydeFrameCounter = 0;
int inkyFrameCounter = 0;
int pinkyFrameCounter = 0;

long long int frame = 0;

bool paused = false;

//pacman animation
bool drawPac = true;
int animCounter = 0;
const int animMax = 5;
bool drawWide = true;
bool drawNarrow = false;

//pacman death animation
int deathFrameCounter = 0;
const int deathAnimMax = 8;
bool dead = false;

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

enum eDirection blinkyDir;
enum eDirection clydeDir;
enum eDirection inkyDir;
enum eDirection pinkyDir;

bool showBlinky = true;
bool showClyde = true;
bool showInky = true;
bool showPinky = true;

int blinkyWait = 100;
int clydeWait = 400;
int inkyWait = 800;
int pinkyWait = 1200;

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

//powerups
bool poweredUp = false;
int poweredUpDuration = 0;
int poweredUpMaxDuration = 350;

int lives = 3;
bool collided = false;
