#include <iostream>
using namespace std;

// Node class
class Node {
      public:
            int data;
            Node* next;

            Node(int value) {
                  data = value;
                  next = nullptr;
            }
};

// LinkedList class
class LinkedList {
      private:
            Node* head;

      public:
            LinkedList() {
                  head = nullptr;
            }

      // Insert at head
            void insertAtHead(int value) {
                  Node* newNode = new Node(value);
                  newNode->next = head; // purane head ko newNode->next me daal diya
                  head = newNode;       // ab newNode hi head hai
            }

      // Insert at tail
            void insertAtTail(int value) {
                  Node* newNode = new Node(value);

                  if (head == nullptr) {
                        head = newNode;
                        return;
                  }

                  Node* temp = head;
                  while (temp->next != nullptr) {
                        temp = temp->next;
                  }
                  temp->next = newNode;
            }

      // Insert at specific position (1-based index)
            void insertAtPosition(int value, int position) {
                  if (position <= 0) {
                        cout << "Invalid position!" << endl;
                        return;
                  }

                  if (position == 1) {
                        insertAtHead(value);
                        return;
                  }

                  Node* newNode = new Node(value);
                  Node* temp = head;

                  for (int i = 1; i < position - 1 && temp != nullptr; i++) {
                        temp = temp->next;
                  }

                  if (temp == nullptr) {
                        cout << "Position out of range!" << endl;
                        delete newNode;
                        return;
                  }

                  newNode->next = temp->next;
                  temp->next = newNode;
            }

      // Delete at head
            void deleteAtHead() {
                  if (head == nullptr) {
                        cout << "List is empty!" << endl;
                        return;
                  }
                  Node* temp = head;
                  head = head->next;
                  delete temp;
            }

      // Delete at tail
            void deleteAtTail() {
                  if (head == nullptr) {
                        cout << "List is empty!" << endl;
                        return;
                  }
                  if (head->next == nullptr) {
                        delete head;
                        head = nullptr;
                        return;
                  }

                  Node* temp = head;
                  while (temp->next->next != nullptr) {
                        temp = temp->next;
                  }
                  delete temp->next;
                  temp->next = nullptr;
            }

      // Delete at specific position (1-based index)
            void deleteAtPosition(int position) {
                  if (position <= 0 || head == nullptr) {
                        cout << "Invalid position or empty list!" << endl;
                        return;
                  }

                  if (position == 1) {
                        deleteAtHead();
                        return;
                  }

                  Node* temp = head;
                  for (int i = 1; i < position - 1 && temp != nullptr; i++) {
                        temp = temp->next;
                  }

                  if (temp == nullptr || temp->next == nullptr) {
                        cout << "Position out of range!" << endl;
                        return;
                  }

                  Node* nodeToDelete = temp->next;
                  temp->next = nodeToDelete->next;
                  delete nodeToDelete;
            }

      // Print linked list
            void printList() {
                  Node* temp = head;
                  while (temp != nullptr) {
                        cout << temp->data;
                        if (temp->next != nullptr) cout << " -> ";
                        temp = temp->next;
                  }
                  cout << endl;
            }

      // Destructor
            ~LinkedList() {
                  Node* current = head;
                  while (current != nullptr) {
                        Node* nextNode = current->next;
                        delete current;
                        current = nextNode;
                  }
            }
};

// Main function
int main() {
    LinkedList list;

    // Insert elements
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtTail(40);

    cout << "Initial List: ";
    list.printList(); // 10 -> 20 -> 30 -> 40

    // Insert at position
    list.insertAtPosition(15, 2);
    cout << "After inserting 15 at position 2: ";
    list.printList(); // 10 -> 15 -> 20 -> 30 -> 40

    // Delete at head
    list.deleteAtHead();
    cout << "After deleting head: ";
    list.printList(); // 15 -> 20 -> 30 -> 40

    // Delete at tail
    list.deleteAtTail();
    cout << "After deleting tail: ";
    list.printList(); // 15 -> 20 -> 30

    // Delete at position
    list.deleteAtPosition(2);
    cout << "After deleting node at position 2: ";
    list.printList(); // 15 -> 30

    return 0;
}
