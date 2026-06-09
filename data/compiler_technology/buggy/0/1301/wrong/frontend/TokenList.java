package frontend;

import java.util.ArrayList;

public class TokenList {
    private final ArrayList<Token> tokens;

    public TokenList() {
        this.tokens = new ArrayList<>();
    }

    public void addToken(Token token) {
        tokens.add(token);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Token token : tokens) {
            sb.append(token.getType() + " " + token.getContent() + "\n");
        }
        return sb.toString();
    }
}
