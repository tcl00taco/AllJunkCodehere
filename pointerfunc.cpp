#include <iostream>
#include <vector>
using namespace std;

double & GetWeeklyHours()
{
    double h = 46.50;
    double &hours = h;

    return hours;
}
//---------------------------------------------------------------------------

vector<string>* getStrings(){
   vector<string> *vec = new vector<string>();
   string str;
   while(getline(cin,str))
       vec->push_back(str);

  return vec;
}






//-----------------------------------------------------------------------
double * GetSalary()
{
    double salary = 26.48;
    double *HourlySalary = &salary;

    return HourlySalary;
}
//---------------------------------------------------------------------------
int main()
{
    double hours  = GetWeeklyHours();
    double salary = *GetSalary();
    double *salary1= GetSalary();
    cout << "Weekly Hours:  " << hours << endl;
    cout << "Hourly Salary: " << *salary1 << endl;

    double WeeklySalary = hours * salary;

    cout << "Weekly Salary: " << WeeklySalary << endl;
    cout<<endl<<endl;  
   //vector<string>* vec1 = getStrings();
   for(auto &x :*getStrings())
       cout<<x<<endl; 

    return 0;
}
