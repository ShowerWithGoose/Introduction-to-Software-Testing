package Reader;

import java.util.ArrayList;

public class TokenStream {
    private ArrayList<Token> tokens;
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

    public int size()
    {
        return tokens.size();
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

    public Token get(int i) {
        if (i >= tokens.size()) {
            return null;
        }
        return tokens.get(i);
    }

}
