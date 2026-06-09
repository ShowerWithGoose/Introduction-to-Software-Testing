import frontend.Lexer;
import frontend.Token;
import java.util.List;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.FileWriter;
import java.nio.file.Paths;
import java.nio.file.Files;

public class Compiler {
    public static void main(String[] args) {
        try {
            List<String> lines = Files.readAllLines(Paths.get("testfile.txt"));
            // 初始化词法分析器
            Lexer lexer = new Lexer(lines);
            List<Token> tokens = lexer.analyze();
            List<Token> errors = lexer.getErrors();

            // 写入lexer.txt文件
            BufferedWriter lexerWriter = new BufferedWriter(new FileWriter("lexer.txt"));
            for (Token token : tokens) {
                lexerWriter.write(token.toString());
                lexerWriter.newLine();
            }
            lexerWriter.close();

            // 写入error.txt文件
            BufferedWriter errorWriter = new BufferedWriter(new FileWriter("error.txt"));
            for (Token token : errors) {
                errorWriter.write(token.toError());
                errorWriter.newLine();
            }
            errorWriter.close();
        } catch (IOException e) {
        }
    }
}