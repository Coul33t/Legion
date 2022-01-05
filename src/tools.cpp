#include "../include/tools.h"

namespace Tools {
    float dst(Vector2 vec1, Vector2 vec2) {
        return sqrt(pow(vec1.x - vec2.x, 2) + pow(vec1.y - vec2.y, 2));
    }

    bool clicked_in(Vector2 mouse_pos, Shape shape, uint size, Vector2 coord) {
        if (shape == Shape::CIRCLE) {
            return (dst(mouse_pos, coord) <= size);
        }
    }

    bool point_in_rectangle(Vector2 ori, Vector2 size, Vector2 pos) {
        return (pos.x > ori.x && 
                pos.x < ori.x + size.x &&
                pos.y > ori.y &&
                pos.y < ori.y + size.y);
    }
}