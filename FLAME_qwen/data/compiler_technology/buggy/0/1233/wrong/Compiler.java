import frontend.Lexer;
import frontend.ParserInput;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

public class Compiler {
    public static void main(String[] args) throws FileNotFoundException {
        //parserInput用来处理文件输入并且获得Arraylist<String>
        ParserInput parserInput = new ParserInput();
        Lexer lexer = new Lexer(parserInput.getLines(), parserInput.getInputLine());
        lexer.printResult();
    }
}