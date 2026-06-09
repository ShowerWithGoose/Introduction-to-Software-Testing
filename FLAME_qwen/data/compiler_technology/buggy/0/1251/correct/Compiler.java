import frontend.Lexer.Lexer;

public class Compiler {
    public static void main(String[] args) {
        String inputFile = "testfile.txt";
        Lexer lexer = new Lexer(inputFile);
        lexer.parse();
    }
}