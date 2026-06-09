package parser_part.declaration.var.initVal;

import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.FormatString;
import parser_part.expression.ExpParser;
import symbol_part.SymbolList;

public class InitValParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public InitValParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public InitVal parseInitVal() {
        Token token = tokenList.getNextToken();
        InitValComponent initValComponent = null;
        if (token.getType() == Token.TokenType.LBRACE) {
            tokenList.moveBack(1);
            ArrayInitValParser arrayInitValParser = new ArrayInitValParser(tokenList, symbolList);
            initValComponent = arrayInitValParser.parseArrayInitVal();
        } else if (token.getType() == Token.TokenType.STRCON) {
            initValComponent = new FormatString(token);
        } else {
            tokenList.moveBack(1);
            ExpParser expParser = new ExpParser(tokenList, symbolList);
            initValComponent = expParser.parseExp();
        }
        return new InitVal(initValComponent);
    }

}
