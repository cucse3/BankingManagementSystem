#include <iostream>
using namespace std;
class Node{
    public:
    string name;
    int account_No;
    int passcode;
    int balance;
    Node* next;
    
    Node(string name,int acc,int pass,int bal){
        this->name=name;
        account_No=acc;
        passcode=pass;
        balance=bal;
        next=NULL;
    }

};


    void CreateAccount(Node* &head,Node* &tail){
        string name;
        int acc,pass,bal;
        cout<<"Enter Name : ";
        cin>>name;
        cout<<"Enter Account No. : ";
        cin>>acc;
        cout<<"Enter PassCode : ";
        cin>>pass;
        cout<<"Enter Balance : ";
        cin>>bal;

        if(head==NULL){
            Node* temp;
            temp=new Node(name,acc,pass,bal);
            head=temp;
            tail=temp;
        }
        else{

        // Pending For already Existing Node
            Node* temp;
            temp=new Node(name,acc,pass,bal);
            tail->next=temp;
            tail=temp;
    }
    }
    void Transaction(Node* &head,Node* &tail){
        int acc,mode,amount;
        cout<<"Enter your Account No. : ";
        cin>>acc;
        Node* temp=head;
        while(temp!=NULL){
            if(acc==temp->account_No){
                break;
            }
            temp=temp->next;
        }

        if(temp==NULL){
            cout<<"Invalid Account No. "<<endl;
        }
        else{
            cout<<"Enter\n1->Deposit\n2->Withdrawl"<<endl;
            cin>>mode;
            if(mode==1){
                cout<<"Enter Amount : ";
                cin>>amount;
                temp->balance+=amount;
            }
            else if(mode==2){
                cout<<"Enter Amount : ";
                cin>>amount;
                temp->balance-=amount;
            }
        }
    }
int main() {
    // Node* root=new Node("Rahul",123456789,1568,9999);
    // cout<<"Name : "<<root->name<<endl;
    // cout<<"Account No. "<<root->account_No<<endl;
    // cout<<"Password : "<<root->passcode<<endl;
    // cout<<"Balance : "<<root->balance<<endl;
    Node* head=NULL;
    Node* tail=NULL;

    CreateAccount(head,tail);
    Transaction(head,tail);

    Node* temp=head;
    while(temp!=NULL){
    cout<<"Name : "<<temp->name<<endl;
    cout<<"Account No. "<<temp->account_No<<endl;
    cout<<"Password : "<<temp->passcode<<endl;
    cout<<"Balance : "<<temp->balance<<endl;
    temp=temp->next;
    }


    return 0;
}
