import java.io.*;

public class Compiler {
    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new FileReader("testfile.txt"));
            StringBuilder buffer = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                buffer.append(line).append("\n");
            }
            reader.close();

            Token token = new Token(buffer.toString());
            Lexer analyzer = new Lexer(token);
            analyzer.getAllTokens(); // 开始词法分析

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

