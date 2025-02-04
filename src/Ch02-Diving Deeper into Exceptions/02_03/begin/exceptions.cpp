#include <iostream>

enum ErrorType
{
    None,
    Disk,
    Permission,    
    FileIO
};

class DiskAccessException {};

class FilePermissionException {};

class FileIOException {};

void triggerException(ErrorType error)
{
    switch (error)
    {    
    case ErrorType::Disk:
        throw DiskAccessException();
    case ErrorType::Permission:
        throw FilePermissionException();
    case ErrorType::FileIO:
        throw FileIOException();
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
    catch(const DiskAccessException& e)
    {
        std::cerr<<"Disk Access Exception: " << std::endl; 
    }
    catch(const FilePermissionException& e)
    {
        std::cerr<<"File Permission Exception"<<std::endl;
    }
    catch(const FileIOException& e)
    {
        std::cerr<<"File IO Exception"<<std::endl;
    }
    catch (...)
    {
        std::cerr << "An unknown exception occurred." << std::endl;
    }
    return 0;
}