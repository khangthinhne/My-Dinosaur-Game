#ifndef DINO_H
#define DINO_H

#include "raylib.h"

class Dino {
public:
    Dino();
    ~Dino();

    void Draw();
    void Update(bool isJumping);
    Rectangle GetRec();
    void DrawHitBox();
    void reset();
    float getVelocity();
    float speed;
private:
    Texture2D image;
    Vector2 position;
    float acceleration;

};

#endif // DINO_H