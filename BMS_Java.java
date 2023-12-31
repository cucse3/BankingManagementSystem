import java.util.Random;
import java.util.Scanner;

class Node {
    String name;
    long accountNumber;
    int PIN;
    double balance = 0.0;
    Node next;

    Node() {}

    Node(String name, int PIN, long accountNumber) {
        this.name = name;
        this.accountNumber = accountNumber;
        this.PIN = PIN;
        balance = 0.0;
        next = null;
    }
}

public class BMS {
    static Scanner scanner = new Scanner(System.in);

    static long generateAccountNumber() {
        Random rand = new Random();
        return 1000 + rand.nextInt(9000);
    }

    static Node createAccount(Node head) {
        String name;
        int PIN;
        long accountNumber = generateAccountNumber();

        System.out.println("Enter your name:");
        scanner.nextLine();
        name = scanner.nextLine();
        System.out.println("Your Account number is: " + accountNumber);
        System.out.println("Set a PIN for your account:");

        while (true) {
            try {
                PIN = scanner.nextInt();
                break;
            } catch (Exception e) {
                System.out.println("Invalid PIN. Please enter a valid number:");
                scanner.next(); // solve invalid input
            }
        }

        Node newNode = new Node(name, PIN, accountNumber);

        if (head == null) {
            head = newNode;
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }

        System.out.println("\nAccount created successfully");
        System.out.println("Name: " + name);
        System.out.println("Account number: " + accountNumber);
        return head;
    }

    static Node login(Node head, long checkAccount, int checkPIN) {
        Node temp = head;
        while (temp != null) {
            if (temp.accountNumber == checkAccount && temp.PIN == checkPIN) {
                System.out.println("Login successful");
                return temp;
            }
            temp = temp.next;
        }
        System.out.println("Wrong account number or password");
        return null;
    }

    static void deposit(Node user) {
        double amount;
        try {
            System.out.println("Enter amount to deposit:");
            amount = scanner.nextDouble();
            user.balance += amount;
            System.out.println("Deposit successful. Updated balance: " + user.balance);
        } catch (Exception e) {
            System.out.println("Invalid input. Please enter a valid amount.");
            scanner.next(); // solve invalid input
        }
    }

    static void withdraw(Node user) {
        double amount;
        try {
            System.out.println("Enter amount to withdraw:");
            amount = scanner.nextDouble();
            if (amount <= user.balance) {
                user.balance -= amount;
                System.out.println("Withdrawal successful. Updated balance: " + user.balance);
            } else {
                System.out.println("Insufficient balance");
            }
        } catch (Exception e) {
            System.out.println("Invalid input. Please enter a valid amount.");
            scanner.next(); // solve invalid input
        }
    }

    static Node updateAccount(Node head, long accountNumber, int newPIN) {
        Node temp = head;
        while (temp != null) {
            if (temp.accountNumber == accountNumber) {
                temp.PIN = newPIN;
                System.out.println("Account information updated successfully!");
                break;
            }
            temp = temp.next;
        }
        return head;
    }

    static Node deleteAccount(Node head, long accountNumber) {
        Node temp = head;
        Node prev = null;

        while (temp != null) {
            if (temp.accountNumber == accountNumber) {
                if (prev == null) {
                    head = temp.next;
                } else {
                    prev.next = temp.next;
                }

                System.out.println("Account deleted successfully!");
                return head;
            }
            prev = temp;
            temp = temp.next;
        }
        System.out.println("Account not found!");
        return head;
    }

    public static void main(String[] args) {
        Node head = null;
        System.out.println("Welcome to ABC Bank");

        int ch1, ch2;
        long checkAcc;
        int checkPIN;
        Node currentUser = null;

        while (true) {
            try {
                System.out.println("\nEnter 1 to Create new Account, Enter 2 to Login, Enter 3 to Update Account info, Enter 4 to Delete Account, 0 to Exit");
                ch1 = scanner.nextInt();

                switch (ch1) {
                    case 1:
                        head = createAccount(head);
                        break;
                    case 2:
                        if (head == null) {
                            System.out.println("No Account Registered");
                        } else {
                            System.out.println("Enter Account number");
                            checkAcc = scanner.nextLong();
                            System.out.println("Enter your PIN");
                            checkPIN = scanner.nextInt();
                            currentUser = login(head, checkAcc, checkPIN);
                            if (currentUser != null) {
                                while (true) {
                                    System.out.println("\nEnter 1 for View Balance, Enter 2 to Deposit, Enter 3 to Withdraw, Enter 0 for Logout");
                                    ch2 = scanner.nextInt();
                                    switch (ch2) {
                                        case 1:
                                            System.out.println("Balance: " + currentUser.balance);
                                            break;
                                        case 2:
                                            deposit(currentUser);
                                            break;
                                        case 3:
                                            withdraw(currentUser);
                                            break;
                                        case 0:
                                            currentUser = null;
                                            break;
                                        default:
                                            System.out.println("Wrong input");
                                    }
                                    if (ch2 == 0) {
                                        break;
                                    }
                                }
                            }
                        }
                        break;
                    case 3:
                        if (head == null) {
                            System.out.println("No Account Registered");
                        } else {
                            long accountNumber;
                            int newPIN;
                            System.out.print("Enter account number for PIN update: ");
                            accountNumber = scanner.nextLong();
                            System.out.print("Enter new PIN: ");
                            newPIN = scanner.nextInt();
                            head = updateAccount(head, accountNumber, newPIN);
                            System.out.println("Login Details:");
                            System.out.println("Account number: " + accountNumber);
                            System.out.println("PIN: " + newPIN);
                        }
                        break;
                    case 4:
                        if (head == null) {
                            System.out.println("No Account Registered");
                        } else {
                            System.out.print("Enter Account number to delete: ");
                            long deleteAcc;
                            deleteAcc = scanner.nextLong();
                            head = deleteAccount(head, deleteAcc);
                        }
                        break;
                    case 0:
                        System.out.println("Exiting...");
                        scanner.close();
                        System.exit(0);
                    default:
                        System.out.println("Wrong input. Please enter a valid option.");
                }
            } catch (Exception e) {
                System.out.println("Invalid input or operation failed. Please try again.");
                scanner.next(); // solve invalid input
            }
        }
    }
}
