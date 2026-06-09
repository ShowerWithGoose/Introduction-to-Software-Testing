package model;

public class Error {
    private String process;
    private int lineno;
    private char errorType;

    public Error(String process, int lineno, char errorType) {
        this.process = process;
        this.lineno = lineno;
        this.errorType = errorType;
    }

    public String getProcess() {
        return this.process;
    }
    public int getLineno() {
        return lineno;
    }
    public char getErrorType() {
        return errorType;
    }
}
