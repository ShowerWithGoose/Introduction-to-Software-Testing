package frontend;

import frontend.Lexer.Lexer;
import frontend.Parser.CompUnit;
import frontend.Parser.Parser;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Logger {
    private final Parser parser;
    private final Lexer lexer;

    public Logger(Parser parser, Lexer lexer)
    {
        this.parser = parser;
        this.lexer = lexer;
    }

    public void printlog()
    {
        CompUnit compUnit = parser.parseCompUnit();
        Error errorLog = parser.getErrorLog();
        ArrayList<Integer> line = lexer.geterrorLine();
        if (!line.isEmpty()) {
            for (Integer i : line) {
                errorLog.add(i, 'a');
            }
        }
        if (errorLog.isEmpty()) {
            try (FileWriter writer = new FileWriter("parser.txt")) {
                writer.write(compUnit.toString());
            } catch (IOException e) {
                System.err.println("Error writing to lexer.txt: " + e.getMessage());
            }
        } else {
            errorLog.sort();
            try (FileWriter writer = new FileWriter("error.txt")) {
                for (Error.oneError error : errorLog.getErrorList()) {
                    writer.write(error.getErrorLine() + " " + error.getErrorChar() + "\n");
                }
            } catch (IOException e) {
                System.err.println("Error writing to error.txt: " + e.getMessage());
            }
        }
    }
}
