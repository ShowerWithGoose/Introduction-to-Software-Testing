package error;

public class Error {
    public int lineNumber;
    public ErrorType type;
    public Error (){};
    public Error (int lineNumber,ErrorType type){
        this.lineNumber = lineNumber;
        this.type = type;
    }
    public int getLineNumber(){
        return lineNumber;
    }
}
