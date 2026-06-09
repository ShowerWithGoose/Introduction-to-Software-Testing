import java.io.IOException;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) throws IOException {
        Text text = new Text();
        Lexer lexer = new Lexer();
        ArrayList<String> lines = text.getLines();
        ArrayList<Word> words = lexer.getWords(lines);
        if (lexer.hasError()) {
            text.printError(lexer.getErrorRow(),lexer.getError());
        }
        else {
            text.printWord(words);
        }
    }
}