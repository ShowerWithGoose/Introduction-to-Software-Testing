import frontend.Lexer;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class Compiler {
    public static void main(String[] args) throws FileNotFoundException {
        boolean lexerPrint = true;
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
}
