/*
Exercise 2: Assume that a railway train has N railroad cars attached together
such as car1, car2, car3, ..., carN . A train can be considered as a list and each car
corresponds to a node in this list.
1
 Each car carries a maximum capacity of passengers (int type) and has an id
(char type). Both variables are user-defined values.
 Each car is reserved by a number of passengers (int type) (which should be
less than its capacity). If there are any cars that don’t have any passengers,
they should be removed from the train.
 It is possible to add new cars to the train.
 A function is available to display all cars’ information or the length of the
train.
Implement a program in C/C++ using Linked List to manage the train and test all
functions
*/

#include <iostream>
#include <string>
using namespace std;

// Node structure for each train car
struct Car {
    char id;          // car ID
    int capacity;     // max passengers
    int reserved;     // reserved passengers
    Car* next;        // pointer to next car

    // Constructor
    Car(char i, int c, int r) : id(i), capacity(c), reserved(r), next(nullptr) {}
};

// Linked List class to manage the train
class Train {
private:
    Car* head; // pointer to first car

public:
    // Constructor
    Train() : head(nullptr) {}

    // Destructor 
    ~Train() {
        while (head != nullptr) {
            Car* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Add new car at the end
    void addCar(char id, int capacity, int reserved) {
        if (reserved >= capacity) {
            cout << "Error: reserved passengers must be less than capacity\n";
            return;
        }

        Car* newCar = new Car(id, capacity, reserved);

        if (head == nullptr) {
            head = newCar;
        } else {
            Car* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newCar;
        }
    }

    // Remove cars with 0 passengers
    void removeEmptyCars() {
        while (head != nullptr && head->reserved == 0) {
            Car* temp = head;
            head = head->next;
            delete temp;
        }

        Car* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->reserved == 0) {
                Car* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }

    // Display all cars
    void displayTrain() {
        if (head == nullptr) {
            cout << "Train is empty\n";
            return;
        }

        Car* temp = head;
        cout << "Train composition:\n";
        while (temp != nullptr) {
            cout << "Car ID: " << temp->id 
                 << " | Capacity: " << temp->capacity 
                 << " | Reserved: " << temp->reserved << endl;
            temp = temp->next;
        }
    }

    int getLength() {
        int count = 0;
        Car* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    Train train;

    train.addCar('A', 50, 20);
    train.addCar('B', 60, 0);
    train.addCar('C', 40, 15);
    train.addCar('D', 30, 0);
    train.addCar('E', 70, 50);

    cout << "Initial Train:\n";
    train.displayTrain();
    cout << "Train length: " << train.getLength() << endl << endl;

    // Remove empty cars
    cout << "After removing empty cars:\n";
    train.removeEmptyCars();
    train.displayTrain();
    cout << "Train length: " << train.getLength() << endl << endl;

    // Add another car
    cout << "Adding a new car:\n";
    train.addCar('F', 100, 80);
    train.displayTrain();
    cout << "Train length: " << train.getLength() << endl;

    return 0;
}
