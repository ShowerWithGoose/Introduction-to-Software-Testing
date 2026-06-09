#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class ErrorReporter {
public:
    struct Error {
        int line;
        std::string message;

        Error(int line, const std::string& message) : line(line), message(message) {}
    };

    static void report(int line, const std::string& message) {
        errors.emplace_back(line, message);
    }

    static void output_errors(const std::string& filename) {
        std::ofstream outfile(filename);
        for (const auto& error : errors) {
            outfile << error.line << " " << error.message << std::endl;
        }
    }

    static bool has_errors() {
        return !errors.empty();
    }

private:
    static std::vector<Error> errors;
};

std::vector<ErrorReporter::Error> ErrorReporter::errors;
