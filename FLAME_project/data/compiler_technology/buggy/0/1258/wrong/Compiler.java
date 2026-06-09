import frontend.*;

import java.io.IOException;

public class Compiler {
    public static void main(String[] args) {
        try {
            // 创建 FileProcessor 读取 "testfile.txt"，输出到 "lexer_output.txt"
            FileProcessor tokenFileProcessor = new FileProcessor("testfile.txt", "lexer.txt");

            // 创建 FileProcessor 单独处理 error.txt 文件
            FileProcessor errorFileProcessor = new FileProcessor("testfile.txt", "error.txt");

            // 创建 Lexer 对象，并传入 tokenFileProcessor 处理词法分析
            Lexer lexer = new Lexer(tokenFileProcessor);

            // 开始词法分析
            lexer.analyze();

            // 输出词法分析结果到 lexer.txt
            lexer.writeTokens(tokenFileProcessor);

            // 输出错误信息到 error.txt
            lexer.writeErrors(errorFileProcessor);

            // 关闭文件写入器
            tokenFileProcessor.close();
            errorFileProcessor.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}