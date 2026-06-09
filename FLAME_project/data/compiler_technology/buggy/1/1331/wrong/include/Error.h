#ifndef ERROR_H
#define ERROR_H

#include <vector>
#include <utility>

class Error {
public:
    static Error &getInstance() {
        static Error instance;
        return instance;
    }

    void error(char type, int line); // 声明，不要定义

    [[nodiscard]] const std::vector<std::pair<char, int>> &getErrors() const {
        return error_list;
    }

private:
    Error() = default;

    Error(const Error &) = delete;

    Error &operator=(const Error &) = delete;

    std::vector<std::pair<char, int>> error_list;
};

#endif // ERROR_H
