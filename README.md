# Simple Url Parser

The library parses URLs and extract of them the elements of path and params with values as shown:
```
http://example.com/user/1/profile?addr=zipcode&driverlicense=number&jobtype=farmer
                 [ <<             only this part should be passed              >> ]
The only params also can be passed without having path elements. See examples in the test.cpp.
```
Example of usage:
```c++
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
```
Output
```
path: user
path: 1
path: profile
 - jobtype = farmer
 - driverlicense = number
 - addr = zipcode
```
The passed URL must not be a complete URL, the only path and params are supported.

The library does not validate a validity of a passed URL, it just does its work.

## Examples of correct URL that can be passed

For more examples see the **test.cpp**.

## Support
It is written on C++ + STL library for GNU C++ compiler under Linux. Also other compilers and platforms should be supported.

## Distributing
Feel free to use any part of or entire code without any contributions.

## Supporting
Any imporovements are welcome.

