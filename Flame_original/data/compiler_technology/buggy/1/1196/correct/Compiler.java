import Frontend.LexType;
import Frontend.Lexer;
import Frontend.Parser;
import Frontend.Token;

import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Compiler {
    public static void main(String[] args) throws IOException {
        FileInputStream input = new FileInputStream("testfile.txt");
        System.setIn(input);
        Scanner scanner = new Scanner(System.in);
        // scanner的来源变成文件
        StringBuilder use_to_lex = new StringBuilder();
        while (scanner.hasNextLine()) {
            String one_row = scanner.nextLine();
            use_to_lex.append(one_row).append("\n");
        }
        scanner.close();
        // 把文件包含\n存到use_to_lex里面
        Lexer lexer = new Lexer(use_to_lex);
        Parser parser = new Parser(lexer);
        parser.analyze();
    }
}