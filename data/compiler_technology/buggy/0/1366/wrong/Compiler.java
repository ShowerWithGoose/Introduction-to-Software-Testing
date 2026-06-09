import frontend.Lexer;
import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;

public class Compiler {

    private static ArrayList<Token> tokens = new ArrayList<>();
    private static ArrayList<Token> errorTokens = new ArrayList<>();

    public static void main(String[] args) {
        lexical_Analysis();
    }

    private static void lexical_Analysis() {
        String sourceFilePath = "testfile.txt";
        String lexerFilePath = "lexer.txt";
        String errorFilePath = "error.txt";
        String source;
        try {
            source = new String(Files.readAllBytes(Paths.get(sourceFilePath)));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Lexer lexer = new Lexer(source);
        while (lexer.hasNext()) {
            Token token = lexer.getToken();
            if (token.getErrorType() == null && token.getLexType() != null){
                tokens.add(token);
            } else if (token.getErrorType() != null && token.getLexType() == null) {
                errorTokens.add(token);
            }
        }
        if (errorTokens.isEmpty()) {
            StringBuilder sb = new StringBuilder();
            for (Token t : tokens) {
                sb.append(t.getLexType().getTypeValue());
                sb.append(" ");
                sb.append(t.getTokenValue());
                sb.append("\n");
            }
            try {
                Files.write(Paths.get(lexerFilePath), sb.toString().getBytes(StandardCharsets.UTF_8));
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        else {
            StringBuilder sb = new StringBuilder();
            for (Token t : errorTokens) {
                sb.append(t.getLineNum());
                sb.append(" ");
                sb.append(t.getErrorType().getError_type());
                sb.append("\n");
            }
            try {
                Files.write(Paths.get(errorFilePath), sb.toString().getBytes(StandardCharsets.UTF_8));
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
