#include "iostream"
#include "string"
using namespace std;
class Album{
private:
  string name;
  string *songs;
  int br;
public:
  Album(string nameIn="",string *songsIn = NULL,int brIn = 1)
  :name(nameIn),br(brIn){
    songs = new string[br];
    for(int i=0;i<br;i++)
      songs[i] = songsIn[i];
  }
  Album(const Album &x):name(x.name),br(x.br){
    songs = new string[br];
    for(int i=0;i<br;i++)
      songs[i] = x.songs[i];
  }
  ~Album(){ delete [] songs; }

  Album & operator = (const Album &x){
    if(this == &x) return *this;
    name = x.name;
    br = x.br;
    delete [] songs;
    songs = new string[br];
    for(int i=0;i<br;i++) songs[i] = x.songs[i];
    return *this;
  }
  Album & operator +=(string song){
    string *temp = new string[br+1];
    for(int i=0;i<br;i++) temp[i] = songs[i];
    temp[br++] = song;
    delete [] songs;
    songs = temp;
    return *this;
  }
  friend ostream & operator <<(ostream &out,const Album &x){
    out<<"Name: "<<x.name<<endl<<"Pesni: ";
    for(int i=0;i<x.br;i++) out<< x.songs[i]<<" ";
    return out;
  }
  string &operator [](int i){return songs[i];}
  const string &operator [](int i) const {return songs[i];}
};
int main(){
  string b[] = {"kako","si"};
  Album a("vase",b,2),c("sos",b,1);
  const Album f("vase",b,2);
  cout<<a[0]<<endl;



  return 0;
}
