#include <iostream>
#include <string>

using namespace std;

class Message{
private:
  string from,to;
  string subject,body;
  bool validate(){
    for(int i = 0;i<to.length();i++)
      if(to[i] == '@') return false;
    return true;
  }
public:
  Message (string from ="",string to="",string subject="",string body=""){
    this->from = from;
    this->to = to;
    this->subject = subject;
    this->body = (body.length() > 2000)?"":body;
  }
  void disp()const{
      cout<<"Od: "<<from<<" Do: "<<to<<endl;
      cout<<subject<<"\n"<<body<<endl;
  }
  const string getFrom()const{
    return from;
  }
};
int main(){
  Message a("vase","boj@an","kako si","bsabdbdasbsabdbabdsasd");
  const Message b("bojan","bojdan","kako si","bsabdbdasbsabdbabdsasd");
  b.disp();
  cout<<b.getFrom()<<endl;
  string p = b.getFrom();
  return 0;
}
