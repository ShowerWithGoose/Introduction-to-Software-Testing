package frontend;

import java.util.ArrayList;

public class TokenList {
    public ArrayList<Token> tokenLists = new ArrayList<Token>();
    int index = 0;

    public void append(Token token) {
        tokenLists.add(token);
    }

    public boolean hasNext() {
        return index < tokenLists.size() - 1;
    }

    public Token get() {
        return tokenLists.get(index);
    }

    public Token getBefore() {
        return index > 0 ? tokenLists.get(index - 1) : null;
    }

    public int getIndex() {
        return index;
    }

    public void setIndex(int index) {
        this.index = index;
    }

    public Token ahead(int cnt) {
        return tokenLists.get(index + cnt);
    }

    public Token consume() {
        return tokenLists.get(index++);
    }

    public Token consumeExpect(TokenType... types) {
        Token token = tokenLists.get(index);
        if (!token.isOf(types)) {
            return null;
//            TODO:
//            throw new SyntaxException("Expected " + types + " but got " + token.type);
        }
        index++;
        return token;
    }

    public void print() {
        ArrayList<String> tokens = new ArrayList<>();
        for (Token token : tokenLists) {
            tokens.add(token.toString());
        }
        util.File.writeFile("lexer.txt", tokens);
    }
}
