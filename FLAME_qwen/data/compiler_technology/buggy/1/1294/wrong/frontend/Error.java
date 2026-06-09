package frontend;

public class Error {
    private int errorLineNo;
    private MyErrorType errorType;

    public Error(int errorLineNo, MyErrorType errorType) {
        this.errorLineNo = errorLineNo;
        this.errorType = errorType;
    }

    public int getErrorLineNo() {
        return errorLineNo;
    }
    @Override
    public String toString(){
        return errorLineNo + " " + errorType.name();
    }
}
