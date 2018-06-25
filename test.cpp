#include <string>
#include <cassert>
#include "surlparser.h"

using namespace std;

int main(int argc, char **argv) {

    SUrlParser m;

    if ( argc > 1 ) {
        m.parse(argv[1]);
        m.print();
        return 0;
    }

    m.parse("/one/two/three");
    assert( m.paths().size() == 3 && m.params().size() == 0 );
    m.parse("//one/two/three");
    assert( m.paths().size() == 3 && m.params().size() == 0 );
    m.parse("//one//two/three");
    assert( m.paths().size() == 3 && m.params().size() == 0 );
    m.parse("//one//two//three/four////five/six");
    assert( m.paths().size() == 6 && m.params().size() == 0 );
    m.parse("//one//two//three/four////five/six/");
    assert( m.paths().size() == 6 && m.params().size() == 0 );
    m.parse("//one//two//three/four////five/six////seven///////");
    assert( m.paths().size() == 7 && m.params().size() == 0 );


    m.parse("/one/two?");
    assert( m.paths().size() == 2 && m.params().size() == 0 );
    m.parse("/one/two//?");
    assert( m.paths().size() == 2 && m.params().size() == 0 );
    m.parse("/one/two////?");
    assert( m.paths().size() == 2 && m.params().size() == 0 );

    m.parse("/one/two?arg");
    assert( m.paths().size() == 2 && m.params().size() == 1 );
    m.parse("/one/two//?arg=10");
    assert( m.paths().size() == 2 && m.params().size() == 1 );
    m.parse("/one/two//?arg=10=");
    assert( m.paths().size() == 2 && m.params().size() == 1 );
    m.parse("/one/two//?arg=====");
    assert( m.paths().size() == 2 && m.params().size() == 1 );
    m.parse("//////one/////two//////?arg=10%323sdfs");
    assert( m.paths().size() == 2 && m.params().size() == 1 );


    m.parse("/one/two?arg1&arg2");
    assert( m.paths().size() == 2 && m.params().size() == 2 );

    m.parse("/one/two?arg1=10&arg2");
    assert( m.paths().size() == 2 && m.params().size() == 2 );

    m.parse("/one/two?arg1=10&arg2=20");
    assert( m.paths().size() == 2 && m.params().size() == 2 );
    m.parse("/one/two////?arg1&arg2=20");
    assert( m.paths().size() == 2 && m.params().size() == 2 );
    m.parse("/one/two?arg1====&arg2");
    assert( m.paths().size() == 2 && m.params().size() == 2 );
    m.parse("/one/two/?arg1====&arg2====");
    assert( m.paths().size() == 2 && m.params().size() == 2 );
    m.parse("/one/two/?arg1=???&arg2=%%%&arg3=@@super-baby");
    assert( m.paths().size() == 2 && m.params().size() == 3 );
 

    m.parse("?arg1=1&arg2=2&arg3=3");
    assert( m.paths().size() == 0 && m.params().size() == 3 );
    m.parse("/?arg1=1&arg2=2&arg3=3");
    assert( m.paths().size() == 0 && m.params().size() == 3 );
    m.parse("/////?arg1=1&arg2=2&arg3=3");
    assert( m.paths().size() == 0 && m.params().size() == 3 );
    m.parse("arg1=1&arg2=2&arg3=3");
    assert( m.paths().size() == 0 && m.params().size() == 3 );
    m.parse("arg1&arg2=2&arg3");
    assert( m.paths().size() == 0 && m.params().size() == 3 );
    m.parse("arg1&arg2&arg3=3");
    assert( m.paths().size() == 0 && m.params().size() == 3 );
    m.parse("arg1&arg2&arg3");
    assert( m.paths().size() == 0 && m.params().size() == 3 );

    m.parse("arg1&arg2=U3VwZXJiYWJ5Cg==&arg3");
    assert( m.paths().size() == 0 && m.params().size() == 3 );

    m.parse("one/two/three/////");
    assert( m.paths().size() == 3 && m.params().size() == 0 );


    return 0;
}

