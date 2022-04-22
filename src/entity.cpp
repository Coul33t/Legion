#include "../include/entity.h"

Entity::Entity() {
    coordinates.x = 10;
    coordinates.y = 10;
}

Entity::Entity(float speed, uint size, Shape shape): speed(speed), size(size), shape(shape) {
    coordinates.x = 10;
    coordinates.y = 10;
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