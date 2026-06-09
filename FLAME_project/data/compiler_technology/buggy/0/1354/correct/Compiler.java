import Utils.WrongError;
import frontend.lexer.Lexer;
import frontend.lexer.TokenList;

import java.io.*;
import java.util.ArrayList;

public class Compiler {
    public static ArrayList<WrongError> errors = new ArrayList<>();

    public static void main(String[] args) {
        // 使用 try-with-resources 自动关闭文件资源
        try (
                BufferedInputStream source = new BufferedInputStream(new FileInputStream("testfile.txt"));
                BufferedWriter lexerWriter = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("lexer.txt")));
                BufferedWriter errorWriter = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("error.txt")))
        ) {
            // 进行词法分析
            TokenList tokenList = Lexer.getInstance().lex(source);

            // 将词法分析器的错误加入全局错误列表
            errors.addAll(Lexer.getInstance().errors);

            // 输出 TokenList 到控制台
            System.out.print(tokenList.toString());

            // 将 TokenList 和错误信息写入到 lexer.txt 文件
            lexerWriter.write(tokenList.toString());

            // 如果有错误信息，也写入到 lexer.txt 文件中
            if (!errors.isEmpty()) {
                for (WrongError error : errors) {
                    errorWriter.write(error.getErrorMessage());
                }
            }

        } catch (FileNotFoundException e) {
            System.err.println("Error: Input file not found.");
        } catch (IOException e) {
            System.err.println("Error while processing files: " + e.getMessage());
        }
    }
}