#include <raylib.h>
#include "ball.h"
#include <vector>

int main() {
    std::vector<Ball> balls;
    balls.emplace_back(Vector2{120.0f, 120.0f}, Vector2{500.0f, 750.0f}, 30.0f, Color{255, 0, 0, 255});
    balls.emplace_back(Vector2{250.0f, 250.0f}, Vector2{500.0f, 750.0f}, 25.0f, Color{0, 255, 0, 255});
    balls.emplace_back(Vector2{500.0f, 500.0f}, Vector2{500.0f, 750.0f}, 35.0f, Color{0, 0, 255, 255});
    balls.emplace_back(Vector2{400.0f, 400.0f}, Vector2{500.0f, 750.0f}, 33.0f, Color{30, 140, 140, 255});
    balls.emplace_back(Vector2{300.0f, 300.0f}, Vector2{500.0f, 750.0f}, 52.0f, Color{255, 0, 255, 255});
    balls.emplace_back(Vector2{200.0f, 200.0f}, Vector2{500.0f, 750.0f}, 20.0f, Color{50, 50, 0, 255});
    balls.emplace_back(Vector2{700.0f, 700.0f}, Vector2{500.0f, 750.0f}, 25.0f, Color{0, 150, 120, 255});

const Color white = {255, 255, 255, 255};


    InitWindow(800,600,"bouncing ball !");
    SetTargetFPS(120);
    //loop
    while(!WindowShouldClose()){
        const float dt = GetFrameTime();
        const int w = GetScreenWidth();
        const int h = GetScreenHeight();

        for (Ball& ball : balls) {
            ball.update(dt, w, h);
        }

        for (int i = 0; i < static_cast<int>(balls.size()); i++) {
            for (int j = i + 1; j < static_cast<int>(balls.size()); j++) {
                Ball::ResolveCollision(balls[i], balls[j]);
            }
        }

        BeginDrawing();
        ClearBackground(white);
        DrawFPS(10, 10);
        for (const Ball& ball : balls) {
            ball.draw();
        }
        EndDrawing();
        
    }
    CloseWindow();
    return 0;
    
}