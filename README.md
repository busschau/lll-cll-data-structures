# Linked-List Data Structures (LLL & CLL) – C++ Implementation

This repository contains my implementation of two custom data structures — a Linear Linked List (LLL) and a Circular Linked List (CLL) — along with a small application demonstrating object-oriented programming concepts such as inheritance, polymorphism, and mixed data storage using both linked lists and vectors.

The project models a festival-style management system with multiple item types (vendors, food stands, stages, lots, etc.), each derived from a common base class. This makes the code a blend of data structures, OOP design, and practical C++ programming.

---

## Purpose

This project was developed to strengthen my understanding of:

- Manual data structure implementation (LLL & CLL)
- Pointer management and dynamic memory in C++
- Object-oriented programming:
  - inheritance  
  - polymorphism  
- Combining STL containers with custom structures:
  - vectors for indexed storage
  - linked lists for dynamic insertion/removal
- Real-world-minded modeling using C++ classes

This project is an authentic, from-scratch implementation done as part of my coursework.

---

## Repository Structure

```
lll-cll-data-structures/
├── Node.cpp / CLL_LLL.h                    # Node definitions
├── LLL.cpp / CLL_LLL.h                  # Linear linked list implementation
├── CLL.cpp                              # Circular linked list implementation
├── vendor.cpp / vendor.h                # Base class
├── food.cpp / vendor.h                    # Derived class
├── stage.cpp / vendor.h                  # Derived class
├── lot.cpp / vendor.h                      # Derived class
├── main.cpp / application.cpp           # Demo + vector usage
└── (supporting files)
```

---

## Features

### Linked List Implementations

**Linear Linked List (LLL):**
- Insert nodes  
- Remove nodes  
- Traverse items  
- Clear memory  

**Circular Linked List (CLL):**
- Rear-pointer circular list  
- Circular traversal logic  
- Insert/remove operations  
- Dynamic memory handling  

---

## Object-Oriented Design (Inheritance & Polymorphism)

The project uses a base class (`vendor`) from which multiple item types inherit:

- `food`
- `stage`
- `lot`

This demonstrates:

- Shared behavior via a common interface  
- Overriding functions in derived classes  
- Polymorphic function calls  
- Realistic modeling of different types of festival “entities”  

---

## Vector-Based Storage

Alongside linked lists, the program also uses `std::vector` to store items.

This provides:
- Fast indexed access  
- A contrast to pointer-driven list traversal  
- A real-world example of mixing STL containers with custom data structures  

---

## Demo Application

The included demo files:
- Create several derived item objects  
- Store them in both vectors and linked lists  
- Output information polymorphically  
- Demonstrate list insertion, traversal, and deletion  

This shows how custom data structures and OOP components can work together in a multi-file C++ program.

---

## Build & Run

Clone the repository:

```bash
git clone https://github.com/busschau/lll-cll-data-structures.git
cd lll-cll-data-structures
```

Compile:

```bash
g++ *.cpp -o festival_list_demo
```

Run:

```bash
./festival_list_demo
```

---

## What This Project Demonstrates (For Employers)

- Strong understanding of core data structures  
- Ability to implement linked lists manually without STL  
- Solid grasp of C++ classes, inheritance, and polymorphism  
- Pointer manipulation and dynamic memory management  
- Multi-file program organization  
- Combining STL (`vector`) with custom data structures  
- Designing reusable and modular code  

---

## Possible Future Enhancements

- Convert raw pointers to smart pointers  
- Add RAII cleanup patterns  
- Add unit tests  
- Add file I/O (save/load items)  
- Expand the item system with additional subclasses  

---

## About the Author

I'm a Computer Science student at Portland State University with interests in systems programming, data structures, and cybersecurity. This project showcases my practical experience building core structures and object-oriented C++ software from the ground up.


