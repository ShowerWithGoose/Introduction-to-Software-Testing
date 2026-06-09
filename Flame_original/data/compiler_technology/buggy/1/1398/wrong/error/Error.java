package error;

import java.util.ArrayList;

public class Error {
    int lineNumber;
    char type;

    public Error(int lineNumber, char type) {
        this.lineNumber = lineNumber;
        this.type = type;
    }
    @Override
    public String toString() {
        return String.valueOf(lineNumber) + ' ' + type;
    }
}
