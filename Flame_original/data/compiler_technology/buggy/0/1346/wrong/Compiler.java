import error.ErrorHandler;
import frontend.lexer.Lexer;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

/**
 * @author
 * @Description:
 * @date 2024/9/29 12:00
 */
public class Compiler {
    public static void main(String[] args) {
        String inputFileName = "testfile.txt";

        //进行词法分析
        Lexer.getInstance().analyze(inputFileName);
        //正确源程序输出
        String lexerOutputFileName = "lexer.txt";
        Lexer.getInstance().printTokens(lexerOutputFileName);
        //错误源程序输出
        String errorOutputFileName = "error.txt";
        ErrorHandler.getInstance().printErrors(errorOutputFileName);
    }
}
