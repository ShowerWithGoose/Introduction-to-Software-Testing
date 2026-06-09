package frontend;

public class Error {
    private int errorLineNo;
    private MyErrorType errorType;

    public Error(int errorLineNo, MyErrorType errorType) {
        this.errorLineNo = errorLineNo;
        this.errorType = errorType;
    }

    @Override
    public String toString(){
        return errorLineNo + " " + errorType.name();
    }
}
