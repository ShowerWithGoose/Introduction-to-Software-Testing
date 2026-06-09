package fronened.Parser;

import fronened.Lexer.ErrorList;
import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

import java.io.FileWriter;
import java.io.IOException;

public class Parser {
    TokenIterator iterator;
    String string;

    public Parser(TokenIterator iterator) {
        this.iterator = iterator;
        this.string = "";
    }

    public void parse() {
        CompUnit compUnit = CompUnit.parse(this.iterator);
        this.string = compUnit.print();
    }

    public void print() throws IOException {
        FileWriter writer = new FileWriter("parser.txt");
        if (ErrorList.hasErrors()) {
            ErrorList.printErrors();
        }
        else {
            writer.write(this.string);
        }
        writer.close();
    }
}
