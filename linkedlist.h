#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copystr( char *dest, const char *src );

/*
struct LinkedListItem {
    char key[16];
    char value[16];
    LinkedListItem *next;
    bool isLast() { return ( next == NULL ); };
    void print() {
        printf(" >> key=%s, value=%s, this_p=%p, next_p=%p\n", key, value, this, (void*)next);
        //printf(" >> this_p=%p, next_p=%p\n", this, (void*)next);
    };
    LinkedListItem(LinkedListItem &src) {
        *this = src;
    };
    LinkedListItem( const char *_key, const char *_value ) {
        copystr( this->key, _key );
        copystr( this->value, _value );
    };
    LinkedListItem &operator=(const LinkedListItem &src) {
        copystr( this->key, src.key );
        copystr( this->value, src.value );
        this->next = src.next;
        return *this;
    };
};
*/

template <class T>
class LinkedList {
    public:
        struct LinkedListIt {
            T *data;
            LinkedListIt *next;
        };
        LinkedList() {
            m_first = NULL;
            m_last = NULL;
            m_num_items = 0;
        };
        ~LinkedList() {
            LinkedListIt *it = m_first;
            LinkedListIt *item = NULL;
            while ( it != NULL ) {
                item = it;
                delete item;
                it = it->next;
            }
        }
        int size() {
            return m_num_items;
        };
        LinkedListIt& first() {
            return *m_first;
        };
        LinkedListIt& last() {
            return *m_last;
        };
        T& at(const int index) {
            LinkedListIt *found = NULL;
            LinkedListIt *it = m_first;
            int curr_id = 0;
            while ( curr_id < index ) {
                it = it->next;
                curr_id++;
                if ( it == NULL ) break;
            };
            if ( it != NULL ) {
                found = it;
            };
            return *found->data;
        };
        void add( T &data ) {
            LinkedListIt *item = new LinkedListIt();
            item->data = new T(data);
            if ( m_first == NULL ) {
                m_first = item;
                m_last = item;
            } else {
                m_last->next = item;
                m_last = item;
            };
            item->next = NULL;
            m_num_items++;
        };
        void printContent() {
            LinkedListIt *begin = m_first;
            while ( begin != NULL ) {
                begin->data->print();
                begin = begin->next;
            };
        };
    private:
        int m_num_items;
        LinkedListIt *m_first;
        LinkedListIt *m_last;
};
#endif // __LINKEDLIST_H__

