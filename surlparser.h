#ifndef __SIMPLEURLPARSER_H__
#define __SIMPLEURLPARSER_H__

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef unordered_map<string, string> KeyValueMap_t;
typedef vector<string> Folder_t;

class SUrlParser {
    private:
        KeyValueMap_t m_keysvalues;
        Folder_t m_folders;
    public:
        bool parse(const char *url);
        Folder_t &paths() { return m_folders; };
        KeyValueMap_t &params() { return m_keysvalues; };
        KeyValueMap_t &args();
        void print(char splitter='\n');
};

#endif // __SIMPLEURLPARSER_H__

