package parser_part.expression;

import lexer_part.TokenList;
import parser_part.expression.binaryExpression.BinaryExpParser;
import symbol_part.SymbolList;

public class ConstExpParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public ConstExpParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public ConstExp parseConstExp() {
        BinaryExpParser binaryExpParser = new BinaryExpParser(tokenList, symbolList);
        return new ConstExp(binaryExpParser.parseAddExp());
    }
}
