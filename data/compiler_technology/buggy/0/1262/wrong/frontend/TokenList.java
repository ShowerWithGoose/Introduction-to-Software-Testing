package frontend;

import java.util.ArrayList;

public class TokenList {
    private ArrayList<Token> tokenArrayList;

    public TokenList() {
        this.tokenArrayList = new ArrayList<>();
    }

    public void addToken(Token token) {
        this.tokenArrayList.add(token);
    }

    public String toErrorString() {
        StringBuilder sb = new StringBuilder();
        for (Token token : tokenArrayList) {
            sb.append(token.getLineNum()).append(" ").append(token.getType()).append("\n");
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Token token : tokenArrayList) {
            sb.append(token.getType()).append(" ").append(token.getContent()).append("\n");
        }
        return sb.toString();
    }
}
