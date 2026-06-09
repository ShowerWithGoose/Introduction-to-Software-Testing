import frontend.Lexer;
import frontend.Token;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Compiler {
    public static void main (String[] args) throws IOException {
        Lexer lexer = new Lexer("testfile.txt");
        String errorFilePath = "error.txt";
        String lexerFilePath = "lexer.txt";
        if (lexer.getIsLexerWrong()) {
            // 词法分析出错，写到error.txt
            FileWriter write = new FileWriter(errorFilePath);
            try (BufferedWriter errorWriter = Files.newBufferedWriter(Paths.get(errorFilePath), java.nio.charset.StandardCharsets.UTF_8, java.nio.file.StandardOpenOption.APPEND)) {
                for (String s : lexer.getLexerWrongInformation()) {
                    errorWriter.write(s + "\n");
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            // tokens写到lexer.txt
            FileWriter write = new FileWriter(lexerFilePath);
            try (BufferedWriter lexerWriter = Files.newBufferedWriter(Paths.get(lexerFilePath), java.nio.charset.StandardCharsets.UTF_8, java.nio.file.StandardOpenOption.APPEND)) {
                for (Token token : lexer.getTokens()) {
                    lexerWriter.write(token.getTypeString() + " " + token.getValue() + "\n");
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
