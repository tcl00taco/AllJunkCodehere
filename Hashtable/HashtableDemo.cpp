#include<ctime>
#include<iostream>
#include<cstring>
#include "Hashtable.h"
using namespace std;

int main(){
 Hashtable* hashtable = new Hashtable(5);
 char key[SIZE_KEY];
 char value[SIZE_VALUE];
  char key1[SIZE_KEY];
 char value1[SIZE_VALUE];
 strcpy(key,"234");
 strcpy(value,"Mary");
 if(!hashtable->contains(key))
{
    cout<<"Adding node- key:  "<< key << " value: " <<value<<endl;
    cout<<hashtable->put(key,value)<<endl;
}
strcpy(key,"334");
 strcpy(value,"Mariam");
 if(!hashtable->contains(key))
{
    cout<<"Adding node- key:  "<< key << " value: " <<value<<endl;
    cout<<hashtable->put(key,value)<<endl;
}

strcpy(key,"134");
 strcpy(value,"Mari");
 if(!hashtable->contains(key))
{
    cout<<"Adding node- key:  "<< key << " value: " <<value<<endl;
    cout<<hashtable->put(key,value)<<endl;
}

strcpy(key,"634");
 strcpy(value,"Salma");
 if(!hashtable->contains(key))
{
    cout<<"Adding node- key:  "<< key << " value: " <<value<<endl;
    cout<<hashtable->put(key,value)<<endl;
}





hashtable->initIterator();



while(hashtable->hasNext()){
cout<<"abc"<<endl;
hashtable->getNextKey(key);
hashtable->get(key,value);
cout<<"key:  "<< key << " value: " <<value<<endl;

}


delete hashtable;

return 0;
}
