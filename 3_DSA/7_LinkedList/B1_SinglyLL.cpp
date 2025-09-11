// 🔹 Singly Linked List implementation in C++

#include <iostream>
using namespace std;

// Node class
class Node {
    public:
      int data;     // value store karega
      Node* next;   // next node ka address store karega

      // Constructor
      Node(int value) {
            data = value;
            next = nullptr; // initially null
      }
};

// LinkedList class
class LinkedList {
   private:
      Node* head;   // list ka starting point

   public:
      LinkedList() {
            head = nullptr;   // initially list empty hai
      }

      // Insert node at end
      void insert(int value) {
            Node* newNode = new Node(value);

            if (head == nullptr) {
                  head = newNode; // agar list empty hai to head = newNode
            } else {
                  Node* temp = head;
                  while (temp->next != nullptr) {  // last node tak jao
                  temp = temp->next;
                  }
                  temp->next = newNode;  // last node ke next me newNode daal do
            }
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

      // Destructor (memory free karega)
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

    // Elements insert karna
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    // Print linked list
    cout << "Linked List: ";
    list.printList();   // Output: 10 -> 20 -> 30 -> 40

    return 0;
}




-------------------------------------------------------------------------------------------------
// 🔹 Singly Linked List implementation in C++ using Generics (Templates)

#include <iostream>
using namespace std;

// Tumhara diya hua generic Node class
template <typename T>
class Node {
      private:
            T data;
            Node<T>* next;

      public:
            Node(const T& value) : data(value), next(nullptr) {}

            T getData() const { return data; }
            void setData(const T& value) { data = value; }

            Node<T>* getNext() const { return next; }
            void setNext(Node<T>* node) { next = node; }

            void printNode() const {
                  cout << data;
                  if (next) cout << " -> ";
            }
};

// 🔹 LinkedList class (sirf demo ke liye)
class LinkedList {
      private:
            Node<int>* head;

      public:
            LinkedList() : head(nullptr) {}

            // Insert node at end
            void insert(int value) {
                  Node<int>* newNode = new Node<int>(value);

                  if (!head) {
                        head = newNode;
                        return;
                  }

                  Node<int>* temp = head;
                  while (temp->getNext() != nullptr) {
                        temp = temp->getNext();
                  }
                  temp->setNext(newNode);
            }

            // Print the list
            void printList() const {
                  Node<int>* temp = head;
                  while (temp != nullptr) {
                        temp->printNode();
                        temp = temp->getNext();
                  }
                  cout << endl;
            }

            // Destructor to free memory
            ~LinkedList() {
                  Node<int>* current = head;
                  while (current != nullptr) {
                        Node<int>* nextNode = current->getNext();
                        delete current;
                        current = nextNode;
                  }
            }
};

// 🔹 Main function
int main() {
    LinkedList list;

    // Insert elements: 10, 20, 30, 40
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    // Print linked list
    cout << "Linked List: ";
    list.printList();  // Output: 10 -> 20 -> 30 -> 40

    return 0;
}
