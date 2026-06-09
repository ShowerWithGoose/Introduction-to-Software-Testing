import frontend.ErrorHandler.ErrorHandler;
import frontend.Lexer;
import frontend.Parser.Parser;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

class Compiler {
    public static void main(String[] args) throws IOException {
        String inputFile = "testfile.txt";
        String outFile = "parser.txt";
        String outErrorFile = "error.txt";
        BufferedReader in = new BufferedReader(new FileReader(inputFile));
        BufferedWriter out = new BufferedWriter(new FileWriter(outFile));
        BufferedWriter err = new BufferedWriter(new FileWriter(outErrorFile));
        Lexer lexer = new Lexer(in);
        Parser parser = new Parser(lexer);
        out.write(parser.parseCompUnit().toString());
        ErrorHandler.ERROR.log(err);
        out.flush();
        err.flush();
    }
}