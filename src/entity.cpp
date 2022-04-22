#include "../include/entity.h"

Entity::Entity() {
    coordinates = {10, 10};
    target = {0, 0};
    speed = 0.0;
    shape = Shape::CIRCLE;
    size = 1.0;
}

Entity::Entity(float speed, uint size, Shape shape): speed(speed), size(size), shape(shape) {
    coordinates = {10, 10};
    target = {0, 0};
}

Entity::Entity(float x, float y, float speed, uint size, Shape shape): speed(speed), size(size), shape(shape) {
    coordinates = {x, y};
    target = {0, 0};
}

bool Entity::move(Vector2 target_entity) {
    if (Tools::dst(coordinates, target_entity) < speed)
        return false;

    float a = atan2(target_entity.y - coordinates.y, target_entity.x - coordinates.x);

    coordinates.x = coordinates.x + speed * cos(a);
    coordinates.y = coordinates.y + speed * sin(a);

    return true;
}

bool Entity::moveToTarget() {
    return move(target);
}