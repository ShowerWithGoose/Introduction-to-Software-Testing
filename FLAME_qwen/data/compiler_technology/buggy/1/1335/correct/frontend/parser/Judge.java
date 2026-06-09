package frontend.parser;

import frontend.lexer.Token;
import frontend.lexer.Type;


public class Judge {
    boolean isDecl(Token currentToken) {
        return currentToken != null && (currentToken.getType().equals(Type.CONSTTK) || isBType(currentToken));
    }

    boolean isFuncDef(Token currentToken, Token nextToken, Token nextToken2) {
        return currentToken != null && isFuncType(currentToken) && nextToken.getType().equals(Type.IDENFR)
                && nextToken2.getType().equals(Type.LPARENT);
    }

    private boolean isFuncType(Token currentToken) {
        return currentToken.getType() == Type.INTTK || currentToken.getType() == Type.CHARTK ||
                currentToken.getType() == Type.VOIDTK;
    }

    boolean isFuncFParams(Token currentToken) {
        return currentToken != null && isBType(currentToken);
    }

    private boolean isBType(Token currentToken) {
        return currentToken.getType() == Type.CHARTK || currentToken.getType() == Type.INTTK;
    }

    boolean isLVal(Token currentToken) {
        return isIdent(currentToken);
    }

    private boolean isIdent(Token currentToken) {
        return currentToken.getType() == Type.IDENFR;
    }

    public boolean isBlock(Token currentToken) {
        return currentToken.getType() == Type.LBRACE;
    }

    public boolean isForStmt(Token currentToken) {
        return isLVal(currentToken);
    }

    boolean isUnaryOp(Token token) {
        return token.getType() == Type.PLUS || token.getType() == Type.MINU ||
                token.getType() == Type.NOT;
    }

}
