#include <iostream>
#include <cstdlib> // Added for rand()

using namespace std;

struct Node {
    float value;
    Node *next;
};

// Function Prototypes
void addNodeFront(Node*& head, float value);
void addNodeTail(Node*& head, float value);
void deleteNode(Node*& head, int postion);
void insertNode(Node*& head, int position, float value);
void deleteList(Node*& head);
void output(Node *head);
int getValidatedInt(string prompt);
float getValidatedFloat(string prompt);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) {
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        } 
        else {
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }

    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    Node *current = head;
    Node *prev = nullptr; // start prev as nullptr to detect head deletion
    
    for (int i = 0; i < (entry - 1); i++) {
        prev = current;
        current = current->next;
    }

    // at this point, delete current and reroute pointers
    if (current) {
        if (prev == nullptr) { 
            // deleting the head node
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        current = nullptr;
    }

    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = nullptr; // reset prev to nullptr for same reason
    
    for (int i = 0; i < entry; i++) {
        prev = current;
        current = current->next;
    }

    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;

    if (prev == nullptr) { 
        // inserting before the head
        head = newnode;
    } else {
        prev->next = newnode;
    }

    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;

    output(head);

    return 0;
}

// function definitions

// definition for addNodeFront
void addNodeFront(Node*& head, float value) {
    Node *newNode = new Node;

    newNode->value = value;
    newNode->next = head;
    head = newNode;
}

// definition for addNodeTail
void addNodeTail(Node*& head, float value) {
    Node *newNode = new Node;

    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

// definition for deleteNode
void deleteNode(Node*& head, int position) {
    if (position < 1) {
        cout << "Invalid position. Positions start at 1.\n";
        return;
    }
    
    Node *current = head;
    Node *previous = nullptr;

    for (int i = 1; i < position && current != nullptr; i++) {
       previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Position exceeds list size. No node deleted.";
        return;
    }

    if (previous == nullptr) {
        head = current->next;
    }
    else {
        previous->next = current->next;
    }
    delete current;

    cout << "Node at position " << position << "deleted.\n";
}

// definition for insertNode
void insertNode(Node*& head, int position, float value) {
    if (position < 0) {
        cout << "Invalid position. Position cannot be negative.\n";
        return;
    }

    Node *current = head;
    Node *previous = nullptr;

    for (int i = 0; i < position; i++) {
        if (current == nullptr) {
            cout << "Position is out of bounds. Node was not inserted.\n";
            return;
        }

        previous = current;
        current = current->next;
    }

    Node *newNode = new Node;

    newNode->value = value;
    newNode->next = current;

    if (previous == nullptr) {
        head = newMode;
    }
    else {
        previous->next = newNode;
    }

    cout << "Node successfully inserted.\n";
}

// definition for deleteList
void deleteList(Node *&head) {
    Node *current = head;

    while (current != nullptr) {
        head = current->next;

        delete current;

        current = head;
    }

    head = nullptr;
}

// definition for output
void output(Node *head) {
    if (!head) {
        cout << "Empty list.\n";
        return;
    }
    
    int count = 1;
    Node *current = head;

    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

// validate the integer input
int getValidationInt(string prompt) {
    int input;

    while (true) {
        cout << prompt;

        if (cin >> input) {
            return input;
        }

        cout << "Error: Invalid input. Please try again.\n";

        cin.clear();
        cin.ignore(1000, '\n');
    }
}

// validate the float input
float getValidatedFloat(string prompt) {
    float input;

    while (true) {
        cout << prompt;

        if (cin >> input) {
            return input;
        }

        cout << "Error: Invalid input. Please try again.\n";

        cin.clear();
        cin.ignore(1000, '\n');
    }
}
