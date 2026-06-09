import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Compiler {
    public static void main(String[] args) {
        String filePath = "testfile.txt";
        //String filePath = "D:\\idea projects\\CiFaFenXi\\testfile.txt";
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            int lineNumber = 1; // 行号从1开始
            Lexer lexer = new Lexer();
            while ((line = br.readLine()) != null) {
                lexer.analyze(line, lineNumber);
                lineNumber++;
            }
            Lexer.right.close();
            Lexer.error.close();
            Lexer.fw1.close();
            Lexer.fw2.close();
        } catch (IOException e) {
            e.printStackTrace(); // 处理异常
        }
    }
}


