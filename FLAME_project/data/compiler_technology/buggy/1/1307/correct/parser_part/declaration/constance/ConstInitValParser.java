package parser_part.declaration.constance;

import error_part.Error;
import error_part.ErrorList;
import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.FormatString;
import parser_part.expression.ConstExpParser;
import parser_part.expression.primaryExpression.LVal;
import parser_part.expression.primaryExpression.LValParser;
import symbol_part.SymbolList;

public class ConstInitValParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public ConstInitValParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public ConstInitVal parseConstInitVal() {
        Token token = tokenList.getNextToken();
        ConstInitValComponent constInitValComponent = null;
        if (token.getType() == Token.TokenType.LBRACE) {
            tokenList.moveBack(1);
            ArrayConstInitValParser arrayConstInitValParser = new ArrayConstInitValParser(tokenList, symbolList);
            constInitValComponent = arrayConstInitValParser.parseArrayConstInitVal();
        } else if (token.getType() == Token.TokenType.STRCON) {
            constInitValComponent = new FormatString(token);
        } else {
            tokenList.moveBack(1);
            ConstExpParser constExpParser = new ConstExpParser(tokenList, symbolList);
            constInitValComponent = constExpParser.parseConstExp();
        }
        return new ConstInitVal(constInitValComponent);
    }
}
