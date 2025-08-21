#include <iostream>
#include <string>
using namespace std;

// Web Structure
struct Website {
    string url;
    string title;
    Website* next;

    Website(string u, string t) : url(u), title(t), next(nullptr) {}
};

// Stack class using linked list
class Stack {
private:
    Website* top;

public:
    Stack() : top(nullptr) {}

    bool isEmpty() {
        return top == nullptr;
    }

    // Push new website
    void push(string url, string title) {
        Website* newSite = new Website(url, title);
        newSite->next = top;
        top = newSite;
    }

    // Pop website
    Website* pop() {
        if (isEmpty()) {
            return nullptr;
        }
        Website* temp = top;
        top = top->next;
        temp->next = nullptr;
        return temp;
    }

    // Peek 
    Website* peek() {
        return top;
    }

    // Display stack content
    void display() {
        if (isEmpty()) {
            cout << "[Empty stack]\n";
            return;
        }
        Website* temp = top;
        while (temp != nullptr) {
            cout << temp->title << " (" << temp->url << ")\n";
            temp = temp->next;
        }
    }

    // Clear stack
    void clear() {
        while (!isEmpty()) {
            Website* temp = pop();
            delete temp;
        }
    }
};

// Navigation System
class BrowserNavigation {
private:
    Stack backward;
    Stack forward;

public:
    // Visit new website
    void visit(string url, string title) {
        backward.push(url, title);
        forward.clear(); 
        cout << "Visited: " << title << " (" << url << ")\n";
    }

    // Go back
    void goBack() {
        if (backward.isEmpty()) {
            cout << "No history to go back\n";
            return;
        }

        Website* site = backward.pop();
        forward.push(site->url, site->title);
        delete site;

        if (!backward.isEmpty()) {
            cout << "Back to: " << backward.peek()->title 
                 << " (" << backward.peek()->url << ")\n";
        } else {
            cout << "No more websites in history\n";
        }
    }

    // Go forward
    void goForward() {
        if (forward.isEmpty()) {
            cout << "No forward history available\n";
            return;
        }

        Website* site = forward.pop();
        backward.push(site->url, site->title);
        cout << "Forward to: " << site->title << " (" << site->url << ")\n";
        delete site;
    }

    // Display history
    void displayHistory() {
        cout << "\nBackward Stack\n";
        backward.display();
        cout << "Forward Stack\n";
        forward.display();
    }
};

// Main function to test
int main() {
    BrowserNavigation browser;

    browser.visit("https://google.com", "Google");
    browser.visit("https://youtube.com", "YouTube");
    browser.visit("https://github.com", "GitHub");
    browser.displayHistory();

    cout << "\nGoing back...\n";
    browser.goBack();
    browser.displayHistory();

    cout << "\nGoing back again...\n";
    browser.goBack();
    browser.displayHistory();

    cout << "\nGoing forward...\n";
    browser.goForward();
    browser.displayHistory();

    cout << "\nVisiting new website...\n";
    browser.visit("https://stackoverflow.com", "StackOverflow");
    browser.displayHistory();

    return 0;
}
