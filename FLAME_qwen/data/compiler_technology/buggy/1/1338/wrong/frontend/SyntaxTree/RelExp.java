package frontend.SyntaxTree;

import frontend.TokenType;

import java.util.ArrayList;

public class RelExp {
    private ArrayList<AddExp> addExps;
    private ArrayList<TokenType> tokenTypes;

    public RelExp() {
        addExps = new ArrayList<AddExp>();
        tokenTypes = new ArrayList<TokenType>();
    }

    public void addAddExp(AddExp addExp) {
        addExps.add(addExp);
    }

    public void addTokenType(TokenType tokenType) {
        tokenTypes.add(tokenType);
    }
}
