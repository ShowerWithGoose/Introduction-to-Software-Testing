package lexer_part;

import java.util.ArrayList;

public class TokenList {
    private ArrayList<Token> list;
    private int curIndex;

    public TokenList() {
        this.list = new ArrayList<>();
        curIndex = -1;
    }

    public void addToken(Token token) {
        list.add(token);
    }

    public Token getNextToken() {
        curIndex++;
        if (curIndex < list.size()) {
            return list.get(curIndex);
        }
        return null;
    }

    public void moveBack(int cnt) {
        curIndex -= cnt;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Token token : list) {
            sb.append(token.getType()).append(" ").append(token.getContent()).append("\n");
        }
        return sb.toString();
    }

    public Token getCurToken() {
        return list.get(curIndex);
    }

    public boolean isNotEnd() {
        return curIndex < list.size() - 1;
    }

    public void merge() {
        int i = 0;
        ArrayList<Token> ans = new ArrayList<>();
        while (i < list.size()) {
            Token token = list.get(i);
            if (token.getType() == Token.TokenType.PLUS || token.getType() == Token.TokenType.MINU) {
                int flag = 1;
                while (list.get(i).getType() == Token.TokenType.PLUS || list.get(i).getType() == Token.TokenType.MINU) {
                    if (list.get(i).getType() == Token.TokenType.MINU) {
                        flag *= -1;
                    }
                    i++;
                }
                if (flag == -1) {
                    ans.add(new Token(Token.TokenType.MINU, "-", 0));
                } else {
                    ans.add(new Token(Token.TokenType.PLUS, "+", 0));
                }
                continue;
            } else {
                ans.add(token);
            }
            i++;
        }
        list = ans;
    }
}
