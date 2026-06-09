package frontend.SyntaxTree;

import frontend.TokenType;

import java.util.ArrayList;

public class EqExp {
    private ArrayList<RelExp> relExps;
    private ArrayList<TokenType> tokenTypes;

    public EqExp() {
        relExps = new ArrayList<RelExp>();
        tokenTypes = new ArrayList<TokenType>();
    }

    public void addRelExp(RelExp relExp) {
        relExps.add(relExp);
    }

    public void addTokenType(TokenType tokenType) {
        tokenTypes.add(tokenType);
    }
}
