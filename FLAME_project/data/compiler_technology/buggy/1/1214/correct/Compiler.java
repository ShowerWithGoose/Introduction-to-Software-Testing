import frontend.Lexer;
import frontend.Parser;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class Compiler {
    public static void main(String[] args) throws FileNotFoundException {
        boolean lexerPrint = false;
        boolean parserPrint = true;
        Path path = Paths.get("testfile.txt");
        String source;
        try {
            source = Files.readString(path);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Lexer lexer = new Lexer(source);
        lexer.next();
        if (lexerPrint) {
            printLexerMessage(lexer);
        }
        Parser parser = new Parser(lexer.tokens);
        parser.getAST();
        if (parserPrint) {
            printParserMessage(parser);
        }
    }

    private static void printLexerMessage(Lexer lexer) {
        if (lexer.isError()) {
            String outPath = "error.txt";
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(outPath))) {
                for (Lexer.Error error : lexer.errors) {
                    writer.write(error.line + " " + error.errorType);
                    writer.newLine();
                }
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        } else {
            String outPath = "lexer.txt";
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(outPath))) {
                for (Lexer.Token token : lexer.tokens) {
                    writer.write(token.tokenType + " " + token.token);
                    writer.newLine();
                }
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }

    private static void printParserMessage(Parser parser) {
        if (parser.isError()) {
            String outPath = "error.txt";
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(outPath))) {
                for (Lexer.Error error : parser.parserErrors) {
                    writer.write(error.line + " " + error.errorType);
                    writer.newLine();
                }
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        } else {
            String outPath = "parser.txt";
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(outPath))) {
                for (String message : parser.parserInfo) {
                    writer.write(message);
                    writer.newLine();
                }
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
