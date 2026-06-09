import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) throws IOException {
        String path1 = "testfile.txt";
        String path2 = "lexer.txt";
        String path3 = "error.txt";
        String string = null;
        try {
            string = new String(Files.readAllBytes(Paths.get(path1)));
        } catch (IOException e) {
            e.printStackTrace();
        }
        ArrayList<Lexer.Token> tokens = new ArrayList<>();
        Lexer.Token token = null;
        Lexer lexer = new Lexer(string);
        while (lexer.getPos() < string.length()) {
            token = lexer.move();
            if (token != null) {
                tokens.add(token);
            }
        }
        if (lexer.getErrorLineNum() != 0) {
            StringBuilder s = new StringBuilder();
            s.append(lexer.getErrorLineNum() + " a\n");
            try (FileOutputStream fos = new FileOutputStream(path3, false)) {
                byte[] bytesToWrite = s.toString().getBytes();
                fos.write(bytesToWrite);
            }
        }
        else {
            StringBuilder s = new StringBuilder();
            for (Lexer.Token myToken : tokens) {
                s.append(myToken.getToken());
            }
            try (FileOutputStream fos = new FileOutputStream(path2, false)) {
                byte[] bytesToWrite = s.toString().getBytes();
                fos.write(bytesToWrite);
            }
        }
    }
}