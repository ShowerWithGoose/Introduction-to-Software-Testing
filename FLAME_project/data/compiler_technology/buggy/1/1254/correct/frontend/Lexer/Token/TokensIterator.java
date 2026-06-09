package frontend.Lexer.Token;

import java.util.ArrayList;

public class TokensIterator {
    private ArrayList<Token> tokens;
    private int index;
    private int point;

    public TokensIterator(ArrayList<Token> tokens) {
        this.tokens = tokens;
        this.index = 0;
    }

    public Token nextToken() {
        if (index < tokens.size()) {
            return tokens.get(index);
        } else {
            return null;
        }
    }

    public Token nextToken(int i) {
        if (index + i < tokens.size()) {
            return tokens.get(index + i);
        } else {
            return null;
        }
    }

    public Token lastToken() {
        return tokens.get(index - 1);
    }

    public Token readNextToken() {
        index++;
        return tokens.get(index - 1);
    }

    public boolean hasNextToken() {
        return index < tokens.size();
    }

    public void addRecord() {
        point = index;
    }

    public void returnToRecord() {
        index = point;
    }
}
