package frontend.parser.function;

import frontend.error.Error;
import frontend.error.ErrorList;
import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.declaration.BType;

public class FuncFParamParser {
    private TokenIterator iterator;
    private BType bType;
    private Token ident;
    private Token leftBracket;
    private Token rightBracket;

    public FuncFParamParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public FuncFParam parseFuncFParam() {
        // FuncFParam â†’ BType Ident ['[' ']']
        Token t1 = iterator.getNextToken();
        if (t1.getLineNum() == 13) {
            int a = 1;
        }
        if (t1.getType() == TokenType.INTTK || t1.getType() == TokenType.CHARTK) {
            bType = new BType(t1);
        } else {
            System.out.println("parseFuncFParam WA!-1");
            return null;
        }
        ident = iterator.getNextToken();
        Token t2 = iterator.getNextToken();
        if (t2.getType() == TokenType.LBRACK) {
            leftBracket = t2;
            Token t3 = iterator.getNextToken();
            if (t3.getType() == TokenType.RBRACK) {
                rightBracket = t3;
            } else {
                rightBracket = null;
                iterator.ungetToken(2);
                Token t4 = iterator.getNextToken();
                Error error = new Error(t4.getLineNum(), "k");
                ErrorList.addErrorList(error);
            }
        } else {
            leftBracket = null;
            rightBracket = null;
            iterator.ungetToken(1);
        }
        return new FuncFParam(bType, ident, leftBracket, rightBracket);
    }
}
