import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Compiler {
    public static void main(String[] args) {
        String filePath = "testfile.txt"; // 文件路径
        StringBuilder contentBuilder = new StringBuilder();

        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                contentBuilder.append(line).append(System.lineSeparator());
            }
            String content = contentBuilder.toString();
            Lexical lexical = new Lexical(content);
            lexical.lexical_analysis();
            lexical.lexical_print();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
