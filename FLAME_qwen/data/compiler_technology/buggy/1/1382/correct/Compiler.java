import frontend.ErrorList;
import frontend.Lexer;
import frontend.Parser;
import frontend.TokenIterator;

import java.io.FileWriter;
import java.io.IOException;

public class Compiler {
    public static void main(String[] args) {
        ErrorList errorList = new ErrorList();
        Lexer lexer = new Lexer(errorList);
        Parser parser = new Parser(errorList, new TokenIterator(lexer.lexerOut()));
        try {
            FileWriter fw = new FileWriter("parser.txt", true);
            fw.write(parser.getCompUnit().toPrint());
            fw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        errorList.popErrors();
    }
}