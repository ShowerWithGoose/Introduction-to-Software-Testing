import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

import frontend.Lexer;
import frontend.Parser;
import frontend.Token;

public class Compiler {
    public static void main(String[] args) throws IOException {
        String testFilePath = "testfile.txt";
        String lexerFilePath = "lexer.txt";
        String parserFilePath = "parser.txt";
        String errorFilePath = "error.txt";

        Lexer lexer = new Lexer(testFilePath);
        Parser parser = new Parser(lexer);
        parser.parserCompUnit();

        boolean outputLexer = false;//词法分析输出
        if (outputLexer) {
            if (lexer.getIsCorrect()) {
                ArrayList<Token> tokens = lexer.getTokens();
                try (BufferedWriter bw = new BufferedWriter(new FileWriter(lexerFilePath))) {
                    for (Token token : tokens) {
                        bw.write(token.getType().toString() + " " + token.getContent());
                        bw.newLine();
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        boolean outputParser = true;
        if (outputParser) {
            if (parser.getErrors().isEmpty()) {
                ArrayList<String> parserResult = parser.outputCompUnit();
                try (BufferedWriter bw = new BufferedWriter(new FileWriter(parserFilePath))) {
                    for (String line : parserResult) {
                        bw.write(line);
                        bw.newLine();
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } else {
                try (BufferedWriter bw = new BufferedWriter(new FileWriter(errorFilePath))) {
                    for (String line : parser.getErrors()) {
                        bw.write(line);
                        bw.newLine();
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}