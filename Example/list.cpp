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
  void push(var x,int pos);
  void pop(int pos);
  void remove();
  void reverse(Node *temp);
};
void List::init(){ head = NULL; }
void List::push(var x,int pos=100){
  Node *temp = new Node;
  temp->item = x;
  temp->next = NULL;
  if(head == NULL){head = temp; return;}
  if(pos == 1){
    temp->next = head;
    head = temp;
    return;
  }
  Node *point = head;
  for(int i = 0; i < pos-2 && point->next !=NULL ; i++,point = point->next);
  temp->next = point->next;
  point->next = temp;
}
void List::pop(int pos = 100){
  Node *temp = head;
  if(pos == 1){
    head = head->next;
    delete temp;
    return;
  }
  for(int i = 0; i < pos-2 && temp->next->next !=NULL ; i++,temp = temp->next);
  Node *temp2 = temp->next;
  temp->next = temp2->next;
  delete temp2;
}
void List::remove(){
  while(head!=NULL) pop(1);
}
void print(Node *temp){
  if(temp == NULL) return;
  cout<< temp->item <<" ";
  return print(temp->next);
}
void printr(Node *temp){
  if(temp == NULL) return;
  printr(temp->next);
  cout<< temp->item <<" ";
}
void List::reverse(Node *temp){
  if(temp->next == NULL){
    head = temp;
    return;
  }
  reverse(temp->next);
  temp->next->next = temp;
  temp->next = NULL;
}
int main(){
  List a;
  a.init();
  a.push(5);
  a.push(2);
  a.push(3);
  a.push(4);
  a.pop();
  print(a.head);
  a.remove();
  return 0;
}
