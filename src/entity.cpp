#include "../include/entity.h"

Entity::Entity() {
    m_coordinates.x = 10;
    m_coordinates.y = 10;
}

Entity::Entity(float speed, uint8_t size, Shape shape): m_speed(speed), m_size(size), m_shape(shape) {
    m_coordinates.x = 10;
    m_coordinates.y = 10;
}

float Entity::getX() {
    return m_coordinates.x;
}

float Entity::getY() {
    return m_coordinates.y;
}

uint8_t Entity::getSize() {
    return m_size;
}

Vector2 Entity::getPosition() {
    return m_coordinates;
}

void Entity::move(Vector2 target) {
    if (Tools::dst(m_coordinates, target) < 1)
        return;

    float a = atan2(target.y - m_coordinates.y, target.x - m_coordinates.x);

    m_coordinates.x = m_coordinates.x + m_speed * cos(a);
    m_coordinates.y = m_coordinates.y + m_speed * sin(a);
}