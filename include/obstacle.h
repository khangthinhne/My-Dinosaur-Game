#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "raylib.h"
class OBSTACLE{
    public:
    OBSTACLE();
    ~OBSTACLE();

    void draw();
    void update();
    void reset();
    Rectangle GetRec();

    private:
    Texture2D image;
    Vector2 position;
    int speed;
};

#endif 