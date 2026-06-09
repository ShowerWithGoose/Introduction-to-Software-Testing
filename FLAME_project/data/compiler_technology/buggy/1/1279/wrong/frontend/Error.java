package frontend;

import java.util.Objects;

public class Error {
    private int lineNumber;
    private char errorCode;

    public Error(int lineNumber, char errorCode) {
        this.lineNumber = lineNumber;
        this.errorCode = errorCode;
    }

    public int getLineNumber() {
        return lineNumber;
    }

    public char getErrorCode() {
        return errorCode;
    }


    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof Error)) return false;
        Error other = (Error) obj;
        return this.lineNumber == other.lineNumber && this.errorCode == other.errorCode;
    }

    @Override
    public int hashCode() {
        return Objects.hash(lineNumber, errorCode);
    }

}
