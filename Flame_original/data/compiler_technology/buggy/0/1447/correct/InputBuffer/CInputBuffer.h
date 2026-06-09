/*
 * @brief: CInputBuffer is defined here.
 * @birth: Created on 2024/9/21.
 * @revision: last revised on 2024/9/26.
 */

#ifndef COMPILER_CINPUTBUFFER_H
#define COMPILER_CINPUTBUFFER_H

#include <cstdio>
#include <iostream>

// OVERVIEW: CInputBuffer provides two alternating read-in buffers,
// and will iterate each char for lexical analyzer.
class CInputBuffer {
private:
    // Members
    char m_FirstBuffer[4097]{};
    char m_SecondBuffer[4097]{};
    FILE* m_pFile;
    int forward;

    // Private Methods
    void LoadFirst() {
        // MODIFIES: contents in this->m_FirstBuffer
        // EFFECTS: Read at most 4096 bytes from file into this->m_FirstBuffer.
        //    Meanwhile, if there are less than 4096 remaining characters in the file,
        //        then after reading those remaining chars, we will attach a 'EOF' after the last char.
        //    For instance, if there are only 3 chars "abc" left in the file, then the contents of
        //        m_FirstBuffer will be {'a', 'b', 'c', EOF}.
        int count;
        if ((count = fread(m_FirstBuffer, 1, 4096, m_pFile)) < 4096) {
            m_FirstBuffer[count] = EOF;
        }
    }

    void LoadSecond() {
        // MODIFIES: contents in this->m_SecondBuffer
        // EFFECTS: Read at most 4096 bytes from file into this->m_SecondBuffer.
        //    Meanwhile, if there are less than 4096 remaining characters in the file,
        //        then after reading those remaining chars, we will attach a 'EOF' after the last char.
        //    For instance, if there are only 3 chars "abc" left in the file, then the contents of
        //        m_SecondBuffer will be {'a', 'b', 'c', EOF}.
        int count;
        if ((count = fread(m_SecondBuffer, 1, 4096, m_pFile)) < 4096) {
            m_SecondBuffer[count] = EOF;
        }
    }

public:
    // Constructors
    CInputBuffer() {
        // MODIFIES: this->mpFile, contents in m_FirstBuffer and m_SecondBuffer
        // EFFECTS: Open the file 'testfile.txt', if such file does not exist, throw std::invalid_argument exception.
        //    If such file exists, read at most 4096 bytes into m_FirstBuffer.
        //    The last byte of m_FirstBuffer and m_SecondBuffer will always be 'EOF'.
        if ((m_pFile = fopen("testfile.txt", "r")) == nullptr) {
            throw std::invalid_argument("The file 'testfile.txt' does not exist!");
        }
        forward = 0;
        LoadFirst();
    }

    explicit CInputBuffer(char const* name) {
        // REQUIRES: name != nullptr
        // MODIFIES: this->mpFile, contents in m_FirstBuffer and m_SecondBuffer
        // EFFECTS: Open the file whose name is 'name', If such file does not exist, throw std::invalid_argument exception.
        //    If such file exists, read at most 4096 bytes into m_FirstBuffer.
        //    The last byte of m_FirstBuffer and m_SecondBuffer will always be 'EOF'.
        if (name == nullptr) {
            throw std::invalid_argument("The input pointer is null!");
        }
        else if ((m_pFile = fopen(name, "r")) == nullptr) {
            throw std::invalid_argument("The file does not exist!");
        }
        forward = 0;
        LoadFirst();
    }

    // Methods
    void MoveForwardBy1() {
        if (IsEof()) {
            return;
        }

        forward = forward + 1;
        switch (forward) {
            case 4096:
                LoadSecond();
                break;
            case 8192:
                forward = 0;
                LoadFirst();
                break;
            default:
                break;
        }
    }

    char GetChar() {
        if (forward < 4096) {
            return m_FirstBuffer[forward];
        } else if (forward < 8192) {
            return m_SecondBuffer[forward - 4096];
        } else {
            std::cout << "Wrong forward algorithm!" << std::endl;
            return (char) -1;
        }
    }

    bool IsEof() {
        return GetChar() == EOF;
    }

    // Destructor
    ~CInputBuffer() {
        fclose(m_pFile);
    }
};


#endif //COMPILER_CINPUTBUFFER_H
