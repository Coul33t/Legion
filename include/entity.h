#ifndef _ENTITY_H
#define _ENTITY_H

#include "tools.h"

class Entity {
    public:
        Entity();
        Entity(float speed, uint size, Shape shape);

        bool move(Vector2 target);
        bool moveToTarget();

        Vector2 coordinates;
        Vector2 target;
        float speed;
        uint size;
        Shape shape;
        bool selected = false;
};

#endif