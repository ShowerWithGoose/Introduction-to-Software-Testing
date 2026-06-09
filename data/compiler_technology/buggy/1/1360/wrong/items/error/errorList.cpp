#include "errorList.h"

// No need to define the constructor or getInstance() method in the .cpp file, as they are already defined in the header file

// You can define member functions of the errorList class here, if needed
errorList &errorList::getInstance() {
    static errorList instance;
    return instance;
}