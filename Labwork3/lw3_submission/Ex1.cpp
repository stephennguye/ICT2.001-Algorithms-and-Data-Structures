#include <iostream>
#include <string>
using namespace std;

// Structure for an item in stock
struct Item {
    string name;
    int quantity;
    double price;
};

// Structure for a customer in the queue
struct Customer {
    string name;    // customer name
    string item;    // item they want
    int quantity;   // quantity they want
    Customer* next;

    Customer(string n, string i, int q) 
        : name(n), item(i), quantity(q), next(nullptr) {}
};

// Queue for customers
class CustomerQueue {
private:
    Customer* front;
    Customer* rear;

public:
    CustomerQueue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue
    void enqueue(string name, string item, int quantity) {
        Customer* newCustomer = new Customer(name, item, quantity);
        if (rear == nullptr) {
            front = rear = newCustomer;
        } else {
            rear->next = newCustomer;
            rear = newCustomer;
        }
        cout << name << " has entered the queue.\n";
    }

    // Remove a customer (dequeue) and process their purchase
    void dequeue(Item items[], int n) {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        Customer* temp = front;
        string itemName = temp->item;
        int qty = temp->quantity;
        bool found = false;

        // Process purchase
        for (int i = 0; i < n; i++) {
            if (items[i].name == itemName) {
                found = true;
                if (items[i].quantity >= qty) {
                    items[i].quantity -= qty;
                    cout << temp->name << " successfully bought " << qty 
                         << " of " << itemName << ".\n";
                } else {
                    cout << "Sorry " << temp->name << ", not enough stock for " 
                         << itemName << ".\n";
                }
                break;
            }
        }

        if (!found) {
            cout << "Item " << itemName << " does not exist.\n";
        }

        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
    }

    // Display queue
    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Current queue:\n";
        Customer* temp = front;
        while (temp != nullptr) {
            cout << temp->name << " wants " << temp->quantity 
                 << " of " << temp->item << endl;
            temp = temp->next;
        }
    }
};

// Display items in stock
void displayItems(Item items[], int n) {
    cout << "\nItems in stock:\n";
    for (int i = 0; i < n; i++) {
        cout << items[i].name << " | Qty: " << items[i].quantity 
             << " | Price: $" << items[i].price << endl;
    }
    cout << endl;
}

int main() {
    int n = 3;
    Item items[3] = {
        {"Laptop", 5, 1200.0},
        {"Phone", 10, 800.0},
        {"Headphones", 7, 150.0}
    };

    CustomerQueue q;

    cout << "Beginning Stock:\n";
    displayItems(items, n);

    // Enqueue customers
    q.enqueue("Alice", "Laptop", 1);
    q.enqueue("Bob", "Phone", 2);
    q.enqueue("Charlie", "Headphones", 3);
    q.enqueue("David", "Phone", 9);   
    q.enqueue("Eve", "Tablet", 1);    

    cout << "\nQueue after enqueuing:\n";
    q.displayQueue();

    q.dequeue(items, n);  // Alice
    q.dequeue(items, n);  // Bob
    q.dequeue(items, n);  // Charlie
    q.dequeue(items, n);  // David
    q.dequeue(items, n);  // Eve

    displayItems(items, n);

    return 0;
}
