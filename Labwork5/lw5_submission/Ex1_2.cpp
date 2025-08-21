#include <iostream>
#include <stack>
using namespace std;

// Function to sort stack using insertion sort logic
void sortStack(stack<int>& s) {
    if (s.empty()) return;

    // Remove top element
    int top = s.top();
    s.pop();

    // Sort remaining stack
    sortStack(s);

    // Insert top element in correct position
    stack<int> temp;
    while (!s.empty() && s.top() > top) {
        temp.push(s.top());
        s.pop();
    }
    s.push(top);

    // Restore elements
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }
}

void displayStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(12);
    s.push(11);
    s.push(13);
    s.push(5);
    s.push(6);

    cout << "Original stack (top to bottom):\n";
    displayStack(s);

    s.push(12);
    s.push(11);
    s.push(13);
    s.push(5);
    s.push(6);

    sortStack(s);

    cout << "Sorted stack (top to bottom):\n";
    displayStack(s);

    return 0;
}
