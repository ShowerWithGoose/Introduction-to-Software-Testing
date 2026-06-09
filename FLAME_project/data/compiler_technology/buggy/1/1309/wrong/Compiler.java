import frontend.*;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

import static frontend.ErrList.errList;

public class Compiler {
    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("testfile.txt"));
        System.setOut(new PrintStream(new FileOutputStream("parser.txt")));
        System.setErr(new PrintStream(new FileOutputStream("error.txt")));
        StringBuffer file = new StringBuffer();
        Scanner scan = new Scanner(System.in);
        while(scan.hasNextLine()) {
            file.append(scan.nextLine());
            file.append('\n');
        }
        Lexer lexer = new Lexer(file);
        Parser parser = new Parser(lexer.getSymbolList());
        ErrList.print();
    }
}