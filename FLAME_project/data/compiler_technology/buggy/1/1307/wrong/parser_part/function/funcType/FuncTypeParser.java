package parser_part.function.funcType;

import lexer_part.Token;
import lexer_part.TokenList;

public class FuncTypeParser {
    private TokenList tokenList;

    public FuncTypeParser(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public FuncType parseFuncType() {
        Token token = tokenList.getNextToken();
        if (isFuncType(token)) {
            return new FuncType(token);
        }
        //System.err.println("expect int or void or float in FuncType");
        return null;
    }

    public boolean isFuncType(Token token) {
        return token.getType() == Token.TokenType.INTTK ||
                token.getType() == Token.TokenType.VOIDTK ||
                token.getType() == Token.TokenType.FLOATTK ||
                token.getType() == Token.TokenType.CHARTK;
    }
}
