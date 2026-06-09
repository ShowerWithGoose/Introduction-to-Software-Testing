import error.CompileError;
import frontend.Lexer;
import frontend.Parser;
import token.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

public class Compiler {
    public static void main(String[] args) {
        Lexer lexer = Lexer.getInstance();
        try {
            lexer.lexicalAnalysis();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Parser parser = Parser.getInstance();
        parser.grammaticalAnalysis();

        printResult(parser);
    }

    private static void printResult(Parser parser) {
        try {
            BufferedWriter output = new BufferedWriter(new FileWriter("parser.txt"));
            BufferedWriter error = new BufferedWriter(new FileWriter("error.txt"));
            ArrayList<Token> tokens = Lexer.getTokens();
            ArrayList<CompileError> compileErrors = CompileError.getCompileErrors();
            HashMap<Integer, ArrayList<String>> nodes = parser.getNodes();
            Collections.sort(compileErrors);
            if (compileErrors.isEmpty()) {
                for (int i = 0; i < tokens.size(); i++) {
                    output.write(tokens.get(i).toString());
                    output.newLine();
                    if (nodes.containsKey(i + 1)) {
                        for (String node : nodes.get(i + 1)) {
                            output.write(node);
                            output.newLine();
                        }
                    }
                }
            } else {
                for (CompileError compileError : compileErrors) {
                    error.write(compileError.toString());
                    error.newLine();
                }
            }
            output.close();
            error.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}