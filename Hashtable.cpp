#include "Hashtable.h"



     Hashtable::Hashtable(){
          table = new HashEntry*[SIZE];
          for(int i =0; i<SIZE; i++)
              table[i] = NULL;
              }

   int Hashtable::get(int key){
        int hash = (key %SIZE);
        while(table[hash]!=NULL && table[hash]->getKey() !=key)
          hash = (hash+1)%SIZE;
        if(table[hash] ==NULL)
          return -1;
        else 
         return table[hash]->getValue();
      }
   
   void Hashtable::put(int key, int value){
        int hash = key%SIZE;
        while(table[hash] != NULL && table[hash]->getKey() != key)
         hash = (hash+1)%SIZE;
        if(table[hash]!=NULL)
          delete table[hash];
        table[hash] = new HashEntry(key,value);    
     }

    Hashtable::~Hashtable(){
           for(int i =0 ; i <SIZE; i++)
               if(table[i]!= NULL)
                    delete table[i];
           delete [] table;

     }

    void Hashtable::printAll(){

    for(int i =0; i<SIZE; i++)
       if(table[i]!=NULL)std::cout<<table[i]->getKey()<<" --- "<<table[i]->getValue()<<std::endl;
   }  
           
