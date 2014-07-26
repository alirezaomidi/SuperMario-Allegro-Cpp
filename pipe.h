#ifndef PIPE_H
#define PIPE_H

#include "gameobject.h"

class Pipe : public GameObject {
public:
    enum PipeType {Big, Medium, Small};
    Pipe(PipeType type, Position *pos);
    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();

private:
    PipeType type;
};

#endif // PIPE_H
