#include "HashEntry.h"

const int SIZE = 128;

class Hashtable{

   private:
      HashEntry **table;


   public:
      Hashtable();
        

   int get(int key);
   
   void put(int key, int value);
   void printAll();

    ~Hashtable();


};         
           
