import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;

// 编译器入口
public class Compiler {
    public static void main(String[] args) throws IOException {
        Lexer lexer = new Lexer();
        lexer.parse(IO.read(Config.lexerInPath));
        if (!lexer.getErrorOccur()) {
            IO.LexerOutput(lexer.getTokenList(),Config.lexerOutPath);
        }
    }
}