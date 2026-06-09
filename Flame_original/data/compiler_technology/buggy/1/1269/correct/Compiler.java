import frontend.Lexer;
import frontend.Parser;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.nio.Buffer;
import java.util.Scanner;

// 按两次 Shift 打开“随处搜索”对话框并输入 `show whitespaces`，
// 然后按 Enter 键。现在，您可以在代码中看到空格字符。
public class Compiler {
    public static void main(String[] args) {
        try {
            System.out.println("当前工作目录：" + new File(".").getAbsolutePath());
            
            FileReader fileReader = new FileReader("./testfile.txt");
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            Lexer lexer = new Lexer(bufferedReader);
            Parser parser = new Parser(lexer);
            lexer.print();
            parser.print();
            //parser.testPrint();
            
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }
}