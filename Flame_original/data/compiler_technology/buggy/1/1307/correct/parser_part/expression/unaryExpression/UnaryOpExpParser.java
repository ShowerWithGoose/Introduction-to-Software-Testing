package parser_part.expression.unaryExpression;

import lexer_part.TokenList;
import symbol_part.SymbolList;

public class UnaryOpExpParser {
    private final TokenList tokenList;
    private SymbolList symbolList;

    public UnaryOpExpParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public UnaryOpExp parseUnaryOpExp() {
        UnaryOpParser unaryOpParser = new UnaryOpParser(tokenList);
        UnaryExpParser unaryExpParser = new UnaryExpParser(tokenList, symbolList);
        UnaryOp unaryOp = unaryOpParser.parseUnaryOp();
        UnaryExp unaryExp = unaryExpParser.parseUnaryExp();
        return new UnaryOpExp(unaryOp, unaryExp);
    }
}
