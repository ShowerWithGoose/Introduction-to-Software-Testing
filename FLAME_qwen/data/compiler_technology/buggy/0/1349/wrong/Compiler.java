import frontend.Config;
import frontend.ErrorHandler;
import frontend.Lexer;
import frontend.Parser;

public class Compiler {
    public static void main(String[] args) {
        ErrorHandler errorHandler = new ErrorHandler();   // 创建错误处理器
        Lexer lexer = new Lexer(errorHandler);            // 创建词法分析器
        lexer.printTokens();                            // 打印词法分析结果
        Parser parser = new Parser(lexer.getTokens(), errorHandler);  // 创建语法分析器
        parser.printResult(); // 打印语法分析结果
        errorHandler.printErrors(); // 打印错误
        Config.closeAll(); // 关闭文件
    }
}
