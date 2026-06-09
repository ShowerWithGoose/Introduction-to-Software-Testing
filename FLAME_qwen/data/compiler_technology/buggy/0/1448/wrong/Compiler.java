import frontend.Lexer;

public class Compiler{
    public static void main(String[] args) {
        String source = "testfile.txt";
        Lexer lexer = new Lexer(source);
        lexer.lexar();
    }
}