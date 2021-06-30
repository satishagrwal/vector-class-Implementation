# vector-class-Implementation
Implement a class in C++, which behaves just like the Vector class.

Vectors are same as dynamic arrays with the ability to resize itself automatically
when an element is inserted or deleted, with their storage being handled automatically 
by the container. Vector elements are placed in contiguous storage so that they can be 
accessed and traversed using iterators. In vectors, data is inserted at the end. 
Inserting at the end takes differential time, as sometimes there may be a need of 
extending the array. Removing the last element takes only constant time because no
resizing happens. 
Inserting and erasing at the beginning or in the middle is linear in time.

We can also make the vector class generic using templates.
Certain functions associated with the Vector that we will implement are: 

void push(int data): This function takes one element and inserts it at the last. Amortized time complexity is O(1).  

int get(int index): It is used to get the element at the specified index. Time complexity is O(1). 

void pop(): It deletes the last element. Time complexity is O(1). 

int size(): It returns the size of the vector i.e, number of elements in the vector. Time complexity is O(1). 

int getCapacity(): It returns the capacity of the vector. Time complexity is O(1). 

void printData(): It is used to print array elements. Time complexity is O(N), where N is the size of the vector. 
