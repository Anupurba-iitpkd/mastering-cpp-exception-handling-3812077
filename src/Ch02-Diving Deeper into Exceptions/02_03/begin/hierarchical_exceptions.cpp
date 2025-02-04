#include <iostream>
#include <stdexcept>
#include <string>

enum ErrorType
{
  None,
  Disk,
  Permission,
  FileIO
};

class DiskAccessException : public std::runtime_error
{
public:
  DiskAccessException(const std::string &msg) : std::runtime_error(msg) {};
};

class FilePermissionException : public DiskAccessException
{
public:
  FilePermissionException(const std::string &msg) : DiskAccessException(msg) {};
};

class FileIOException : public FilePermissionException
{
public:
  FileIOException(const std::string &msg) : FilePermissionException(msg) {};
};

void triggerException(ErrorType error)
{
  switch (error)
  {
  case ErrorType::Disk:
    throw DiskAccessException("Disk Access denied");
  case ErrorType::Permission:
    throw FilePermissionException("File permissions not sufficient");
  case ErrorType::FileIO:
    throw FileIOException("File IO Exception");
  default:
    break; // No exception thrown
  }
}

int main()
{
  try
  {
    triggerException(ErrorType::Permission);
  }

  catch (const FileIOException &e)
  {
    std::cerr << "FileIOException: " << e.what() << std::endl;
  }
  catch (const FilePermissionException &e)
  {
    std::cerr << "FilePermissionException: " << e.what() << std::endl;
  }
  catch (const DiskAccessException &e)
  {
    std::cerr << "DiskAccessException: " << e.what() << std::endl;
  }

  catch (...)
  {
    std::cerr << "An unknown exception occurred." << std::endl;
  }
  return 0;
}