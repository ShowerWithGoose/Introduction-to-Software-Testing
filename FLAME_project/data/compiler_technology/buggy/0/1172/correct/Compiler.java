import java.io.IOException;

public class Compiler {
    public static void main(String[] args) {
        // 程序入口，初始化Lexer并进行词法分析
        try {
            Lexer lexer = new Lexer("testfile.txt");
            lexer.run(); // 调用词法分析
        } catch (IOException e) {
            e.printStackTrace(); // 捕获并输出文件读取异常
        }
    }
}
