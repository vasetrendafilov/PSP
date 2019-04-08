#include "iostream"
#include "string"
#include "cstdlib"

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
void List::print(){
  for( Node *temp = head ; temp != NULL ; temp = temp->next)
    cout<< temp->item <<" ";
}
void List::remove(){
  while(head!=NULL)
    pop(false);
}
void sort(List &x){
  for( Node *i = x.head ; i != NULL ; i = i->next)
    for( Node *j = x.head ; j != NULL ; j = j->next)
      if(i->item < j->item){
        var temp = j->item;
        j->item = i->item;
        i->item = temp;
      }
}
void bind(List &a,List &b,List &c){
  Node *first = a.head, *second = b.head;
  while( first != NULL && second != NULL){
    if(first->item == second->item) second = second->next;
    if(first->item < second->item){
      c.push(first->item);
      first = first->next;
    }else{
      c.push(second->item);
      second = second->next;
    }
  }
  while (first != NULL ) {
    c.push(first->item);
    first = first->next;
  }
  while (second != NULL ) {
    c.push(second->item);
    second = second->next;
  }
}
int main(){
  List a,b,c;
  a.init();
  b.init();
  c.init();
  for (size_t i = 0; i < 5; i++){
    a.push(rand()%100);
    b.push(rand()%100);
  }
  sort(a);
  sort(b);
  bind(a,b,c);
  c.print();
  a.remove();
  b.remove();
  c.remove();
  return 0;
}
