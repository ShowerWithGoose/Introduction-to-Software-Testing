import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;

public class Compiler {
    public static void main(String[] args) throws IOException {
        File input = new File("testfile.txt");
        String content = Files.readString(input.toPath());
        Lexer lexer = new Lexer(content);
        printLex(lexer);
    }

    private static void printLex(Lexer lexer) throws IOException {
        File output = new File("lexer.txt");
        if (!output.exists()) {
            output.createNewFile();
        }
        File error = new File("error.txt");
        if (!error.exists()) {
            error.createNewFile();
        }
        FileWriter fw1 = new FileWriter(output, false);
        FileWriter fw2 = new FileWriter(error, false);
        while (lexer.getToken() != null) {
            if (lexer.getToken().equals("|") || lexer.getToken().equals("&")) {
                fw2.write(lexer.getLineno() + " a\n");
            } else {
                if (!lexer.getToken().isEmpty()) {
                    fw1.write(lexer.getType() + " " + lexer.getToken() + "\n");
                }
            }
            lexer.next();
        }
        fw1.close();
        fw2.close();
    }
}
