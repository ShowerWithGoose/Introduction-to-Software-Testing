import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Compiler {
    public static void main(String[] args) {
        String input;
        try {
            input = String.join("\n", Files.readAllLines(Paths.get("testfile.txt")));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Lexer lexer = new Lexer(input);
        String good = "";
        String bad = "";
        while (lexer.next()) {
            if (lexer.getLexType() == LexType.ERR_SINGLE_AND || lexer.getLexType() == LexType.ERR_SINGLE_OR) {
                bad += lexer.getLineno() + " " + "a" + "\n";
            } else {
                good += lexer.getLexType() + " " + lexer.getToken() + "\n";
            }
        }
        try {
            if (bad.isEmpty()) {
                Files.write(Paths.get("lexer.txt"), good.getBytes());
            } else {
                Files.write(Paths.get("error.txt"), bad.getBytes());
            }

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}