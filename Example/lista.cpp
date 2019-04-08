#include "iostream"
#include "string"
using namespace std;

typedef int var;

struct Node{
  var item;
  Node *next;
};
struct List{
  int br;
  Node *head,*tail;
  void init();
  void push(var x,bool back);
  void pop(bool back);
  void print();
  void remove();
};
void List::init(){ head = tail = NULL; br=0;}
void List::push(var x,bool back = false){
  Node *temp = new Node;
  temp->item = x;
  if(head == NULL){
     temp->next = temp;
     head = tail = temp;
   }
  else if (back){
    tail->next = temp;
    tail = temp;
    tail->next = head;
  }else{
    temp->next = head;
    head = temp;
    tail->next = head;
  }br++;
}
void List::pop(bool back = false){
  if(head == NULL){
    cout<<"Listata e prazna";
    return;
  }
  if(head->next == head){
    delete head;
    head = tail = NULL;
    br = 0;
  }else if(back){
    Node *i,*temp;
    for(i=head;i->next != tail;i=i->next);
    i->next = head;
    delete tail;
    tail = i;
    br--;
  }else{
    tail->next = head->next;
    delete head;
    head = tail->next;
    br--;
  }
}
void List::print(){
  Node *i = head;
  do{
    cout<< i->item<<'\t';
    i = i->next;
  }while(i != head);
}
void List::remove(){
  while (head!=NULL) pop(true);
}
int main(){
  List a;
  a.init();
  a.push(10);
  a.push(5);
  a.push(3);
  a.print();
  a.remove();
}
