package fronted.lexer;

import java.util.ArrayList;

public class TokenList {

    private final ArrayList<Token> tokens = new ArrayList<>();

    private int pos;
    // for better scanning, it contains all tokens and uses a point to indicate the position which have read

    public TokenList(){
        this.pos = 0;
    }

    public int getPos() {
        return pos;
    }

    public void setPos(int pos) {
        this.pos = pos;
    }

    public void addToken(Token token){
        if (token != null) {
            this.tokens.add(token);
        }
    }

    public Token selectToken(int pos){
        if (pos >= tokens.size()) {
            return null;
        } else {
            return tokens.get(pos);
        }
    }

    public boolean hasToken(){
        return pos < tokens.size();
    }

    public Token next() {
        Token token = this.tokens.get(pos);
        pos++;
        return token;
    } // use it after ** hasToken() **

    public Token now() {
        return this.tokens.get(pos);
    }

    public Token before() {
        if (pos > 0) {
            return this.tokens.get(pos-1);
        } else {
            return null;
        }
    }

    //for pre-read
    public boolean hasAhead(int ahead) {
        return pos + ahead < this.tokens.size();
    }

    public Token getAheadOne(int ahead) {
        return this.tokens.get(pos + ahead);
    } //use it after ** hasAhead() **

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Token token : tokens) {
            sb.append(token.toString());
        }
        return sb.toString();
    }

    public String printTrue() {
        StringBuilder sb = new StringBuilder();
        for (Token token : tokens) {
            if (token.isIfCorrect()) {
                sb.append(token.toString());
            }
        }
        return sb.toString();
    }

    public String printFalse() {
        StringBuilder sb = new StringBuilder();
        for (Token token : tokens) {
            if (!token.isIfCorrect()) {
                sb.append(token.getLine());
                sb.append(" ").append("a").append('\n');
            }
        }
        return sb.toString();
    }
}
