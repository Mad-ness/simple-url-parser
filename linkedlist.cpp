#include <string.h>
#include <stdio.h>
#include "linkedlist.h"

void copystr( char *dest, const char *src )
{
    int size = strlen(src);
    // dest = new char[size+2];
//    dest = (char*)malloc(size * sizeof(src[0]) + 1);
    strcpy( dest, src );
//    printf("First letter: %c (%lu bytes), Old str [%s], new str [%s], src size %d\n", src[0], sizeof(src[0]), src, dest, size);
};

LinkedList::LinkedList() {
    m_first = NULL;
    m_last = NULL;
    m_num_items = 0;
}

LinkedList::~LinkedList() {
    LinkedListItem *it = this->m_first;
    LinkedListItem *item;
    while ( it != NULL ) {
        item = it;
        delete item;
        it = it->next;
    };
}

int
LinkedList::size() {
    return m_num_items;
}

LinkedListItem&
LinkedList::first() {
    return *m_first;
}

LinkedListItem&
LinkedList::last() {
    return *m_last;
}

void
LinkedList::printContent() {
    LinkedListItem *begin = this->m_first;
    while ( begin != NULL ) {
        begin->print();
        begin = begin->next;
    };
};

LinkedListItem& 
LinkedList::at(const int index) {
    LinkedListItem *found = NULL, *it = m_first;
    int curr_id = 0;
    while ( curr_id < index ) {
        it = it->next;
        curr_id++;
        if ( it == NULL ) break;
    }
    if ( it != NULL ) {
        found = it;
    }
    return *found;;
}

void
LinkedList::add( LinkedListItem *item ) {
//    printf("Starting adding an item\n");
    if ( m_first == NULL ) {
        m_first = item;
        m_last = item;
    } else {
        printf("Added %s\n", item->key);
        m_last->next = item;
        m_last = item;
    }
    item->next = NULL;
    m_num_items++;
    printf(" >>> this poiner %p\n", item);
}

void
LinkedList::add( const char *key, const char *value ) {
//    printf("Before adding an item\n");
    LinkedListItem *item =  new LinkedListItem( key, value );
//    printf("Added an item\n");
    this->add( item );
}

