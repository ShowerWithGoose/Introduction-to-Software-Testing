package Error;/**
 * @Description:
 * @author
 * @date 2024/9/30 15:50
 */
import Utils.IO;
/**
 * @author:
 * TODO  
 * 2024/9/30 15:50
 */
public class ErrorHandler {
    private CompileException compileException;

    private static ErrorHandler errorHandler=new ErrorHandler();

    public static ErrorHandler getInstance(){
        return errorHandler;
    }
    public void print(CompileException compileException){
        compileException.print();
    }
}
