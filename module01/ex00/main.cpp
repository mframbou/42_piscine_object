#include "Worker.hpp"
#include "Tools.hpp"

int main() {
    Worker *worker = new Worker();
    Worker *worker2 = new Worker();

    worker->printTools();
    worker2->printTools();

    Tool *shovel = new Shovel();
    Tool *shovel2 = new Shovel();
    Tool *hammer = new Hammer();

    worker->giveTool(shovel);
    worker2->giveTool(hammer);
    
    worker->printTools();
    worker2->printTools();

    worker2->giveTool(shovel);
    worker2->giveTool(shovel2);

    worker->printTools();
    worker2->printTools();

    worker->removeTool(shovel);
    worker2->removeTool(shovel);
    worker2->removeTool(hammer); // should sill have shovel2

    worker->printTools();
    worker2->printTools();

    delete worker;
    delete shovel;
    delete shovel2;
    delete worker2;
    return 0;
}