import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import frontend.Lexer;

public class Compiler {
    public static void main(String[] args) throws FileNotFoundException {
        String inputFile = "testfile.txt";
        FileInputStream fis = new FileInputStream(inputFile);
        BufferedInputStream bis = new BufferedInputStream(fis);
        Lexer lexer = new Lexer(bis);
        lexer.printLog();
    }
}