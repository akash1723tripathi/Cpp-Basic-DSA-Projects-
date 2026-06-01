# C++ Basics & DSA Mastery

Welcome to my C++ Data Structures and Algorithms repository! This space documents my systematic approach to mastering competitive programming concepts, core computer science fundamentals, and advanced problem-solving techniques. 

## 🗂️ Repository Structure

This repository is organized progressively to build a strong foundation before tackling advanced algorithmic challenges:

* **`1_Basics/`**: Core C++ syntax, memory management, and standard template library (STL) usage.
* **`2_Oops/`**: Object-Oriented Programming concepts in C++ (Classes, Inheritance, Polymorphism).
* **`3_DSA/`**: Implementations of various Data Structures and Algorithms, categorized by patterns.
* **`4_Projects/`**: Applied projects demonstrating the use of C++ logic in real-world scenarios.
* **`DSA_Decision_Chart.pdf`**: A quick-reference guide for choosing the right data structure/algorithm for specific constraints.

## 🗺️ DSA Learning Roadmap

Below is the strategic roadmap I am following to conquer both foundational problem-solving (Phase 1) and complex optimization problems (Phase 2).

```mermaid
graph TD
    subgraph Phase 1
        DS[Data Structure] --> A[Array]
        DS --> Str[String]
        DS --> H[Hashing]

        A --> TP[Two Pointers]
        A --> PS[Prefix Sum]
        A --> Search[Searching]
        
        TP --> SW[Sliding Window]
        Search --> BS[Binary Search]
        
        H --> St[Stack]
        St --> Q[Queue]
        Q --> LL[Linked List]
        LL --> T[Tree]
    end

    subgraph Phase 2
        T --> Rec[Recursion]
        T --> Hp[Heap]
        T --> Tr[Tries]
        
        Rec --> BT[Backtracking]
        BT --> G[Graph]
        G --> DP[Dynamic Programming]
        
        DP --> 1DP[1-DP]
        DP --> 2DP[2-DP]
        DP --> BM[Bit Manipulation]
        
        Hp --> Gr[Greedy]
        Hp --> Int[Intervals]
        
        G --> AG[Advanced Graph]
        Gr --> AG
    end
