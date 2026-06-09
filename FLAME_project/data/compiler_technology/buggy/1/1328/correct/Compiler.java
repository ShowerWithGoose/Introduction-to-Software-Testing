import config.Config;
import error.ErrorHandler;
import frontend.Lexer;
import frontend.Parser;
import utils.MyIO;

public class Compiler {
    public static void main(String[] args) {
        /*
         * 编译过程
         */
        // 词法分析
        Lexer.getInstance().fsa(MyIO.read(Config.inputFilePath));
        // 语法分析
        Parser.getInstance().setTokens(Lexer.getInstance().getTokens());
        Parser.getInstance().parsing();

        /*
         * 分析结果输出
         */
        if (Config.lexer) {
            if (ErrorHandler.getInstance().getErrors().isEmpty()) { // 源程序正确
                Lexer.getInstance().printTokens();
            } else   // 源程序错误
                ErrorHandler.getInstance().printErrors();
        }

        if (Config.parser) {
            if (ErrorHandler.getInstance().getErrors().isEmpty()) { // 源程序正确
                Parser.getInstance().printParserRes();
            } else   // 源程序错误
                ErrorHandler.getInstance().printErrors();
        }
    }
}