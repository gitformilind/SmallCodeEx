#include <iostream>
#include <algorithm>
//A Function Object, or Functor (the two terms are synonymous) is simply any object that can be called as if it is a function.
//Class that defines operator() is called function object.
using namespace std;

class funcObject{
  int state;
public:

  funcObject(){
    cout << "CTOR" << endl;
    state = 0;
  }
  //adding explicit before the constructor will prevent call of constructor in case of object = 10;
  explicit funcObject(int input){
    cout << "CTOR with Arg" << endl;
    state = input;
  }
  //Adding copy constructor will break the code as funcObject(10) will be tried with copy constructor :(
  /*
  funcObject( funcObject & ref){
    cout << "copy ctor "<<endl;
  }*/
  ~funcObject(){
     cout << "DTOR" << endl;
  }
  void operator()(){
    cout << "Inside operator" << endl;
    state = -1;
  }
  void display(){
    cout << "Value of state " << state << endl;
  }
  operator int() {
    cout << "conversion operator" << endl;
    return state;
  }
};

int main()
{
  cout << "*** START ***"<< endl;
  funcObject obj;
  obj();
  obj.display();
  funcObject newObj = funcObject(10);
  newObj.display();
  int state = newObj;
  cout << "Value " << state << endl;
  cout << "*** END ***"<< endl;
  return 0;
}

/*
*** START ***
CTOR
Inside operator
Value of state -1
CTOR with Arg
Value of state 10
conversion operator
Value 10
*** END ***
DTOR
DTOR
*/
