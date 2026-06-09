package frontend;

public class Error {
    private String errorType;
    private int lineNum;
    public Error(int lineNum, String errorType){
        this.lineNum = lineNum;
        this.errorType = errorType;
    }
    public String toString(){
        return this.lineNum+" "+this.errorType;
    }
}
