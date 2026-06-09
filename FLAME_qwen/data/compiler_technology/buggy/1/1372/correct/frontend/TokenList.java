package frontend;

import java.util.ArrayList;

public class TokenList {
    private ArrayList<Token> tokens;
    private int index;

    public TokenList(ArrayList<Token> tokens) {
        this.tokens = tokens;
        this.index = 0;
    }

    public Token getThis() {
        if (EOF()) {
            return null;
        } else {
            return tokens.get(index);
        }
    }

    public void goNext() {
        if (index < tokens.size() - 1) {
            index++;
        }
    }

    public int mark() {
        return index;
    }

    public void backtrack(int pos) {
        index = pos;
    }

    public Boolean EOF() {
        return index > tokens.size() - 1;
    }

    public Token preview(int stride) {
        if (index+stride > tokens.size() - 1) {
            return null;
        } else {
            return tokens.get(index+stride);
        }
    }

    public int getErrLine() {
        if( index == 0 ) {
            return 1;
        } else {
            return tokens.get(index-1).getLineNum();
        }
    }

}
