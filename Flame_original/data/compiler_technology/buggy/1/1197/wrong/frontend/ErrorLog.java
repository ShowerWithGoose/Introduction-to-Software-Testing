package frontend;

public record ErrorLog(int lineNum, ErrorType errorType) {

    @Override
    public String toString() {
        return lineNum + " " + errorType;
    }
}