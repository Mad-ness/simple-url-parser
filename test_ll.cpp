#include <stdio.h>
#include "linkedlist.h"


int main() {
    LinkedList l;
    printf("List size %d items\n", l.size()); 
    l.add("one", "oneone");
    l.add("two", "twotwo");
    l.add("three", "threethree");
    l.add("four", "fourfour");
    l.add("five", "fivefive");
    printf("List size %d items\n", l.size()); 
    l.printContent();
    l.at(5);
    return 0;
}

