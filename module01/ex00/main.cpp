#include "Worker.hpp"
#include "Tools.hpp"
#include "Workshop.hpp"


int main() {
    {
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
    delete worker2;
    delete shovel;
    delete shovel2;
    delete hammer;
    }
    std::cout << std::endl << "-------------------------------" << std::endl << std::endl;
    {
    Workshop workshop = Workshop();
    Workshop workshop2 = Workshop();

    Worker *worker3 = new Worker();
    Worker *worker4 = new Worker();
    Worker *worker5 = new Worker();

    Tool *shovel3 = new Shovel();
    Tool *shovel4 = new Shovel();
    Tool *hammer2 = new Hammer();

    worker3->giveTool(shovel3);
    worker4->giveTool(shovel4);
    worker5->giveTool(hammer2);


    workshop.registerWorker<Shovel>(worker3);
    workshop.registerWorker<Shovel>(worker4);
    workshop2.registerWorker<Hammer>(worker4);
    workshop2.registerWorker<Shovel>(worker4);
    workshop2.registerWorker<Shovel>(worker4);
    workshop2.registerWorker<Hammer>(worker5);

    worker3->printTools();
    worker4->printTools();
    worker5->printTools();
    
    workshop.printWorkers();
    workshop2.printWorkers();

    worker3->work();
    worker4->work();
    worker5->work();

    workshop.unregisterWorker(worker3);

    delete worker3;
    delete worker4;
    delete worker5;
    delete shovel3;
    delete shovel4;
    delete hammer2;
    }
    std::cout << std::endl << "-------------------------------" << std::endl << std::endl;
    {
    Worker *worker = new Worker();
    Worker *worker2 = new Worker();

    Tool *shovel = new Shovel();
    Tool *shovel2 = new Shovel();
    Tool *hammer = new Hammer();
    Tool *hammer2 = new Hammer();

    worker->giveTool(shovel);
    worker->giveTool(shovel2);
    worker->giveTool(hammer);

    worker2->giveTool(hammer2);

    worker->printTools();
    worker2->printTools();

    std::cout << "getTool(Shovel) = " << worker->getTool<Shovel>() << std::endl;
    std::cout << "getTool(Hammer) = " << worker->getTool<Hammer>() << std::endl;
    std::cout << "getTool(Shovel) = " << worker2->getTool<Shovel>() << std::endl;
    std::cout << "getTool(Hammer) = " << worker2->getTool<Hammer>() << std::endl;

    delete worker;
    delete worker2;
    delete shovel;
    delete shovel2;
    delete hammer;
    delete hammer2;
    }
    return 0;
}