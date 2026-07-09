/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice02.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 21:24:08 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/09 22:30:05 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//operators are symbols that tell the compiler to preform specific mathematical, logical, or data-manipulation operations.

//arithmetic ops
//+ - * % / 
//assignment ops
// =   += -=  *= /= %=
//relational (Comparison) ops
//==  != > <  <= >=
//logical ops
//&& || ! 
//bitwise ops
// & | ^ << >> 

//stream io ops
// << >> 
//Memory & pointers ops
//& address * deference new new[] dynamic allocation delete delete[] deallocation -> Member Selection via pointer . Member Selection via Object

//Miscellaneous Operators
//sizeof() ?:-> condition ? expression_if_true : expression_if_false;
// , :: 


//each operator are a fun
//like the a + b the + here is operator+ fun 


//btw the cpp allows me to define what the fun dose when its operands are your

//Rules for operators overloading 
//1. some ops must be MEMBERS OF THE CLASS
//operator=  this for copy the obj elements  
// , operator[] for array 
// , operator() make the the obj as fun 
// , operator-> for ptr
//all these just FOR MEMBER CLASS USE
//[] = () -> 


//stream ops must be FREE OPS
//(std::cout) (<<) (obj)  the left is (std::cout) is std::ostream that class have no member
//


#include <iostream>
#include <cassert>

class SmartArray
{
    private :
    int *_data;
    int _size; 
    public :  
    SmartArray(int size): _data(NULL), _size(size)
    {
        _data = new int[_size];
        
    }
    ~SmartArray()
    {
        delete []_data;
    }

    //all the blow from RULE 1 as part of the class
    // =========================================================================
    // RULE 1: MUST BE MEMBERS (Enforced by C++ Standard)
    // =========================================================================
    SmartArray& operator=(SmartArray const &other)
    {
         if (this == &other)
         return *this;
         _size = other._size; 
         delete [] _data ;
         _data = NULL; 
         _data  = new int[_size];
         for (int i = 0; i < _size; i++)
         {
            _data[i] = other._data[i];
         }
         return *this; 
    }

    //allows array syntax to look like this obj[] so we can assign like i want to use to return an element
    int& operator[](int index)
    {
        return _data[index];
    }

    //this let me call the obj as fun objName() and assign something to do with it
    void operator()()
    {
        std::cout << "[Function Call Triggered] Processing array data...\n";
    }
    //next is member selection via pointer
    // To demonstrate this purely, we return the pointer to this object
    SmartArray* operator-> ()
    {
        return this ; 
    }
    
    void displayDebug()
    {
        std::cout << " DEBUG: Internal Array Size : " << _size <<std::endl; 
    }
//now the rule 4 also as part of class =+ -= 
    // =========================================================================
    // RULE 4: COMPOUND ASSIGNMENT BELONGS AS MEMBERS (Modifies in-place)
    // =========================================================================
    
    //adds a flat value to all elements inside this array directly 
    SmartArray& operator+=(int value)
    {
        for (int i = 0; i < _size; i++)
        {
            _data[i] += value;
        }
        return *this;
    }
    int getSize () const 
    {
        return _size;
    }
};


// =============================================================================
// RULE 2: STREAM OPERATORS MUST BE NON-MEMBERS (Left operand is std::ostream)
// =============================================================================

//ok its like i want to output the all array inside an obj but using cout only
//the first obj is os -> std::cout and the 2 is obj of array
std::ostream& operator<<( std::ostream& os , SmartArray const &arr )
{
    os << "[";
    for (int i = 0; i < arr.getSize(); i++)
    {
        os << const_cast <SmartArray &>(arr) [i] << " , " ;
    }
    os << "]" << std::endl;
    return os; //we continue with the chaining with          
}


//after streaming the last rule is 3 
// =============================================================================
// RULE 3: SYMMETRIC BINARY OPERATORS PREFER NON-MEMBER (Symmetric Conversions)
// =============================================================================
//like * + - / %
//we can make it inside the class but it will operate on 1 obj must be left
//and it return a new array have both element from the first array and the sec
SmartArray operator+(SmartArray const & arr1 , SmartArray const &arr2)
{
    SmartArray newArr(SmartArray(arr1.getSize() + arr2.getSize()));
    int i = 0 ; 
    while (i < arr1.getSize())
    {
        newArr[i] = const_cast <SmartArray &> (arr1)[i]; 
        i++;
    }
    int j = 0;
    while ( j < arr2.getSize() )
    {
        
        newArr[i + j] = const_cast <SmartArray &> (arr2)[j]; 
        j++;
    }
    return newArr ; 
}


int main() {
    // Creating initial arrays
    SmartArray a(3);
    a[0] = 10; a[1] = 20; a[2] = 30; // Using Rule 1: operator[]
    


    

    SmartArray b(3);
    b[0] = 5;  b[1] = 5;  b[2] = 5;


    
    // 1. Testing Rule 2: Stream insertion operator (<<)
    std::cout << "Array A: " << a << "\n"; // Prints: [ 10 20 30 ]
    std::cout << "Array B: " << b << "\n"; // Prints: [ 5 5 5 ]

    
    
    
    // 2. Testing Rule 3: Symmetric binary addition (+)
    SmartArray c = a + b; 
    std::cout << "Array C (A + B): " << c << "\n"; // Prints: [all ]



    
    // 3. Testing Rule 4: Compound Assignment (+=)
    c += 10; // Modifies array c in place it mean it take the same obj and take the value and add all values to the array and return the obj 
    //it looks like this c.operate+=(10)  
    std::cout << "Array C after += 10: " << c << "\n"; // Prints: [ 25 35 45 ]



    
    // 4. Testing Rule 1: Copy Assignment (=) deep-copying memory
    SmartArray d(3);
    d = c; // Deep copy executed
    
    d[0] = 999; // Changing d does NOT alter c because they are separate on the heap!
    
    std::cout << "Array D (Modified): " << d << "\n"; // Prints: [ 999 35 45 ]
    
    std::cout << "Array C (Untouched): " << c << "\n"; // Prints: [ 25 35 45 ]

    // 5. Testing Rule 1: Function call operator (())
    
    c(); // Invokes the object like a function call

    // 6. Testing Rule 1: Pointer Member Selection operator (->)

    c->displayDebug(); // Executes via the custom overloaded arrow mapping

    return 0;
}