package fronened.Lexer;

import java.util.ArrayList;

public class TokenIterator {

    private ArrayList<Token> tokens;
    private int currentToken;
    public TokenIterator(ArrayList<Token> tokens) {
        this.tokens = tokens;
        this.currentToken = -1;
    }

    public Token next() {
        currentToken++;
        if (currentToken >= tokens.size()) {
            return new Token(Token.Type.NULL,0,null);
        }
        return tokens.get(currentToken);
    }

    public void back() {
        currentToken--;
    }

    public void back(int n) {
        currentToken -= n;
    }

    public boolean hasNext() {
        return currentToken < tokens.size();
    }

    public Integer now_line() {
        return tokens.get(currentToken).getLine();
    }

    public int getCurrentToken() {
        return currentToken;
    }

    public void setCurrentToken(int currentToken) {
        this.currentToken = currentToken;
    }
}
