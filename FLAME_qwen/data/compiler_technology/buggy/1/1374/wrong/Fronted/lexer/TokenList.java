package Fronted.lexer;
import Fronted.parser.Parser;

import java.util.ArrayList;

public class TokenList {
    private static final TokenList tokenList = new TokenList();

    public static TokenList getTokenList() {
        return tokenList;
    }

    private ArrayList<Token> tokens = new ArrayList<>();

    public void add(Token token) {
        this.tokens.add(token);
    }

        @Override
    public String toString() {
        StringBuilder out=new StringBuilder();
        for(Token token : this.tokens){
            out.append(token);
        }
        return out.toString();
    }


    public Token get(int index) {
        return this.tokens.get(index);
    }

    public int size() {
        return this.tokens.size();
    }
}
