import java.util.List;

public class Compiler {
    public static void main(String[] args) {
        // 调用 Lexer 获取词法单元
        List<Token> tokens = Lexer.main(args);

        // 调用 Parser 进行语法分析
        Parser parser = new Parser(tokens);
        parser.parse();
    }
}
