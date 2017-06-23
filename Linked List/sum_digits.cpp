#include<iostream>
#include<stdlib.h>
#include "mylist.h"

using namespace std;

Node* add(Node *num1, Node *num2){
  Node *head=NULL;
  int carry=0,sum=0;
  while(num1||num2){
    sum=carry;
    if(num1) sum+=num1->data;
    if(num2) sum+=num2->data;

    if(sum>9){
      carry=sum/10;
      sum=sum%10;
    }
    else carry = 0;

    Node *temp = new Node(sum);
    addToFront(head, temp);
    
    if(num1) num1=num1->next;
    if(num2) num2=num2->next;
}

  if(carry){
    Node *temp = new Node(carry);
    addToFront(head, temp);
  }

  return head;

}

int main(){
  Node *h1=takeInput();
  Node *h2=takeInput();
//  h1=rev(h1);
//  h2=rev(h2);
  Node *ans= add(h1,h2);
  print(ans);
}