package frontend;

public class Error {
    int curLine;
    char errorType;
    public Error(int curLine,char errorType){
        this.curLine = curLine;
        this.errorType = errorType;
    }

    public int getCurLine() {
        return curLine;
    }

    public char getErrorType() {
        return errorType;
    }
}
