#include "iostream"
#include "string"

using namespace std;

typedef int var;
struct Node{
  var item;
  Node *next;
};
struct List{
  Node *head;
  void init();
  void push(var x,bool back);
  void pop(bool back);
  void remove();
  void print();
};

void List::init(){ head = NULL; }
void List::push(var x,bool back = true){
  if(back){
    Node *temp = new Node;
    temp->item = x;
    temp->next = NULL;
    if(head == NULL)
      head = temp;
    else{
      Node *poz = head;
      while(poz->next != NULL) poz = poz->next;
      poz->next = temp;
    }
  }else{
    Node *temp = new Node;
    temp->item = x;
    temp->next = head;
    head = temp;
  }
}
void List::pop(bool back = true){
  if(head == NULL){
    cout<<"Listata e prazna"<<endl;
    return;
  }else if(head->next == NULL){
    delete head;
    head = NULL;
  }
  if(back){
    Node *poz = head,*del;
    while(poz->next->next != NULL) poz = poz->next;
    del = poz->next;
    poz->next = NULL;
    delete del;
  }else{
      Node *temp = head;
      head = head->next;
      delete temp;
  }
}
void List::remove(){
  while(head!=NULL)
    pop(false);
}
void List::print(){
  for( Node *temp = head ; temp != NULL ; temp = temp->next)
    cout<< temp->item <<" ";
}
int main(){
   List a;
   a.init();
   a.push(10);
   a.push(40,false);
   a.push(5);
   a.push(20);
   a.pop();
   a.print();
  return 0;
}
