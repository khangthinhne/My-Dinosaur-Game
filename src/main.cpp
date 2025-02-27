#include "raylib.h"
#include <time.h>
#include <stdlib.h>
#include "dino.h"
#include "obstacle.h"

int cnt = 0;
int main(){
    srand(time(0));
    const int screenWidth = 1200;
    const int screenHeight = 800;
    
    InitWindow(screenWidth, screenHeight, "MyGamee");
    SetTargetFPS(60);

    OBSTACLE catus[100];
    Dino dino;
    int idx = 0;
    bool isColliding = CheckCollisionRecs(dino.GetRec(), catus[idx].GetRec());
    
    bool isJumping = false;
    while(!WindowShouldClose()){  

        if(isColliding == false){
            if(IsKeyDown(KEY_SPACE)){
                isJumping = true;
            }
            if (dino.GetRec().y + 170 > 640){
                isJumping = false;
            }
            dino.Update(isJumping);
            catus[idx].update();
            isColliding = CheckCollisionRecs(dino.GetRec(), catus[idx].GetRec());
        }

        BeginDrawing();
        ClearBackground(WHITE);
        DrawRectangle(0, 640, screenWidth, 200, BLACK);
        catus[idx].draw();
        dino.Draw();

        if(isColliding){
            DrawText("PRESS R TO PLAY AGAIN", 280, 300, 50, RED);
            if(IsKeyPressed(KEY_R)){
                isColliding = false;
                isJumping = false;
                dino.reset();
                catus[idx].reset();
                idx = 0;
            }
        }
        if(catus[idx].GetRec().x + catus[idx].GetRec().width <= 0){
            idx++;
        }
        if(isColliding) dino.DrawHitBox();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}