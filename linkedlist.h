#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copystr( char *dest, const char *src );

struct LinkedListItem {
    char *key;
    char *value;
    LinkedListItem *next;
    bool isLast() { return ( next == NULL ); };
    void print() {
        printf(" >> key=%s, value=%s, this_p=%p, next_p=%p\n", key, value, this, (void*)next);
        //printf(" >> this_p=%p, next_p=%p\n", this, (void*)next);
    };
    LinkedListItem(LinkedListItem &src) {
        *this = src;
    };
    LinkedListItem( const char *key, const char *value ) {
        copystr( this->key, key );
        copystr( this->value, value );
    };
    LinkedListItem &operator=(const LinkedListItem &src) {
        copystr( this->key, src.key );
        copystr( this->value, src.value );
        this->next = src.next;
        return *this;
    };
};

class LinkedList {
    private:
        int m_num_items;
        LinkedListItem *m_first;
        LinkedListItem *m_last;
    public:
        LinkedList();
        ~LinkedList();
        int size();
        LinkedListItem *first();
        LinkedListItem *last();
        void add( LinkedListItem *item );
        void add( const char *key, const char *value );
        void printContent();
};

#endif // __LINKEDLIST_H__

