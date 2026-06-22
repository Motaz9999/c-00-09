# 📘 الإتقان في C++: الدليل الشامل لمنهاج مدرسة 42 (Modules 00 - 09)

> **✅ القواعد الأساسية للكتاب (Ground Rules)**
> كل كود برمجي في هذا الكتاب يجب أن يلتزم بالتالي:
> 1. تجميع نظيف وبدون أخطاء باستخدام: `c++ -Wall -Wextra -Werror -std=c++98`
> 2. استخدام حماية الملفات الرأسية (Include Guards) بشكل صحيح `#ifndef / #define / #endif`.
> 3. فصل إعلانات الفئات (`.hpp`) عن التعريفات (`.cpp`).
> 4. يمنع منعاً باتاً استخدام `using namespace std;` في النطاق العام (Global Scope).
> 5. الالتزام بالصيغة الأساسية المعتمدة (Orthodox Canonical Form) بداية من الفصل الثالث.
> 6. يمنع استخدام أي ميزات من C++11 أو أحدث (مثل `auto`, `nullptr`) إلا كملاحظة فقط.

---

## 📊 نظرة عامة على الوحدات (Module-to-Chapter Mapping)

| 42 Module | Chapter(s) | Core Concepts |
| :--- | :--- | :--- |
| **CPP Module 00** | Chapter 1 | Namespaces, I/O Streams, Classes, Constructors, const, static |
| **CPP Module 01** | Chapter 2 | new/delete, References, Member Pointers, File I/O |
| **CPP Module 02** | Chapter 3 | Orthodox Canonical Form, Operator Overloading, Fixed-Point |
| **CPP Module 03** | Chapter 4 | Inheritance, Access Control, Constructor Chaining, Diamond Problem |
| **CPP Module 04** | Chapter 5 | Virtual Functions, Abstract Classes, Interfaces, Slicing |
| **CPP Module 05** | Chapter 6 | Exceptions, Custom Exception Classes, Exception Safety |
| **CPP Module 06** | Chapter 7 | static_cast, dynamic_cast, reinterpret_cast, const_cast |
| **CPP Module 07** | Chapter 8 | Function Templates, Class Templates, Specialization |
| **CPP Module 08** | Chapter 9 | STL Containers, Iterators, Algorithms |
| **CPP Module 09** | Chapter 10 | Advanced STL, Bitcoin Exchange, RPN, PmergeMe |

---

## 📑 الفهرس التفصيلي (Table of Contents)

### PART I — C++ BASIC CONCEPTS (Module 00)
**Chapter 1 — Introduction to C++ and Object-Oriented Programming**
* 1.1 — What Is C++? A Bridge From C
* 1.2 — Namespaces
* 1.3 — The Standard I/O Streams
* 1.4 — Introducing Classes: Encapsulation
* 1.5 — Constructors and Destructors
* 1.6 — Member Initialization Lists
* 1.7 — const Member Functions and Data
* 1.8 — static Members
* 1.9 — Non-Member Functions & Scope

### PART II — MEMORY, POINTERS & REFERENCES (Module 01)
**Chapter 2 — Dynamic Memory and References**
* 2.1 — Stack vs. Heap: A Deep Dive
* 2.2 — new and delete
* 2.3 — References
* 2.4 — Pointers to Members
* 2.5 — File I/O Streams
* 2.6 — switch Statement (C++ Nuances)

### PART III — CANONICAL FORM & OPERATOR OVERLOADING (Module 02)
**Chapter 3 — The Orthodox Canonical Form and Operator Overloading**
* 3.1 — Why We Need a Canonical Form
* 3.2 — The Orthodox Canonical Form (OCF) — The Four Horsemen
* 3.3 — Operator Overloading: Fundamentals
* 3.4 — Comparison and Stream Operators
* 3.5 — Increment / Decrement Operators
* 3.6 — The Assignment Operator in Depth
* 3.7 — Fixed-Point Numbers (Module 02 Context)

### PART IV — INHERITANCE (Module 03)
**Chapter 4 — Inheritance and Class Hierarchies**
* 4.1 — What is Inheritance?
* 4.2 — Access Control in Inheritance
* 4.3 — Constructor and Destructor Chaining
* 4.4 — Overriding Member Functions (Non-Virtual)
* 4.5 — Multiple Inheritance
* 4.6 — The Diamond Problem

### PART V — POLYMORPHISM & ABSTRACT CLASSES (Module 04)
**Chapter 5 — Runtime Polymorphism**
* 5.1 — The Problem That Virtual Functions Solve
* 5.2 — Virtual Functions
* 5.3 — Virtual Destructors
* 5.4 — Pure Virtual Functions and Abstract Classes
* 5.5 — Interfaces in C++
* 5.6 — Deep Copy with Inheritance

### PART VI — EXCEPTIONS (Module 05)
**Chapter 6 — Exception Handling**
* 6.1 — The Problem With Error Codes
* 6.2 — try, throw, catch — The Mechanics
* 6.3 — The Standard Exception Hierarchy
* 6.4 — Custom Exception Classes
* 6.5 — Exception Safety Guarantees
* 6.6 — Common Pitfalls

### PART VII — C++ CASTS (Module 06)
**Chapter 7 — Type Casting in C++**
* 7.1 — Why C-Style Casts Are Dangerous
* 7.2 — static_cast
* 7.3 — dynamic_cast
* 7.4 — reinterpret_cast
* 7.5 — const_cast
* 7.6 — Scalar Type Conversion (Module 06 Context)

### PART VIII — TEMPLATES (Module 07)
**Chapter 8 — Generic Programming with Templates**
* 8.1 — The Problem Templates Solve
* 8.2 — Function Templates
* 8.3 — Class Templates
* 8.4 — Template Specialization
* 8.5 — Non-Type Template Parameters
* 8.6 — The iter and whatever Exercises (Module 07 Context)

### PART IX — CONTAINERS, ITERATORS & ALGORITHMS (Module 08)
**Chapter 9 — The STL: Containers, Iterators, and Algorithms**
* 9.1 — The Standard Template Library Philosophy
* 9.2 — Sequence Containers
* 9.3 — Container Adaptors
* 9.4 — Associative Containers
* 9.5 — Iterators
* 9.6 — STL Algorithms
* 9.7 — The easyfind and Span Exercises (Module 08 Context)

### PART X — ADVANCED STL (Module 09)
**Chapter 10 — Advanced STL and Real-World Applications**
* 10.1 — std::map Deep Dive
* 10.2 — std::stack and RPN Evaluation
* 10.3 — Sorting Algorithms and std::deque / std::list
* 10.4 — Putting It All Together: Design Patterns in C++98

### Appendices
* Appendix A — C++98 Quick Reference Card
* Appendix B — The 42 Compliance Checklist
* Appendix C — Common Compiler Errors Decoded
* Appendix D — Debugging C++ Programs
* Appendix E — Glossary of C++ Terms