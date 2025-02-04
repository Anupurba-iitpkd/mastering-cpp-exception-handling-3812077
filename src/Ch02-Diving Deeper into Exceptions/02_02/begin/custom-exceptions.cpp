#include <iostream>
#include <stdexcept>
#include <string>

class InsufficientDiskSpaceException : public std::runtime_error
{
public: 
  InsufficientDiskSpaceException(const std::string& message) : std::runtime_error(message) {}
};

void CheckDiskSpace(unsigned long availableSpaceMB)
{
  const unsigned long requiredSpaceMB = 100;
  if(availableSpaceMB < requiredSpaceMB)
  {
    throw InsufficientDiskSpaceException("Insufficient disk space");
  }
}

int main()
{
  unsigned long spaceToTest[] = {130, 100, 80};

  for(unsigned long space : spaceToTest)
  {
    try
    {
    CheckDiskSpace(space);
    std::cout<<"Sufficient disk space"<< space << " MB "<<std::endl;
    }
    catch (const InsufficientDiskSpaceException& e)
    {
      std::cerr<<"Error: "<< e.what() << " Available space: "<< space<<std::endl;
    }
  }
}