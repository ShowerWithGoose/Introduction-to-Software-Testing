import frontend.Lexer;
import frontend.Token;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

import static frontend.TypeCode.*;

class Compiler {
    public static void main(String[] args) throws IOException {
        String inputFile = "testfile.txt";
        String outFile = "lexer.txt";
        String outErrorFile = "error.txt";
        BufferedReader in = new BufferedReader(new FileReader(inputFile));
        BufferedWriter out = new BufferedWriter(new FileWriter(outFile));
        BufferedWriter err = new BufferedWriter(new FileWriter(outErrorFile));
        Lexer lexer = new Lexer(in);
        Token token = lexer.getToken();
        while (!token.isType(EOF)) {
            if (token.isType(ERR)) {
                err.write(token.toString());
                err.newLine();
            } else {
                out.write(token.toString());
                out.newLine();
            }
            token = lexer.getToken();
        }
        out.flush();
        err.flush();
    }
}