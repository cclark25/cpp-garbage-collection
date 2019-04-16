# cpp-garbage-collection
A C++ resource file implementing a template class used to safely create objects on the heap.

# Description
The purpose of this project is to demonstrate a simple method of memory management one the heap in C++.
The code in this project mimics the functionality of normal objects in Java. By wrapping any object in the template "Condom<T>",
it can exist on the heap, rather than on the stack, and delete itself upon all referrences to it being removed. 
Like a Java object, when it is passed as an argument into a function, the internal data is strictly passed by referrence rather
than by value like C++ usually defaults to.

# Usage
The following code demonstrates using the template:

 #include "Condom.hxx"
 #include <iostream>
 using namespace Condoms;
 using namespace std;
 
 int main(){
    Condom<int> x = 4;
    Condom<int> y = x;
    
    cout << x << endl;
    cout << y << endl;
    
    x++;
    
    cout << x << endl;
    cout << y << endl;
 }


The above code will print the following output:

  4
  4
  5
  5
  
Since a Condom is a referrence, declaring a new Condom and initializing it with another results in two referrences to the same 
data, so changes to one happen to the other as well. Every operator is overridden on the Condom class to act directly on the
stored data as well, allowing operations like "x++" above to increment the internal integer. Binary operators such as '+'
will take 2 Condoms and create a new Condom with its referrenced data equal to the operator applied to the LHS's data and RHS's
data. 
An exeption to this is the dereferrence operator '*'. When applied to an Condom, it returns the dereferrenced pointer to 
the data stored in the second field of the pair on the heap. This is so that in a situation where the overridden operators can't 
work, the data itself can be directly referrenced. Although currently overridden, a situation similar to the std:cout's "<<" 
operator could cause this. This operator is overridden in the std:cout's class, but it does not have an override for custom 
classes such as our Condom<T> class. It is currently using a friend override in the Condom<T> class, but for other unaccounted 
for situations it would be necessary to use the '*' operator instead. Note that it is illegal to create a Condom<T*> for a 
pointer. This defeats the purpose of the Condom<T> template and will likely result in code leakage, so there are assert 
statements to assure that never happens. 
The member access operator '.' cannot be overridden, therefore the '->' operator must be used to access members of the base class
instead.

# How it works
The Condom<T> class works by containing a pointer to a STD pair of an unsigned int in the first field and an object instance 
of T in the second field. When the Condom object is initialized without another Condom in the constructor, it creates a new pair.
If the Condom is initialized using a Condom in the constructor, the new Condom is created as a referrence to the older one, and
copies the pair pointer from the original as its own pointer.
Whenever a Condom is made referrencing an existing Condom, the integer in the pair on the heap is incremented by one. Whenever
a Condom object's destructor is called, such as when the scope of the Condom is finished, this same integer value is decremented 
by one. If this integer is ever decremented to or past 0 during this stage, the data is deleted of the heap and the memory is
freed. This means that the programmer does not need to manually clear heap data, as it will be taken care of automatically.
