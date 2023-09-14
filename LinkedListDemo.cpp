#include <bits/stdc++.h>
using namespace std;

class node{
    public: 
    int data;
    node *next;

    node(){}

    node(int value){
        data=value;
        next=NULL;
    }

    void add(node* &head, int value){
        node* n= new node(value);
        if(head==NULL){
            head=n;
            return;
        }
        else{
        node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = n;
        }
    }

    void addATfirst(node* &head,int value){
        node* n= new node(value);
        n->next=head;
        head=n;
    }

    void disp(node* head){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data <<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};

int main(){
    node obj;
    node* head=NULL;
    obj.add(head,1);
    obj.add(head,2);
    obj.add(head,8);
    obj.add(head,7);
    obj.addATfirst(head,76);

    obj.disp(head);

return 0;
}
