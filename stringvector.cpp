#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<unordered_map>
#include<map>
using namespace std;


string reverse(string const  &input){
  return string(input.rbegin(),input.rend());
}

int main(){
unordered_map<string,vector<string>> mymap;
string str;

while(getline(std::cin,str)){
   string st1 = str.substr(str.rfind("."));
   cout<<st1<<endl;
   unordered_map<string,vector<string>>::iterator got{mymap.begin()};
   got=mymap.find(st1);
   if(got==mymap.end()){
      vector<string> temp;
      temp.push_back(str);
      mymap.insert(make_pair(st1,temp));
     }
   else{
    got->second.push_back(str);
   }  
}

map<string,vector<string>> ordered(mymap.begin(),mymap.end());
for(auto &x :ordered){
  cout<<x.first<<" "<< "list: "<<endl;
  sort(x.second.begin(),x.second.end());
  for(auto it =x.second.begin(); it != x.second.end();++it)
      cout<<*it<<endl;
  cout<<"-------"<<endl<<endl;
 } 

/*
vector<string> vec;
vector<string>::iterator iter;

vec.push_back("hello world");
vec.push_back("joy ma kali");
vec.push_back("fuck mohammad");
for(iter=vec.begin();iter != vec.end();++iter)
    cout<<*iter<<endl;
sort(vec.begin(),vec.end());
for(iter=vec.begin();iter != vec.end();++iter)
    cout<<*iter<<endl;*/
return 0;

}


