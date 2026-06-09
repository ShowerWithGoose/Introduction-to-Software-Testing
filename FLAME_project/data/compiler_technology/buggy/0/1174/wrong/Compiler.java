import lexer.Lexer;
import lexer.Token;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.IOException;
import java.io.PrintWriter;

public class Compiler {
    public static void main(String[] args) {
        String sourceCode;
        PrintWriter writer_lexer = null;
        PrintWriter writer_error = null;

        try {
            sourceCode = new String(Files.readAllBytes(Paths.get("testfile.txt")));
            writer_lexer = new PrintWriter("lexer.txt");
            writer_error = new PrintWriter("error.txt");
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }
        
        /* 初始化词法分析器 */
        Lexer lexer = new Lexer(sourceCode);
        
        while (lexer.readNextToken()) {
            Token token = lexer.getToken();
            System.out.println(token.getType().name() + " " + token.getContent() + " (line:" + token.getLineNum() + ",col:" + token.getColNum() + ')');
            writer_lexer.println(token.getType().name() + " " + token.getContent());
            if (token.getError()) {
                writer_error.println(token.getLineNum() + " a");
            }
        }

        writer_lexer.close();
        writer_error.close();

        System.out.println("Compile Finish!");
    }

}
