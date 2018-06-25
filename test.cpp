#include <string>
#include <iostream>
#include <cassert>
#include "surlparser.h"

using namespace std;

void testall();
void testpath();
bool test(const char *path, const char *compare_to);

bool test(const char *path, const char *compare_to);

int main(int argc, char **argv) {
    testall();
    testpath();
    return 0;
}

void testpath() {

    assert( test( "/test", "/test" ));
    assert( test( "///test", "/test" ));
    assert( test( "///test//////", "/test" ));
    assert( test( "test", "/test" ));
    assert( test( "test", "/test" ));
    assert( test( "test/", "/test" ));
    assert( test( "test////", "/test" ));

    assert( test( "/device/ping", "/device/ping" ));
    assert( test( "///device/////ping", "/device/ping" ));
    assert( test( "device/ping////", "/device/ping" ));
    assert( test( "/device/ping", "/device/ping" ));
    assert( test( "/device/ping", "/device/ping" ));

    assert( test( "/device/ping?youre=mine", "/device/ping" ));
    assert( test( "device/ping?youre=mine", "/device/ping" ));
    assert( test( "device/ping/?youre=mine", "/device/ping" ));
    assert( test( "device/ping/?youre=mine&me=isyoure", "/device/ping" ));
    assert( test( "////device/////ping//////?youre=mine&and&I=youers", "/device/ping" ));
}

bool test(const char *path, const char *compare_to) {
    bool result = false;
    SUrlParser p;
    p.parse(path);
    std::cout << "Test path: [" << path << "] ... ";
    string s = p.path();
    if ( s == string(compare_to) ) {
        std::cout << "GOOD, " << s << std::endl;
        result = true;
    } else {
        std::cout << "BAD, " << s << std::endl << std::endl;
    }
    return result;
}

void testall() {
    SUrlParser m;
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

}

