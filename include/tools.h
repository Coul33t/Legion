#ifndef _TOOLS_H
#define _TOOLS_H

#include <iostream>

#include "raylib.h"

#include <math.h>
#include <stdint.h>

typedef unsigned int uint;

enum Shape {
    CIRCLE,
    ELLIPSE
};

struct mVec2f {
    float values[2];
    float& x = values[0];
    float& y = values[1];
    float& w = values[0];
    float& h = values[1];
};

struct Point {
    uint x, y;
};

struct Size {
    uint w, h;
};

namespace Tools {
    float dst(Vector2 vec1, Vector2 vec2);
    bool clicked_in(Vector2 mouse_pos, Shape shape, uint size, Vector2 coord);
    bool point_in_rectangle(Vector2 ori, Vector2 size, Vector2 pos);
}

#endif