#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    string name;
    long int account_number;
    int PIN;
    double balance = 0.0;
    node *next;

    node() {}

    node(string name, int PIN, long int account_no)
    {
        this->name = name;
        account_number = account_no;
        this->PIN = PIN;
        balance = 0.0;
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
    string name;
    int PIN;
    long int account_no = random();
    cout << "Enter your name\n";
    cin.ignore(); // to take string input in a new line
    getline(cin, name);
    cout << "Your Account number is: " << account_no << endl;
    cout << "Set a PIN for your account\n";
    cin >> PIN;

    node *n = new node(name, PIN, account_no);
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

node *login(node *head, long int check_acc, int check_PIN)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->account_number == check_acc && temp->PIN == check_PIN)
        {
            cout << "Login successful\n";
            return temp;
        }
        temp = temp->next;
    }
    cout << "Wrong account number or password\n";
    return NULL;
}

void deposit(node *user)
{
    double amount;
    cout << "Enter amount to deposit:\n";
    cin >> amount;
    user->balance += amount;
    cout << "Deposit successful. Updated balance: " << user->balance << endl;
}

 node* searchAccount(int accountNumber) {
        node*head;
        node* temp = head;
        while (temp != NULL) {
            if (temp->account_number == accountNumber) 
            {
                cout<<"Account found\n";
                return temp;
            }
            temp = temp->next;
        }
        cout<<"No Account Found\n";
        return NULL; 
    }

void updateAccount(int accountNumber, string newName) {
       node* temp = searchAccount(accountNumber);
        if (temp != NULL)
        {
            temp->name = newName;
            cout << "Account information updated successfully!" << endl;
        } 
        else
        {
            cout << "Account not found!" << endl;
        }
    }

int main()
{
    node *head = NULL;
    cout << "Welcome to ABC Bank\n";

    int ch1, ch2;
    long int check_acc;
    int check_PIN;
    node *current_user = NULL;

    while (true)
    {
        cout << "\nEnter 1 to Create new Account, Enter 2 to Login, 0 to Exit\n";
        cin >> ch1;

        switch (ch1)
        {
        case 1:
            create_account(head);
            break;
        case 2:
            if (head == NULL)
            {
                cout << "No Account Registered\n";
            }
            else
            {
                cout << "Enter Account number\n";
                cin >> check_acc;
                cout << "Enter your PIN\n";
                cin >> check_PIN;
                current_user = login(head, check_acc, check_PIN);
                if (current_user != NULL)
                {
                    while (true)
                    {
                        cout << "\nEnter 1 for View Balance, Enter 2 to Deposit, Enter 0 for Logout\n";
                        cin >> ch2;
                        switch (ch2)
                        {
                        case 1:
                            cout << "Balance: " << current_user->balance << endl;
                            break;
                        case 2:
                            deposit(current_user);
                            break;
                        case 0:
                            current_user = NULL; // Logout
                            break;
                        default:
                            cout << "Wrong input\n";
                        }
                        if (ch2 == 0)
                        {
                            break;
                        }
                    }
                }
            }
            break;
        case 0:
            return 0;
        default:
            cout << "Wrong input\n";
        }
    }

    return 0;
}
