#ifndef CLOUD_H
#define CLOUD_H

#include "gameobject.h"

class Cloud : public GameObject {
public:
    enum CloudType {Big, Medium, Small};
    Cloud(CloudType type, Position *pos);
    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();

private:
    CloudType type;
};

#endif // CLOUD_H
