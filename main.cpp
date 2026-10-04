#include <iostream>
#include <cstdlib> // Added for rand()
#include <string>

using namespace std;

struct Node {
    float value;
    Node *next;
};

// Function Prototypes
    // I chose to send the pointer by reference because it allows
    // functions to modify the original head pointer directly without
    // needing to return anew pointer, making the code simpler and 
    // easier to manage.
void addNodeFront(Node*& head, float value);
void addNodeTail(Node*& head, float value);
void deleteNode(Node*& head, int position);
void insertNode(Node*& head, int position, float value);
void deleteList(Node*& head);
void output(Node *head);
int getValidatedInt(string prompt);
float getValidatedFloat(string prompt);

int main() {
    Node *head = nullptr;
    int choice = 0;

    // Add 4 random nodes to list
    for (int i = 0; i < 4; i++) {
        addNodeFront(head, rand() % 100);
    }

    do {
        cout << "       Linked List Menu        \n";
        cout << "-------------------------------\n";
        cout << "1. Add node to the front\n";
        cout << "2. Add node to the end\n";
        cout << "3. Delete a node\n";
        cout << "4. Insert a node\n";
        cout << "5. Delete the entire list\n";
        cout << "6. Print the list\n";
        cout << "7. Exit\n";
        cout << "---------------------------------\n";

        choice = getValidatedInt("Enter your choice (1-7): ");
        cout << endl;

        while (choice < 1 || choice > 7) {
            cout << "Invalid choice. Please enter a number from 1 to 7\n";
            choice = getValidatedInt("Enter your choice (1-7): ");
            cout << endl;
        }

        switch (choice) {
            case 1: {
                float value =  getValidatedFloat(
                    "Enter float value to add to front: "
                );

                addNodeFront(head, value);

                cout << "Node added to front.\n";
                break;
            }

            case 2: {
                float value =  getValidatedFloat(
                    "Enter float value to add to end: "
                );

                addNodeTail(head, value);

                cout << "Node added to end.\n";
                break;
            }

            case 3: {
                if (head == nullptr) {
                    cout << "The list is empty. Nothing to delete.\n";
                    break;
                }

                cout << "Current List:\n";
                output(head);

                int position = getValidatedInt(
                    "Enter the position number of the node to delete: "
                );

                deleteNode(head, position);
                break;
            }

            case 4: {
                cout << "Current List:\n";
                output(head);

                int position = getValidatedInt(
                    "Enter the position after which to insert (0 for front): "
                );

                float value = getValidatedFloat(
                    "Enter float value to insert: "
                );
                
                insertNode(head, position, value);
                break;
            }

            case 5: {
                deleteList(head);

                cout << "The entire list has been cleared.\n";
                break;
            }

            case 6: {
                cout << "Current List contents:\n";
                output(head);
                break;
            }

            case 7: {
                cout << "Exiting\n";
                deleteList(head);
                break;
            }
        }
    } 
        while (choice != 7);

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

    cout << "Node at position " << position << " deleted.\n";
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
        head = newNode;
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
int getValidatedInt(string prompt) {
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
