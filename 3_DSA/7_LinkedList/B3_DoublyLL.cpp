      #include <iostream>
      using namespace std;

      struct Node {
            int data;
            Node* prev;
            Node* next;

            Node(int val) {
                  data = val;
                  prev = next = nullptr;
            }
      };

      class DoublyLinkedList {
            private:
                  Node* head;

            public:
                  DoublyLinkedList() { head = nullptr; }

            // Insert at head
            void insertAtHead(int val) {
                  Node* newNode = new Node(val);
                  if (head != nullptr) {
                        newNode->next = head;
                        head->prev = newNode;
                  }
                  head = newNode;
            }

            // Insert at tail
            void insertAtTail(int val) {
                  Node* newNode = new Node(val);

                  if (head == nullptr) {  // if list empty
                        head = newNode;
                        return;
                  }

                  Node* temp = head;
                  while (temp->next != nullptr) {
                        temp = temp->next;
                  }

                  temp->next = newNode;
                  newNode->prev = temp;
            }

            // Insert at given position (1-based index)
            void insertAtPosition(int pos, int val) {
                  if (pos <= 1) {  // insert at head if pos = 1 or less
                        insertAtHead(val);
                        return;
                  }

                  Node* temp = head;
                  int count = 1;

                  while (temp != nullptr && count < pos - 1) {
                        temp = temp->next;
                        count++;
                  }

                  if (temp == nullptr) {  // position > length -> insert at tail
                        insertAtTail(val);
                        return;
                  }

                  Node* newNode = new Node(val);
                  newNode->next = temp->next;
                  newNode->prev = temp;

                  if (temp->next != nullptr) {
                        temp->next->prev = newNode;
                  }

                  temp->next = newNode;
            }

            // Delete node by position (1-based index)
            void deleteAtPosition(int pos) {
                  if (head == nullptr) return;

                  Node* temp = head;

                  if (pos == 1) { // deleting head node
                        head = head->next;
                        if (head != nullptr)
                        head->prev = nullptr;
                        delete temp;
                        return;
                  }

                  int count = 1;
                  while (temp != nullptr && count < pos) {
                        temp = temp->next;
                        count++;
                  }

                  if (temp == nullptr) return; // position > length

                  if (temp->next != nullptr)
                        temp->next->prev = temp->prev;

                  if (temp->prev != nullptr)
                        temp->prev->next = temp->next;

                  delete temp;
            }

            void displayForward() {
                  Node* temp = head;
                  while (temp != nullptr) {
                        cout << temp->data << " <-> ";
                        temp = temp->next;
                  }
                  cout << "NULL\n";
            }

            void displayBackward() {
                  if (head == nullptr) return;
                  Node* temp = head;
                  while (temp->next != nullptr) {
                        temp = temp->next;
                  }
                  while (temp != nullptr) {
                        cout << temp->data << " <-> ";
                        temp = temp->prev;
                  }
                  cout << "NULL\n";
            }
      };

      // Test the class
      int main() {
            DoublyLinkedList dll;

            dll.insertAtHead(10);
            dll.insertAtHead(20);
            dll.insertAtTail(5);
            dll.insertAtTail(1);
            dll.insertAtPosition(3, 15); // position = 3
            dll.displayForward();

            dll.deleteAtPosition(2);  // delete node at position 2
            dll.displayForward();

            cout << "Backward Traversal: ";
            dll.displayBackward();

            return 0;
      }
