#include "dino.h"

Dino::Dino(){
    Image resizedImage = LoadImage("D:\\Project\\MySnakeGame\\res\\dino.png");
    ImageResize(&resizedImage, 150, 170);
    image = LoadTextureFromImage(resizedImage);
    position.x = 550;
    position.y =  640 - 170;
    speed = 100;
    acceleration = -0.267f;
}

Dino::~Dino(){
    UnloadTexture(image);
}

void Dino::Draw(){
    DrawTextureV(image, position, WHITE);
}

void Dino::Update(bool isJumping){
    if(isJumping){
        position.y -= getVelocity();
    }
    else { position.y = 640 -170; speed = 10;}
        
}

Rectangle Dino::GetRec(){
    return Rectangle{position.x , position.y , float(image.width) ,float(image.height)};
}

void Dino::DrawHitBox(){
    DrawRectangleLinesEx(Dino::GetRec(), 5, RED);
}

float Dino::getVelocity(){
    speed = speed + acceleration;
    return speed;
}

void Dino::reset(){
    position.y = 640 -170;
    speed = 10;
}