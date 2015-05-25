#include "application.hpp"
#include <vector>


int main()
{
    std::vector< std::vector< int> > v(40, std::vector<int>(40));
    jatekmester ez(v);
    ez.start();
    return 0;
}
