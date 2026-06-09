import config.Config;
import error.ErrorHandler;
import fronted.Lexer;
import utils.MyIO;

public class Compiler {
    public static void main(String[] args) {
        Lexer.getInstance().fsa(MyIO.read(Config.inputFilePath));
        if (Config.lexer) {
            if (ErrorHandler.getInstance().getErrors().isEmpty()) { // 源程序正确
                Lexer.getInstance().printTokens();
            } else   // 源程序错误
                ErrorHandler.getInstance().printErrors();
        }
    }
}