package parser_part.expression;

import lexer_part.TokenList;
import parser_part.expression.binaryExpression.BinaryExpParser;
import symbol_part.SymbolList;

public class ExpParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public ExpParser(TokenList tokenList,SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public Exp parseExp() {
        BinaryExpParser binaryExpParser = new BinaryExpParser(tokenList,symbolList);
        return new Exp(binaryExpParser.parseAddExp());
    }
}
