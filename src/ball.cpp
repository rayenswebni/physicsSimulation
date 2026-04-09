#include "ball.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
 
Ball::Ball(Vector2 position, Vector2 velocity, float radius, Color color) {
     this->position = position;
     this->velocity = velocity;
     this->radius = radius;
     this->mass = radius*radius;
     this->color = color;
 }
 
float Ball::getRadius() const{
    return radius;
}
 
Vector2 Ball::getPosition() const{
    return position;
}
 
Vector2 Ball::getVelocity() const{
    return velocity;
}
 
Color Ball::getColor() const{
    return color;
}
 
void Ball::update(float dt, int w, int h){
    position.x += velocity.x * dt;
    position.y += velocity.y * dt;

    if(position.x -radius <= 0|| position.x + radius >= w){
        velocity.x = -velocity.x;
    }
    
    if(position.y -radius <= 0|| position.y + radius >= h){
        velocity.y = -velocity.y;
    }
    
}

void Ball::draw() const{
    DrawCircleV(position, radius, color);
}

inline float Dot(Vector2 a, Vector2 b) { return a.x*b.x + a.y*b.y; }


void Ball::ResolveCollision(Ball& a, Ball& b) {
    float dx   = b.position.x - a.position.x;
    float dy   = b.position.y - a.position.y;
    float dist = sqrtf(dx*dx + dy*dy);
    float minD = a.radius + b.radius;
    if (dist >= minD || dist < 1e-7f) return;
 
    Vector2 n = { dx/dist, dy/dist };
 
    // push apart proportional to inverse mass
    float overlap = minD - dist;
    float totalM  = a.mass + b.mass;
    a.position.x -= n.x * overlap * (b.mass / totalM);
    a.position.y -= n.y * overlap * (b.mass / totalM);
    b.position.x += n.x * overlap * (a.mass / totalM);
    b.position.y += n.y * overlap * (a.mass / totalM);
 
    Vector2 relVel = { b.velocity.x - a.velocity.x, b.velocity.y - a.velocity.y };
    float   vn     = Dot(relVel, n);
    if (vn > 0) return;
    float RESTITUTION = 0.97f;
 
    float imp = -(1.0f + RESTITUTION) * vn / totalM;
    a.velocity.x -= imp * b.mass * n.x;
    a.velocity.y -= imp * b.mass * n.y;
    b.velocity.x += imp * a.mass * n.x;
    b.velocity.y += imp * a.mass * n.y;
}
