//Approach 1:  using stack implementation via linked list
class MinStack {
private:
      struct Node {
            int data;
            int minNow;
            Node* next;

            Node(int val, int minVal, Node* nextNode) 
                  : data(val), minNow(minVal), next(nextNode) {}  
      };

      Node* head = nullptr;

public:
      MinStack() = default;
      
      void push(int val) {
            int newMin = (head == nullptr) ? val : std::min(val, head->minNow);
            head = new Node(val, newMin, head);
      }
    
      void pop() {
            Node* temp = head;
            head = head->next;
            delete temp;
      }
      
      int top() {
            return head->data;
      }
    
      int getMin() {
            return head->minNow;
      }
};



//Approach 2: using two stack
class MinStack {
private:
      stack<int> st;   // normal values
      stack<int> mn;   // current minimums

public:
      MinStack() {}

      void push(int val) {
            st.push(val);
            if (mn.empty() || val <= mn.top()) {
                  mn.push(val);
            }
      }
      
      void pop() {
            if (st.top() == mn.top()) {
                  mn.pop();
            }
            st.pop();
      }
      
      int top() {
            return st.top();
      }
      
      int getMin() {
            return mn.top();
      }
};


//using stack with pairs

class MinStack {
private:
      stack<pair<int,int>> st;

public:
      MinStack() {}

      void push(int val) {
            if (st.empty()) {
                  st.push({val, val});
            } else {
                  int currentMin = min(val, st.top().second);
                  st.push({val, currentMin});
            }
      }
      
      void pop() {
            st.pop();
      }
      
      int top() {
            return st.top().first;
      }
      
      int getMin() {
            return st.top().second;
      }
};
