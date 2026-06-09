import frontend.Lexer;
import frontend.Parser;
import frontend.PreLexer;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class Compiler {
    public static void main(String[] args) {
        File file = new File("testfile.txt");
        PrintStream fileOut1;
        PrintStream fileOut2;
        Scanner scanner;
        try {
            scanner = new Scanner(file);
            fileOut1 = new PrintStream("parser.txt");
            fileOut2 = new PrintStream("error.txt");
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        Lexer.setFile(fileOut1,fileOut2);
        Parser.setFile(fileOut1,fileOut2);
        StringBuilder input = new StringBuilder();
        String line;
        // 读取输入直到 EOF
        while (scanner.hasNextLine()) {
            line = scanner.nextLine();
            input.append(line).append("\n");
        }
        scanner.close();
        Lexer.Input(input.toString());
        PreLexer.Input(input.toString());
        Parser.start();
    }
}