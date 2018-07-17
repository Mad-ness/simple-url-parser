#include <stdio.h>
#include "linkedlist.h"

struct Item {
    char key[20];
    char value[20];
    void print() {
        printf(" >> %s = %s\n", key, value);
    };
    Item(const Item &src) {
        *this = src;
    };
    Item(const char *key, const char *value) {
        strcpy(this->key, key);
        strcpy(this->value, value);
    };
    Item& operator=(const Item &src) {
        strcpy(this->key, src.key);
        strcpy(this->value, src.value); 
        return *this;
    };
};


int main() {
    LinkedList<Item> l;
    LinkedList<char*> c;
    printf("List size %d items\n", l.size()); 
/*
    l.add(Item("one", "oneone"));
    l.add(Item("two", "twotwo"));
    l.add(Item("three", "threethree"));
//    l.add(Item("four", "fourfour"));
//    l.add(Item("five", "fivefive"));
    printf("List size %d items\n", l.size()); 
    l.printContent();
    l.at(0).print();
*/
    c.add("char one");
    c.add("char two");
    return 0;
}

