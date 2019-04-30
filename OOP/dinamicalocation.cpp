#include "iostream"
#include "string"
using namespace std;

class foo{
private:
  int *arr;
  int br;
public:
  ~foo(){
    delete [] arr;
  }
  foo(int x[]=NULL,int n=0){
    arr = new int[n];
    br = n;
    for(int i=0;i<n;i++)
      arr[i]=x[i];
  }
  void operator +=(foo x){
      int *temp = new int[br];
      for(int i=0;i<br;i++)
         arr[i] += x.arr[i];
  }
  void add(int num){
    int *temp = new int[br+1];
    for(int i=0;i<br;i++)
      temp[i] = arr[i];
    temp[br++] = num;
    delete [] arr;
    arr = temp;
  }
  void print(){
    for(int i=0;i<br;i++)
      cout<<arr[i]<<" ";
    cout<<endl;
  }
};
int main(){
  int temp[] = {10,20,30};
  int temp2[] = {12,213,213};
  foo a(temp,3);
  foo c(temp2,3);
  c+=a;
  c.print();
}
