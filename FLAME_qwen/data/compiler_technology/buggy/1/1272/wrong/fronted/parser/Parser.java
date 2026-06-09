package fronted.parser;

import fronted.ErrorList;
import fronted.lexer.Lexer;
import fronted.parser.others.CompUnit;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

public class Parser {

    private Lexer lexer;

    private CompUnit compUnit;

    public Parser(Lexer lexer) {
        this.lexer = lexer;
    }

    public void parse() {
        this.compUnit = CompUnit.parse(lexer.getTokenList());
    }

    public void printInformation() {
        if (ErrorList.isEmpty()) {
            //System.err.println(compUnit.toString());
            String outputFile = "parser.txt";
            try {
                OutputStream outputStream = new FileOutputStream(outputFile);
                try {
                    outputStream.write(compUnit.toString().getBytes());
                } catch (IOException e) {
                    System.err.println("Can not Write it!");
                }
            } catch (FileNotFoundException e) {
                System.err.println("Can not Open!");
            }
        } else {
            ErrorList.print();
        }
    }
}
