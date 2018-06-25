#include <iostream>
#include "surlparser.h"

int main() {
    SUrlParser p;
    p.parse("/user/1/profile?addr=zipcode&driverlicense=number&jobtype=farmer");

    for ( auto &f : p.paths() )
        std::cout << "path: " << f << std::endl;

    for ( auto &v : p.params() )
        std::cout << " - " << v.first << " = " << v.second << std::endl;

    return 0;
}

