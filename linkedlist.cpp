#include <string.h>
#include <stdio.h>
#include "linkedlist.h"

void copystr( char *dest, const char *src )
{
    int size = strlen(src);
    dest = new char[size+1];
    strncpy( dest, src, size );
    printf("Old str [%s], new str [%s], src size %d\n", src, dest, size);
};

LinkedList::LinkedList() {
    m_first = NULL;
    m_last = NULL;
    m_num_items = 0;
}

LinkedList::~LinkedList() {

}

int
LinkedList::size() {
    return m_num_items;
}

LinkedListItem*
LinkedList::first() {
    return m_first;
}

LinkedListItem*
LinkedList::last() {
    return m_last;
}

void
LinkedList::printContent() {
    LinkedListItem *begin = this->m_first;
    while ( begin != NULL ) {
        begin->print();
        begin = begin->next;
    };
};

void
LinkedList::add( LinkedListItem *item ) {
    printf("Starting adding an item\n");
    if ( item == NULL ) {
        printf("Item is not initialized\n");
    };
    printf("Updated pointers\n");
    if ( m_first == NULL ) {
        m_first = item;
        m_last = item;
    } else {
        m_last->next = item;
    }
    item->next = NULL;
    m_num_items++;
    printf("Item is being added\n");
}

void
LinkedList::add( const char *key, const char *value ) {
    printf("Before adding an item\n");
    LinkedListItem *item =  new LinkedListItem( key, value );
    printf("Added an item\n");
    this->add( item );
}

