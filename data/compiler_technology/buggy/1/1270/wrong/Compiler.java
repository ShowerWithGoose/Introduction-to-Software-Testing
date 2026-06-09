import frontend.Lexer;
import frontend.Parser;
import frontend.Token;
import java.io.IOException;
import java.util.List;

public class Compiler {
    public static void main(String[] args) {
        String inputFile = "testfile.txt";
        String lexerOutputFile = "lexer.txt";
        String errorOutputFile = "error.txt";
        String parserOutputFile = "parser.txt";
        try {
            Lexer lexer = new Lexer(inputFile);
            List<Token> tokens = lexer.analyze(lexerOutputFile, errorOutputFile);
            Parser parser = new Parser(tokens);
            parser.parse(parserOutputFile, errorOutputFile);
        } catch (IOException e) {
            System.err.println("文件读取错误: " + e.getMessage());
        }
    }
}
