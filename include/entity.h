#ifndef _ENTITY_H
#define _ENTITY_H

#include <iostream>
#include "tools.h"

class Entity {
    public:
        Entity();
        Entity(float m_speed, uint8_t size, Shape shape);
        void move(Vector2 target);
        
        float getX();
        float getY();
        uint8_t getSize();
        Vector2 getPosition();

    private:
        Vector2 m_coordinates;
        float m_speed;
        uint8_t m_size;
        Shape m_shape;
};

#endif