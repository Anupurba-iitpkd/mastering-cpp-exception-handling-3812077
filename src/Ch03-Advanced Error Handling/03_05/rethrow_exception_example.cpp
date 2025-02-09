#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>

void handle_exception(std::exception_ptr eptr)
{
  try
  {
    if(eptr)
      std::rethrow_exception(eptr);
  }
  catch(const std::exception& e)
  {
    std::cerr<<"Example of rethrow: Exception: "<<e.what()<<std::endl;
  }
}

int main()
{
  std::exception_ptr eptr;
  try
  {
    char ch = std::string().at(1);
  }
  catch(...)
  {
    eptr = std::current_exception();
  }
  handle_exception(eptr);
}