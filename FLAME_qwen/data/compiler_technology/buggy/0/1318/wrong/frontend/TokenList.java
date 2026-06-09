package frontend;

import java.util.ArrayList;

import static utils.File.WriteFile;

public class TokenList {
    private final ArrayList<Token> tokens = new ArrayList<>();

    public void add(Token token) {
        tokens.add(token);
    }

    public void print() {
        ArrayList<String> content = new ArrayList<>();
        for (Token token : this.tokens) {
            content.add(token.toString());
        }
        WriteFile("lexer.txt", content);
    }
}