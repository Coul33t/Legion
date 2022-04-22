#include "../include/tools.h"

namespace Tools {
    double dst(Vector2 vec1, Vector2 vec2) {
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

    Vector4 get_true_rectangle_coordinates(int origin_x, int origin_y, int size_x, int size_y) {
        // x, y, w, z (h)
        Vector4 true_coordinates;

        true_coordinates.x = origin_x;
        true_coordinates.y = origin_y;
        true_coordinates.w = abs(size_x);
        true_coordinates.z = abs(size_y);


        if (size_x < 0) {
            true_coordinates.x = static_cast<float>(origin_x + size_x);
        }

        if (size_y < 0) {
            true_coordinates.y = static_cast<float>(origin_y + size_y);
        }

        return true_coordinates;
    }
}