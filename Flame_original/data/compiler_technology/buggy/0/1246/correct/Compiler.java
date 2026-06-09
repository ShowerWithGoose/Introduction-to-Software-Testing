import error.ErrorHandler;
import token.Token;

import java.util.ArrayList;
import frontend.*;
import utils.IO;

/**
 * @Description 万恶之源
 * @Author
 * @Date 2024/9/17
 */
public class Compiler {
    public String inputText = "";

    private Lexer lexer = null;
    private ArrayList<Token> lexerResult = null;
    private boolean hasError = false;

    public void lexicalAnalysing(){
        System.out.println("======开始[词法分析]=====");
        if(inputText == null){
            System.out.println("文件读入失败");
            return;
        }
        lexer = new Lexer(inputText);
        lexer.process();
        lexer.outputResult();
        lexerResult = lexer.getTokenResult();
        System.out.println("=====[词法分析]完成!=====");
    }

    public void lexicalChecking(){
        System.out.println("=====开始[词法分析后错误处理]=====");
        // 输出错误
        ErrorHandler.printErrors();
        // 记录是否有错误
        hasError = ErrorHandler.hasError();
        System.out.println("======[词法分析后错误处理]完成=====");
    }

    public void compiling() {
        System.out.println("开始[编译]");
        inputText = IO.read();
        lexicalAnalysing();
        lexicalChecking();
        if (hasError) {
            System.out.println("=======存在词法错误，详见error.txt!======");
        } else {
            System.out.println("=======恭喜，无词法错误!======");
        }
        System.out.println("=======完成[词法分析]，结果见lexer.txt!======");
    }

    public static void main(String[] args) {
        Compiler compiler = new Compiler();
        compiler.compiling();
    }
}
