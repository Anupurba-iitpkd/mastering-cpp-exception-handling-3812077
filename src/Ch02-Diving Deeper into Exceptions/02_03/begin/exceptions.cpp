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

class FilePermissionException : public std::runtime_error
{
public:
    FilePermissionException(const std::string &msg) : std::runtime_error(msg) {};
};

class FileIOException : public std::runtime_error
{
public:
    FileIOException(const std::string &msg) : std::runtime_error(msg) {};
};

void triggerException(ErrorType error)
{
    switch (error)
    {
    case ErrorType::Disk:
        throw DiskAccessException("DiskAccessException");
    case ErrorType::Permission:
        throw FilePermissionException("FilePermissionException");
    case ErrorType::FileIO:
        throw FileIOException("FileIOException");
    default:
        break; // No exception thrown
    }
}

int main()
{
    try
    {
        triggerException(ErrorType::FileIO);
    }
    catch (const DiskAccessException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const FilePermissionException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const FileIOException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "An unknown exception occurred." << std::endl;
    }
    return 0;
}