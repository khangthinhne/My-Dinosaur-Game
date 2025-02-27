#include "obstacle.h"
#include "raylib.h"

OBSTACLE::OBSTACLE(){
    Image resizedImage = LoadImage("D:\\Project\\MySnakeGame\\res\\catus.png");
    ImageResize(&resizedImage, 100, 160);
    image = LoadTextureFromImage(resizedImage);
    speed = 10;
    position.x = 1200;
    position.y = 500;
}

OBSTACLE::~OBSTACLE(){
    UnloadTexture(image);
}

void OBSTACLE::draw(){
    DrawTextureV(image, position, WHITE);
}

void OBSTACLE::update(){
    position.x -= speed;
}

Rectangle OBSTACLE::GetRec(){
    return Rectangle{position.x, position.y, float(image.width), float(image.height)};
}

void OBSTACLE::reset(){
    position.x = 1200;
}