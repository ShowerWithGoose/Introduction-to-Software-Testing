package Error;
import Utils.IO;
/**
 * @author:
 * TODO  
 * 2024/9/21 11:16
 */
public class CompileException{
    private int lineNumber;
    private ErrorType errorType;

    public CompileException(int lineNumber,ErrorType errorType){
        this.lineNumber=lineNumber;
        this.errorType=errorType;
    }

    public int getLineNumber() {
        return lineNumber;
    }

    public ErrorType getErrorType() {
        return errorType;
    }

    public void print(){
        IO.lexer_error(lineNumber + " " + errorType+'\n');
    }
}
