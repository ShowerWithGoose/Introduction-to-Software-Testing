import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

public class Compiler {
    public static void main(String[] args) throws FileNotFoundException {
        String readeraddr = "./testfile.txt";
        Scanner codes = readFile(readeraddr);
        Lexer lexer = new Lexer(codes);
        int lexerAns = lexer.getTokens();
        printLexerAns(lexerAns, lexer);
    }

    public static void printLexerAns(int kind, Lexer lexer) throws FileNotFoundException {
        if (kind == 0) {
            ArrayList<Token> tokens = lexer.getTokensArray();
            FileOutputStream fos = new FileOutputStream("lexer.txt");
            PrintStream ps = new PrintStream(fos);
            System.setOut(ps);
            for (Token token : tokens) {
                System.out.println(token.getKind() + " " + token.getContents());
            }
        } else {
            FileOutputStream fos = new FileOutputStream("error.txt");
            PrintStream ps = new PrintStream(fos);
            System.setOut(ps);
            lexer.printError();
        }
    }

    public static Scanner readFile(String addr) throws FileNotFoundException {
        return new Scanner(new File(addr));
    }
}
