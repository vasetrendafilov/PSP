#include <iostream>
#include <string>

using namespace std;

class Employee{
private:
  string name,pos;
  int salary;
public:
  Employee (){}
  Employee (string name,string pos,int salary){
    this->name = name;
    this->pos = pos;
    this->salary = salary;
  }
  int getSalary(){
    return salary;
  }
  void print(){
    cout<<name<<" "<<pos<<" "<<salary<<endl;
  }
};
void sort(Employee emp[],int n){
  for (int i = 0; i < n; i++)
    for(int j=i+1; j<n;j++)
      if(emp[i].getSalary() > emp[j].getSalary()){
        Employee temp = emp[i];
        emp[i]=emp[j];
        emp[j]=temp;
      }
}
int main(){
  Employee emp[100];
  string name,pos;
  int salary,m,n=0;
  cin>>m;
  while(m != 0){
    cin>>name>>pos>>salary;
    Employee temp(name,pos,salary);
    emp[n++]=temp;
    cin>>m;
  }
  sort(emp,n);
  for(int i=0;i<n;i++)
    emp[i].print();
  return 0;
}
