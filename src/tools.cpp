#include "../include/tools.h"

namespace Tools {
    float dst(Vector2 vec1, Vector2 vec2) {
        return sqrt(pow(vec1.x - vec2.x, 2) + pow(vec1.y - vec2.y, 2));
    }
}