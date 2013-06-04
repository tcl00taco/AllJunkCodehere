#include<iostream>
#include<cstdlib>
#include<cmath>
#include "Hashtable.h"

using namespace std;

Hashtable::Hashtable(int tablesize)
{
    size =0;
    this->tablesize = tablesize;
    table = new Meta*[tablesize];
    for(int i =0; i <tablesize; i++){
     table[i] = NULL;
    }
}

Hashtable::~Hashtable(){
 removeAll();
 delete [] table;
}

bool Hashtable::put(char* key, char* value){
 if(find(key) != NULL){
 return false;}
 Meta* entry = new Meta(key,value);
 int bucket = hashString(key);
 entry->next = table[bucket];
 table[bucket]=entry;
 size++;
 return true;
}
bool Hashtable::get(char* key, char* value){
Meta* temp = find(key);
if(temp == NULL){
value[0]='\0';
return false;
}
else{
strcpy(value,temp->value);
return true;
}
}

bool Hashtable::contains(char* key){
if(find(key)== NULL){
return false;}
else {
return true;}
}

bool Hashtable:: remove(char* key){
int bucket = hashString(key);
Meta* temp = table[bucket];

if(temp==NULL){
return false;}
else if(strcmp(key,temp->key)== 0){
table[bucket]= temp->next;
delete temp;
size--;
return true;
}
else{

Meta* temp_next = temp->next;
while(temp_next != NULL){
if(strcmp(key,temp_next -> key) ==0){
temp->next = temp_next->next;
delete temp_next;
size--;
return true;}
temp = temp->next;
temp_next = temp_next->next;
}
}
}
void Hashtable::removeAll()
{
    for(int i=0 ; i <tablesize; i++){
    Meta* temp = table[i];
    while(temp != NULL){
    Meta* next = temp->next;
    cout<<"remove node - Key: "<< temp->key<<"\t"<<temp->value<<endl;
    delete temp;
    temp = next;

    }
    }
    size =0;
}

int Hashtable::getSize(){
return size;
}

Meta* Hashtable::find(char* key){

   int bucket = hashString(key);
   Meta* temp = table[bucket];
   while(temp!= NULL){
    if(strcmp(key,temp->key)== 0){
    return temp;}
    temp =temp->next;


   }
  return NULL;
}

long Hashtable::hashString(char* key){
 int n = strlen(key);
 long h = 0;
 for(int i=0; i<n; i++){
  h = (h<<2) + key[i];
 }

 return abs(h%tablesize);
}

bool Hashtable::hasNext(){

if(current_entry == NULL)
return false;
else return true;
}

void Hashtable::initIterator(){

  current_entry = NULL;
  current_index = tablesize;
  for(int  i =0 ; i <tablesize; i++){
   if(table[i] == NULL){
   cout<<"found"<<endl;}
   else{
   current_entry = table[i];
   current_index = i;
   return;}
  }

}

void Hashtable::getNextKey(char* key){
  if(current_entry == NULL)
  {
       key[0] ='\0';
       return;  }
       strcpy(key,current_entry->key);
       if(current_entry->next != NULL){
        current_entry = current_entry->next;
       }
       else{
       for(int i = current_index+1; i< tablesize; i++){
        if(table[i]==NULL)
        continue;
       current_entry = table[i];
       current_index=i;
       return;
       }
       current_entry = NULL;
       current_index = tablesize;
       }
}
