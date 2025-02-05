#include <stdexcept>
#include <iostream>
#include <string>

class A
{
public:
  A() { std::cout<<"In the constructor of A"<<std::endl;}
  ~A() {std::cout<<"In destructor of A"<<std::endl;}
};

class B
{
public: 
  B() {std::cout<<"In the constructor of B"<<std::endl;}
  ~B() {std::cout<<"In the destructor of B"<<std::endl;}
};

void CreateObjects()
{
  A a;
  B b;
}

void my_terminate()
{
  std::cout<<"Call to my terminate"<<std::endl;
}

int main()
{
  try
  {
    std::set_terminate(my_terminate);
    std::cout<<"In try block of main"<<std::endl;
    //CreateObjects();
    A a;
    B b;
    throw("Exception thrown from the try block of main.");
    //throw std::runtime_error("Exception thrown from the try block of main.");
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  catch(...)
  {
    std::cerr << "No matching catch block." << '\n';
  }
  
}
