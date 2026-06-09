import frontend.Lexer;
import frontend.Node;
import frontend.Parser;

import java.io.*;

// 按两次 Shift 打开“随处搜索”对话框并输入 `show whitespaces`，
// 然后按 Enter 键。现在，您可以在代码中看到空格字符。
public class Compiler {
    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("testfile.txt");
             BufferedReader br = new BufferedReader(new InputStreamReader(fis))) {
            String line;
            Lexer lexer = new Lexer("");
            int lineNumber = 1;
            while ((line = br.readLine()) != null) {
                lexer.getSymbol(line, lineNumber);
                lineNumber++;
                lexer.posZero();
            }
            Parser parser = new Parser(lexer);
            Node compUnit = parser.parseCompUnit();
            if (lexer.isRight()) compUnit.print();
            /*if (lexer.isRight()) {
                try (FileOutputStream fos = new FileOutputStream("lexer.txt");
                     PrintWriter writer = new PrintWriter(fos)) {
                    List<Token> tokens = lexer.getTokens();
                    for (Token token : tokens) {
                        writer.printf("%s\n", token.toString());
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }*/
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}