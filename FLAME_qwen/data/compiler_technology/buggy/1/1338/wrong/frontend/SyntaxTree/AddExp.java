package frontend.SyntaxTree;

import frontend.TokenType;

import java.util.ArrayList;

public class AddExp {
    private ArrayList<MulExp> mulExps;
    private ArrayList<TokenType> tokenTypes;

    public AddExp() {
        mulExps = new ArrayList<MulExp>();
        tokenTypes = new ArrayList<TokenType>();
    }

    public void addMulExp(MulExp mulExp) {
        mulExps.add(mulExp);
    }

    public void addTokenType(TokenType tokenType) {
        tokenTypes.add(tokenType);
    }
}
