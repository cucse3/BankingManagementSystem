#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    string name;
    long int account_number;
    int PIN;
    double balance=0.0;
    node *next;
    node() {}

    node(string name, int PIN, long int account_no, double balance)
    {
        this->name = name;
        account_number = account_no;
        this->PIN = PIN;
        this->balance=balance;
        next = NULL;
    }

};

    int random()
    {
        srand(static_cast<unsigned int>(time(nullptr)));
        int min = 10000000; // Smallest 8-digit number
        int max = 99999999; // Largest 8-digit number
        int randomInteger = min + (rand() % (max - min + 1));
        return randomInteger;
    }

    void create_account(node *&head)
    {
        node obj;
        string name;
        int PIN;
        long int account_no = random();
        cout << "Enter your name\n";
        cin.ignore(); // to take string input in new line
        getline(cin, name);
        cout << "Your Account number is: " << account_no << endl;
        cout << "Set a PIN for your account\n";
        cin >> PIN;

        node *n = new node(name, PIN, account_no,obj.balance);
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }

        cout << "\nAccount created successfully\n";
        cout << "Name: " << name << endl
             << "Account number: " << account_no << endl;
    }

    void login(node *head)
    {
        int check_PIN;
        long int check_acc;
        cout << "\nLogin\n";
        cout << "Enter Account number\n";
        cin >> check_acc;
        cout << "Enter you PIN\n";
        cin >> check_PIN;

        node *temp = head;
        bool found = false;

        while (temp != NULL)
        {
            if (temp->account_number == check_acc && temp->PIN == check_PIN)
            {
                cout << "Login successful\n";
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found)
        {
            cout << "Wrong account number or password\nRetry\n";
            login(head);
        }
    }

int main()
{
    node obj;
    node *head = NULL;
    cout << "Welcome to ABC Bank\n";

    int ch1, ch2, exit1 = 1,exit2 = 1;
    repeat:
    while (exit1 == 1)
    {
        cout << "\nEnter 1 to create new account, Enter 2 to login, 0 to exit\n";
        cin >> ch1;
        switch (ch1)
        {
        case 1:
        {
            create_account(head);
            break;
        }
        case 2:
        {
            if (head == NULL)
            {
                cout << "No account registered\n";
            }
            else
            {
                login(head);
                exit1 = 0;
            }
            break;
        }
        case 0: return 0;
        default:
            cout << "Wrong input\n";
        }
    }

    while (exit2 == 1)
    {
        cout << "\nEnter 1 for View Balance, Enter 0 for logout\n";
        cin>>ch2;
        switch(ch2){
            case 1: {
                cout<<"Balance: " <<obj.balance <<endl;
                break;
            }
            case 0: {
                exit1=1;
                goto repeat;
                break;
            }
            default: cout<<"Wrong input\n";
        }
    }

    return 0;
}
