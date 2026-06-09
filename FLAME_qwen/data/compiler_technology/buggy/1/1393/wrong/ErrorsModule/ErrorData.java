package ErrorsModule;

public class ErrorData {
    private int lineNumber;
    private char errorType;

    public ErrorData(int lineNumber, char errorType) {
        this.lineNumber = lineNumber;
        this.errorType = errorType;
    }

    public String toString() {
        return lineNumber + " " + errorType;
    }
    public int getLineNumber(){
        return lineNumber;
    }
}
