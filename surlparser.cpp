#include <iostream>
#include <string>
#include "surlparser.h"


bool SUrlParser::parse(const char *uri) {
    m_folders.clear();
    m_keysvalues.clear();
    enum Type { begin, folder, param, value };
    string s;

    const char *c = uri;
    // scan the whole string
    enum Type t = Type::begin;
    string last_param;
    if ( c != NULL || *c != '\0' ) {
        do {
            if ( *c == '/' ) {
                if ( s.length() > 0 ) {
                    m_folders.push_back(s);
                    s.clear();
                }
                t = Type::folder;
            } else if ( *c == '?' && ( t == Type::folder || t == Type::begin )) {
                if ( s.length() > 0 && s.length() > 0 ) {
                    m_folders.push_back(s);
                    s.clear();
                }
                t = Type::param;
            } else if ( *c == '=' && ( t == Type::param || t == Type::begin )) {
                m_keysvalues[s] = "";
                last_param = s;
                s.clear();
                t = Type::value;
            } else if ( *c == '&' && ( t == Type::value || t == Type::param || t == Type::begin )) {
                if ( t == Type::value ) {
                    m_keysvalues[last_param] = s;
                } else if (( t == Type::param || t == Type::begin ) && ( s.length() > 0 )) {
                    m_keysvalues[s] = "";
                    last_param = s;
                }
                t = Type::param;
                s.clear(); 
            } else if ( *c == '\0' && s.length() > 0 ) {
                if ( t == Type::value ) {
                    m_keysvalues[last_param] = s;
                } else if ( t == Type::folder ) {
                    m_folders.push_back(s);
                } else if ( t == Type::param ) {
                    m_keysvalues[s] = "";
                }
                s.clear();
            } else if ( *c == '\0' && s.length() == 0 ) {
                if ( t == Type::param && last_param.length() > 0 ) {
                    m_keysvalues[last_param] = "";
                }
                s.clear();
            } else { 
                s += *c;
            }
        } while ( *c++ != '\0' );
    }
    return true;
}

KeyValueMap_t &SUrlParser::args() {
    return m_keysvalues;
}

void SUrlParser::print(char splitter) {
    std::cout << std::endl;
    std::cout << "Total " << m_folders.size() << " m_folders, see below, if any" << std::endl;
    for ( const auto &n : m_folders ) {
        std::cout << " - " << n << std::endl;
    }
    for ( const auto &n : m_keysvalues ) {
        std::cout << "Key:[" << n.first << "] Value: [" << n.second << "]" << splitter;
    }
    std::cout << std::endl;
}

