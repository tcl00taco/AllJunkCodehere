#include<cstring>
#define SIZE_KEY 32
#define SIZE_VALUE 256
#define DEFAULT_TABLESIZE 101


typedef struct Metadata
{
    char key[SIZE_KEY];
    char value[SIZE_VALUE];
    struct Metadata* next;


    Metadata(char * key, char *  value){
    strcpy(this->key,key);
    strcpy(this->value,value);
    next = NULL;

    }


}Meta;

class Hashtable
{
    private:
       int tablesize;
       Meta** table;
       int size;
       long hashString(char* key);
       Meta* find(char* key);
       Meta* current_entry;
       int current_index;
    public:
       Hashtable(int tablesize=DEFAULT_TABLESIZE);
       virtual ~Hashtable();
       bool put(char* key, char* value);
       bool get(char* key, char* value);
       bool contains(char* key);
       bool remove(char* key);
       void removeAll();
       int getSize();
       void initIterator();
       bool hasNext();
       void getNextKey(char* key);

};
