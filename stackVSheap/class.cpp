#include <iostream>
#include <string.h>

class Entity
{
private:
    int x;

public:
    Entity(int _x, std::string msg)
    {
        x = _x;
        std::cout << "Entity Created using " << msg << " memory" << std::endl;
    }

    ~Entity()
    {
        std::cout << "Entity Destroyed" << std::endl;
    }
};

int main()
{
    {
        // stack allocation
        Entity e(5, "stack");
    }

    {
        // heap Allocation
        Entity *e = new Entity(5, "Heap");
        delete e;
    }
    std::cin.get();
}