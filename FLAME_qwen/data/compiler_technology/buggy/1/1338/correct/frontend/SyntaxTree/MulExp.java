package frontend.SyntaxTree;

import frontend.TokenType;

import java.util.ArrayList;

public class MulExp {
    private ArrayList<UnaryExp> unaryExps;
    private ArrayList<TokenType> tokenTypes;

    public MulExp() {
        unaryExps = new ArrayList<UnaryExp>();
        tokenTypes = new ArrayList<TokenType>();
    }

    public void addUnaryExp(UnaryExp unaryExp) {
        unaryExps.add(unaryExp);
    }

    public void addTokenType(TokenType tokenType) {
        tokenTypes.add(tokenType);
    }
}
