package parser_part.expression;

import lexer_part.TokenList;
import parser_part.expression.Cond;
import parser_part.expression.binaryExpression.BinaryExpParser;
import symbol_part.SymbolList;

public class CondParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public CondParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public Cond parseCond() {
        BinaryExpParser binaryExpParser = new BinaryExpParser(tokenList, symbolList);
        return new Cond(binaryExpParser.parseLOrExp());
    }
}
