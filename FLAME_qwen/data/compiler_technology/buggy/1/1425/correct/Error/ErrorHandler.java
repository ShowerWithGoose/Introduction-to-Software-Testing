package Error;/**
 * @Description:
 * @author
 * @date 2024/9/30 15:50
 */
import Utils.IO;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

/**
 * @author:
 * TODO  
 * 2024/9/30 15:50
 */
public class ErrorHandler {
    private List<CompileException> compileExceptionList=new ArrayList<>();

    private static ErrorHandler errorHandler=new ErrorHandler();

    public static ErrorHandler getInstance(){
        return errorHandler;
    }
    public void print(CompileException compileException){
        compileException.print();
    }
    public void add(CompileException compileException){
        compileExceptionList.add(compileException);
    }
    public void Error_print(){
        compileExceptionList.sort(Comparator.comparingInt((CompileException c) -> c.getLineNumber()));
        for(CompileException compileException:compileExceptionList){
            compileException.print();
        }
    }
}
