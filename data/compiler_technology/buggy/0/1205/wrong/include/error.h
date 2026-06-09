#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

struct Error {
    int lineno;
    std::string msg;
};

class ErrorReporter {
    std::vector<Error> _errors;

    ErrorReporter() = default;
    ErrorReporter(const ErrorReporter&) = delete;
    ErrorReporter& operator=(const ErrorReporter&) = delete;

    public:
        static ErrorReporter& get() {
            static ErrorReporter instance;
            return instance;
        }

        static void error(int lineno, const std::string& msg) {
            get().add_error(lineno, msg);
        }

        void add_error(int lineno, const std::string& msg) {
            _errors.push_back(Error{lineno, msg});
        }

        bool has_error() const {
            return !_errors.empty();
        }

        void print_error(std::ostream& out) {
            std::sort(
            _errors.begin(), _errors.end(),
            [](const Error& e1, const Error& e2)
            {return e1.lineno < e2.lineno;});

            for (const auto&[lineno, msg] : _errors) {
                out << lineno << " " << msg << std::endl;
            }
        }
};

