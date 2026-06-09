import frontend.lexer.Lexer;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PushbackInputStream;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Compiler {
    public static void main(String[] args) throws IOException {
        System.out.println("Hello, this is my compiler");
        System.out.println("Current working directory: " + System.getProperty("user.dir"));


        // read testfile.txt
//        String baseDir = new File(System.getProperty("user.dir")).getParent(); // 获取父目录
//        String filePath = baseDir + File.separator + "/compiler/src/main/java/testfile.txt"; // 组合文件路径
//        PushbackInputStream in = new PushbackInputStream(new FileInputStream(filePath));

        PushbackInputStream in = new PushbackInputStream(new FileInputStream("testfile.txt"));

        // Lexer
        Lexer lexer = new Lexer(in);
        lexer.scanFile();
        lexer.printMessage();

    }
}