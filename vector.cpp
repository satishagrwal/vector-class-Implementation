#include<iostream>

using namespace std;

template<typename T>
class cVector
{
    T* array;
    
    int capacity;
    
    int current;
    
public:
    
    T& operator =(const T& rhs);
    cVector(const cVector& rhs);
    cVector();
    void push(T data);
    void pop();
    int size();
    int getCapacity();
    T get(int index);
    void printDate();
};

template <typename T>
cVector<T>::cVector()
{
    array = new T[1];
    capacity = 1;
    current = 0;
}

template <typename T>
void cVector<T>::push(T data)
{
    if(current == capacity)
    {
        T* temp = new T[2 * capacity];
            
        for(int i = 0; i< capacity;  i++)
        {
            temp[i] = array[i];
        }
        delete[] array;
        capacity = capacity*2;
        array = temp;     
    }
        
    array[current] = data;
    current++;
}

template <typename T>    
void cVector<T>::pop()
{
    current--;
}

template <typename T>
int cVector<T>::size()
{
    return current;
}

template <typename T>
int cVector<T>::getCapacity()
{
    return capacity;
}
    
template <typename T>    
void cVector<T>::printDate()
{
    for(int i=0; i<current; i++)
    {
        std::cout << array[i] << std::endl;
    }
}

template <typename T>    
T& cVector<T>::operator =(const T& rhs)
{
    if(this != &rhs)
    {
      delete[] array;
      array = new T[rhs.capacity];
            
      capacity = rhs.capacity;
      size = rhs.size;
       
      for(int i = 0; i< rhs.capacity;  i++)
      {
        array[i] = rhs.array[i];
      }       
     return *this;
      }
}

template <typename T>
cVector<T>::cVector(const cVector& rhs)
{
    array = new T[rhs.capacity];
    capacity = rhs.capacity;
    current = rhs.current;
        
    for(int i = 0; i< rhs.capacity;  i++)
    {
       array[i] = rhs.array[i];
    }  
}

template <typename T>
T cVector<T>::get(int index)
{
    if (index < current)
    {
        return array[index];
    }
}

int main()
{
    cVector<int> v;
    cout<<"Intial size: "<<v.size()<<endl;
    cout<<"Initial capacity: "<<v.getCapacity()<<endl;
    v.push(10);
    v.push(20);
    v.push(30);
    v.push(40);
    cout<<"Get element at index 1 "<<v.get(1)<<endl;
    cout<<"After insertion"<<endl;
    cout<<"Vector size: "<<v.size()<<endl;
    cout<<"Vector capacity: "<<v.getCapacity()<<endl;
    v.push(50);
    v.printDate();
    cout<<"After insertion when capacity and size is same"<<endl;
    cout<<"size: "<<v.size()<<endl;
    cout<<"New capacity: "<<v.getCapacity()<<endl;
    
    cVector<int> v1;
    v1 = v;
    cout<<"After assigment from once object to other object "<<endl;
    v1.printDate();
    
    cVector<int> v2 = v;
    cout<<"After copy constuctor"<<endl;
    cout<<"size: "<<v2.size()<<endl;
    cout<<"new capacity: "<<v2.getCapacity()<<endl;
    v2.printDate();
    
    return 0;
}
