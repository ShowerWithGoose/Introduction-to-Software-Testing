import frontend.executor.Lexer;
import frontend.executor.Parser;
import error.Error;

import java.io.FileWriter;
import java.io.IOException;

public class Compiler {
    public static void main(String[] args) throws IOException {
        clearFiles("error.txt","lexer.txt","parser.txt","test.txt");
        Lexer.getInstance().analyze();
        Lexer.getInstance().print_lexer_result();
        Parser.getInstance().analyze();
        Error.sortErrors();
    }

    public static void clearFiles(String... filePaths) {
        for (String filePath : filePaths) {
            try (FileWriter fileWriter = new FileWriter(filePath, false)) {
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}