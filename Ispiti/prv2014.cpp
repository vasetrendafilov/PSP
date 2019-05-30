#include "iostream"
#include "string"
using namespace std;
class Player;
class Monster{
protected:
  string name;
  int atack,defence;
  bool state;
public:
  Monster(string nm="",int at=0,int df=0,bool st=false)
  :name(nm),atack(at),defence(df),state(st){}
  Monster(const Monster &x)
  :name(x.name),atack(x.atack),defence(x.defence),state(x.state){}
  bool napad(Monster &m){ return state * m.state;}
  bool odbran(Monster &m){ return !(state * m.state);}
  friend Player;
  void print(){
    cout<<name<<" "<<atack<<" "<<defence<<" "<<state<<endl;
  }
};
class Player{
protected:
  string name;
  int healt,br;
  Monster monsters[5];
public:
  Player(string namev="",int healtv=0,Monster monstersv[] = NULL,int brv=0)
  :name(namev),healt(healtv),br(brv){
    for(int i=0;i<br;i++)
      monsters[i] = monstersv[i];
  }
  Player(const Player &x):name(x.name),healt(x.healt),br(x.br){
    for(int i=0;i<br;i++)
      monsters[i] = x.monsters[i];
  }
  Player duel(Player &p){
    for(int i=0;i<p.br;i++){

        if(monsters[0].napad(p.monsters[i])){
          if(monsters[0].atack > p.monsters[i].atack)
            p.healt -= monsters[0].atack;
          else
            healt -= p.monsters[i].atack;
        }else if (monsters[0].state || p.monsters[i].state){
        if(monsters[0].state){
          if(monsters[0].atack > p.monsters[i].defence)
            p.healt-=monsters[0].atack;
          else
            healt-=p.monsters[i].atack;
        }else{
          if(p.monsters[i].atack > monsters[0].defence)
            healt-=p.monsters[i].atack;
          else
            p.healt-=monsters[0].atack;
        }
        }
      }

    return (healt>p.healt)?*this:p;
  }
  void print(){
    cout<<name<<" "<<healt<<endl;
    for(int i=0;i<br;i++) monsters[i].print();
  }
};
int main(){
  Monster a[]={Monster("vas",2,2,1) , Monster("va",1,1,0),Monster("ks",3,3,1)};
  Monster f[] = {Monster("sad",5,5,1)};
  Player b("bsae",100,f,1),c("vas",100,a,3);
  (b.duel(c)).print();
  return 0;
}
