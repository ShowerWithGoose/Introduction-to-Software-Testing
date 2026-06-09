import lexer.Lexer;

import java.io.FileOutputStream;
import java.io.PrintStream;
import java.io.IOException;
import java.io.*;

public class Compiler {
    public static void main(String[] args) {
        Lexer lexer = new Lexer();
        lexer.run(args);

        // 当编译正确时
        if (lexer.err_sym) {
            System.out.println("correct!!!");

            //lexer. writeOutputToFile("C:/Users/sjn/Desktop/lexer.txt");
            lexer. writeOutputToFile("lexer.txt");
        }
        else {
            System.out.println(lexer.err_line + " " + lexer.err_code);
            // 将错误信息输出到 error.txt 文件
            try (PrintStream errorOut = new PrintStream(new FileOutputStream("error.txt"))) {
            //try (PrintStream errorOut = new PrintStream(new FileOutputStream("C:/Users/sjn/Desktop/error.txt"))) {
                    errorOut.println(lexer.err_line + " " + lexer.err_code);
                } catch (IOException e) {
                    e.printStackTrace(); // 如果出现异常，打印错误信息
                }
            }
        }
    }

