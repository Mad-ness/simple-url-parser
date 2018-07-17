#include <stdio.h>
#include "linkedlist.h"


int main() {
    LinkedList l;
    printf("List size %d items\n", l.size()); 
    l.add("one", "oneone");
    l.add("two", "twotwo");
    l.add("three", "threethree");
    l.add("four", "fourfour");
    l.add("eleven", "eleveneleven");
    printf("List size %d items\n", l.size()); 
    l.printContent();
    return 0;
}

