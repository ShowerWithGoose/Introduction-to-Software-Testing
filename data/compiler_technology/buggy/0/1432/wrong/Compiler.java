import frontend.ErrorLog;
import frontend.Lexer;
import frontend.Token;
import frontend.TokenType;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class Compiler {
    public static void main(String[] args) throws IOException {
        Path path = Paths.get("testfile.txt");
        String str = Files.readString(path);
        Lexer lexer = new Lexer(str);
        StringBuilder stringBuilder = new StringBuilder();
        Token token = lexer.getCurrentToken();
        do {
            //System.out.println(token);
            stringBuilder.append(token).append("\n");
            lexer.next();
            token = lexer.getCurrentToken();
        } while(token.getType() != TokenType.END);
        ErrorLog.getInstance().printErrors();
        Path path1 = Paths.get("lexer.txt");
        Files.writeString(path1, stringBuilder.toString());
    }
}