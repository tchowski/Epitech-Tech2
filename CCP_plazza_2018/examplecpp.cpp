// thread example
#include <iostream> // std::cout
#include <thread> // std::thread
#include <functional>

void foo()
{
    // do stuff...
}

void bar(int &x)
{
    std::cout << "print: " << x << std::endl;
    // do stuff...
}

int main()
{
    int test = 3;
    std::thread first(foo); // spawn new thread that calls foo()
    std::thread second(bar, std::ref(test)); // spawn new thread that calls bar(0)

    std::cout << "main, foo and bar now execute concurrently...\n";

    // synchronize threads:
    first.join(); // pauses until first finishes
    second.join(); // pauses until second finishes

    std::cout << "foo and bar completed.\n";

    return 0;
}