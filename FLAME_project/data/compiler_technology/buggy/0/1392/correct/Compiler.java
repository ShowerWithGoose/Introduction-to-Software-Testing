import frontend.Lexer;

public class Compiler {
    public static void main(String[] args) {
        Lexer.getInstance().lexicalAnalyse();
    }
}
