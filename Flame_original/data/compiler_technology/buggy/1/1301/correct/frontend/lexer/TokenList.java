package frontend.lexer;

import java.util.ArrayList;

public class TokenList {
    private final ArrayList<Token> tokens;
    private int pos;

    public TokenList() {
        this.tokens = new ArrayList<>();
        this.pos = 0;
    }

    public void addToken(Token token) {
        tokens.add(token);
    }

    public Token nextToken() {
        if (pos >= tokens.size()) {
            return null;
        } else {
            Token token = tokens.get(pos);
            pos++;
            return token;
        }
    }

    public void rollBack(int num) {
        if (pos - num >= 0) {
            pos -= num;
        }
    }

    public int preNonTerminalLineNum() {
        if (pos - 2 >= 0) {
            return tokens.get(pos - 2).getLineNum();
        } else {
            return -1; //impossible
        }
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
