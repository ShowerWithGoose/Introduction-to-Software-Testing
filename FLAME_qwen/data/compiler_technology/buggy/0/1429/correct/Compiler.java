import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

/**
 * Classname ${CLASSNAME}
 * Description TODO
 * Date 2024/10/2 22:25
 * Created ZHW
 */
public class Compiler {
    public static void main(String[] args) {
        try {
            // 读取文件内容
            String sourceCode = readSourceFile("testfile.txt");
            Token token = new Token(sourceCode);

            // 创建 Lexer 对象并进行词法分析
            Lexer analyzer = new Lexer(token);
            analyzer.getAllTokens(); // 开始词法分析

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //读取文件并返回字符串
    private static String readSourceFile(String filePath) throws IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            StringBuilder buffer = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                buffer.append(line).append("\n");
            }
            return buffer.toString();
        }
    }
}