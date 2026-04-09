#pragma once
#include "raylib.h"

class Ball{
    private:
        Vector2 position;
        Vector2 velocity;
        float radius;
        float mass;
        Color color;
    public:
      Ball(Vector2 position, Vector2 velocity, float radius, Color color);
    void update(float dt, int w, int h);
    static void ResolveCollision(Ball& a, Ball& b);
    void draw() const;
    float getRadius() const;
    Vector2 getPosition() const;
    Vector2 getVelocity() const;
    Color getColor() const;
};  