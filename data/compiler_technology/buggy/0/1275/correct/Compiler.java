import frontend.Lexer;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Compiler {
    public static void main(String[] args) {
        Lexer lexer = new Lexer();
        // 读取 testfile.txt 文件
        StringBuilder sourceBuilder = new StringBuilder();
        try (BufferedReader br = new BufferedReader(new FileReader("testfile.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                sourceBuilder.append(line).append("\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }

        String source = sourceBuilder.toString(); // 将读取到的内容转换为字符串
        lexer.analyze(source);
        lexer.outputResults(); // 保存词法分析结果到文件
    }
}
