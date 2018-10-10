#include <iostream>
#include <exception>

using namespace std;

class GenStackException : public exception {};
class GenStackOverflow : public GenStackException {} overflow;
class GenStackUnderflow : public GenStackException {} underflow;

template <class X> class GenStack
{
public:
  /* The default and overloaded constructors will initialize all out
  the variables to default values. The destructor will clear memory*/
  GenStack();
  GenStack(int maxSize);
  ~GenStack();

  /*These will manually create the push, pop, and peek functionalities
  for stacks*/
  void push(X data);
  X pop();
  X peek();

  /*Methods #1 and #2 occur when there is the wrong size of stack.
  Method #3 will resize the stack if it is full. Method #4 is a print
  method made for debugging*/
  bool isFull(); //Method #1
  bool isEmpty(); //Method #2
  void resize(); //Method #3
  void print(); //Method #4

  /*These are the class variables. Size is the number of elements
  in the stack in total. Top only refers to the last item (or first
  out) in the stack. maxSize is another argument for size*/
  int size;
  int top;
  int maxSize;

  //This is an array based on strings used for analyzing the source code
  X *myArray;
} ;

//////////////////////////////////////////////////////////////////////
template <class X>
GenStack<X>::GenStack() //default constructor
{
myArray = new X[size];
size = maxSize;
top = -1;
}

//////////////////////////////////////////////////////////////////////
template <class X>
GenStack<X>::GenStack(int maxSize) //overloaded constructor
{
  myArray = new X[maxSize];
  size = maxSize;
  top = -1;
}

//////////////////////////////////////////////////////////////////////
template <class X>
GenStack<X>::~GenStack()
{
  //what do i need to do here?
  delete[] myArray;
  cout << "stack destroyed" << endl;
}

//////////////////////////////////////////////////////////////////////
template <class X>
void GenStack<X>::push(X data)
{
  //add error -> check if not full
  try
  {
    if (isFull())
    {
      throw overflow;
    }
    myArray[++top] = data;
  }
  catch (GenStackOverflow e)
  {
    this->resize();
    this->push(data);
  }
  //you are responsible for error and bound checking
}

//////////////////////////////////////////////////////////////////////
template <class X>
X GenStack<X>::pop()
{
  //error checks
  try
  {
    if (isEmpty())
    {
      throw underflow;
    }
  }
  catch (GenStackUnderflow e)
  {
    cout << "Stack is empty" << endl;
  }
  //check if isEmpty
  return myArray[top--];
}

//////////////////////////////////////////////////////////////////////
template <class X>
X GenStack<X>::peek()
{
  return myArray[top];
}

//////////////////////////////////////////////////////////////////////
template <class X>
bool GenStack<X>::isFull()
{
  return (top == size-1);
}

//////////////////////////////////////////////////////////////////////
template <class X>
bool GenStack<X>::isEmpty()
{
  return (top == -1);
}

//////////////////////////////////////////////////////////////////////
template <class X>
void GenStack<X>::resize()
{
  X* newArray = new X[size*2];
  for (int i = 0; i <= top; i++)
  {
    newArray[i] = myArray[i];
  }

  delete[] myArray;
  myArray = newArray;
  size = size*2;
}

//////////////////////////////////////////////////////////////////////
template <class X>
void GenStack<X>::print()
{
  for (int i = 0; i <= top; i++)
  {
    cout << myArray[i] << " ";
  }
  cout << endl;
}
