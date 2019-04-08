#include "iostream"
#include "math.h"
#include "string"

using namespace std;

struct Student {
  string ime,prezime,index;
  int bodovi;
  void print(){
    cout<<ime<<" "<<prezime<<" "<<index<<" "<<bodovi<<endl;
  }
};
int main() {
  Student x[100];
  int n = 0;
  cin >> n;
  for (int i = 0; i <n ; i++) {
    cin >> x[i].ime >> x[i].prezime >> x[i].index;
    int n = 0;
    for (size_t j = 0; j < 4; j++) {
      int a;
      cin >> a;
      n+=a;
    }
    x[i].bodovi = n;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if(x[i].bodovi > x[j].bodovi){
        Student a = x[i];
        x[i] = x[j];
        x[j] = a;
      }
    }
  }
  for (size_t i = 0; i < n; i++) {
     x[i].print();
  }
  return 0;
}
