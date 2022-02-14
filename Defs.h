#pragma once

struct Vector2D  // Represents a 2D vector
{
    float vx = 0;  // The first coordinate
    float vy = 0;  // The second coordinate
    float px = 0;  // The first coordinate
    float py = 0;  // The second coordinate
    Vector2D operator*(float scale) { return Vector2D{vx * scale, vy * scale, px * scale, py * scale}; }  // Scalar multiplication
    Vector2D operator/(float scale) { return Vector2D{vx / scale, vy / scale, px / scale, py / scale}; }  // Scalar division
    Vector2D operator+(float scale) { return Vector2D{vx + scale, vy + scale, px + scale, py + scale}; }  // Scalar addition
    Vector2D operator-(float scale) { return Vector2D{vx - scale, vy - scale, px - scale, py - scale}; }  // Scalar subtraction
    Vector2D operator*(const Vector2D & v) { return Vector2D{vx * v.vx, vy * v.vy, px * v.px, py * v.py}; }  // Element-wise multiplication
    Vector2D operator/(const Vector2D & v) { return Vector2D{vx / v.vx, vy / v.vy, px / v.px, py / v.py}; }  // Element-wise division
    Vector2D operator+(const Vector2D & v) { return Vector2D{vx + v.vx, vy + v.vy, px + v.px, py + v.py}; }  // Element-wise addition
    Vector2D operator-(const Vector2D & v) { return Vector2D{vx - v.vx, vy - v.vy, px - v.px, py - v.py}; }  // Element-wise subtraction
    Vector2D& operator*=(const Vector2D& v) { vx *= v.vx; vy *= v.vy; px *= v.px; py *= v.py; return *this; }  // Element-wise multiplication
    Vector2D& operator/=(const Vector2D& v) { vx /= v.vx; vy /= v.vy; px /= v.px; py /= v.py; return *this; }  // Element-wise division
    Vector2D& operator+=(const Vector2D& v) { vx += v.vx; vy += v.vy; px += v.px; py += v.py; return *this; }  // Element-wise addition
    Vector2D& operator-=(const Vector2D& v) { vx -= v.vx; vy -= v.vy; px -= v.px; py -= v.py; return *this; }  // Element-wise subtraction
};

enum FlipperType { LEFT, RIGHT };

// Should be replaced by a config file!
#define GAME_WIDTH 700
#define GAME_HEIGHT 675
#define BALL_RADIUS 10
#define INITIAL_CENTER {0, 0, 150, 20}
#define INITIAL_VELOCITY {-500, 0, 0, 0}
#define status {-500, 0, 150, 20}
#define FLIPPER_MAJOR_RADIUS 10
#define FLIPPER_MINOR_RADIUS 5
#define FLIPPER_LENGTH 50
#define FLIPPERS_DISTANCE FLIPPER_LENGTH