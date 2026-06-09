import frontend.Lexer;
import frontend.Parser;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class Compiler {
    public static void main(String[] args){
        String file_in = "testfile.txt";
        String file_out = "parser.txt";
        String file_error = "error.txt";
        try {
            BufferedReader in = new BufferedReader(new FileReader(file_in));
            BufferedWriter out = new BufferedWriter(new FileWriter(file_out));
            BufferedWriter error = new BufferedWriter(new FileWriter(file_error));
            // Lexer
            // Lexer lexer = Lexer.getInstance(in, out, error);
            // lexer.run();
            // Parser
            Parser parser = Parser.getInstance(in,out,error);
            parser.run();

            in.close();
            out.close();
            error.close();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}