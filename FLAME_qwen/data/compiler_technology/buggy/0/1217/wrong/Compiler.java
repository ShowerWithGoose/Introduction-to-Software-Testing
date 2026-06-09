import frontend.Lexer;
import java.io.*;

public class Compiler {
    public static void main(String[] args) {
        try {
            // 直接定义文件名变量
            String inputFilePath = "testfile.txt";  // 输入文件
            String lexerOutputPath = "lexer.txt";   // 词法分析输出文件
            String errorOutputPath = "error.txt";    // 错误输出文件

            Lexer lexer = Lexer.getInstance();
            lexer.initialize(inputFilePath);  // 初始化词法分析器

            try (BufferedWriter lexerWriter = new BufferedWriter(new FileWriter(lexerOutputPath));
                 BufferedWriter errorWriter = new BufferedWriter(new FileWriter(errorOutputPath))) {

                while (lexer.next()) {
                    if (lexer.getLexType() != null) {
                        // 正确的 token 输出到 lexer.txt
                        lexerWriter.write(lexer.getLexType() + " " + lexer.getToken() + "\n");
                    } 
                }
                // 输出错误信息
                lexer.writeErrorsToFile(errorOutputPath);
            }
            System.out.println("词法分析完成.");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
