package Reader;

import java.util.ArrayList;

public class TokenStream {
    private ArrayList<Token> tokens;
    private int p = 0;
    private int nextp = 0;

    public TokenStream(ArrayList<Token> tokens) {
        this.tokens = tokens;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Token token : tokens) {
            sb.append(token);
            sb.append("\n");
        }
        return sb.toString();
    }

    public String toStringWithErr(){
        StringBuilder sb = new StringBuilder();
        for (Token token : tokens) {
            if (token.getErr() != 0) {
                sb.append(token.toStringWithErr());
                sb.append("\n");
            }
        }
        return sb.toString();
    }

    public Token next() {
        if (nextp < tokens.size()) {
            return tokens.get(nextp++);
        }
        return null;
    }

    public Token peek() {
        if (nextp < tokens.size()) {
            return tokens.get(nextp);
        }
        return null;
    }

    public void back() {
        nextp--;
    }

    public void reset() {
        nextp = p;
    }

    public Token look(int step)
    {
        if (nextp + step < tokens.size()) {
            return tokens.get(nextp + step);
        }
        return null;
    }

    public int getLineNumber() {
        return tokens.get(p).getLineNumber();
    }
}
