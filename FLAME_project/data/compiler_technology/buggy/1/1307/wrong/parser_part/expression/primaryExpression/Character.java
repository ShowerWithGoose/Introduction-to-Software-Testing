package parser_part.expression.primaryExpression;

import lexer_part.Token;
import symbol_part.Symbol;
import symbol_part.SymbolList;

public class Character implements PrimaryExpComponent {

    private Token token;

    public Character(Token token) {
        this.token = token;
    }

    @Override
    public String toString() {
        return token.toString() + "<Character>\n";
    }

    @Override
    public int getArray() {
        return 0;
    }

    @Override
    public Symbol.SymbolType getSymbolType() {
        return Symbol.SymbolType.Char;
    }

    @Override
    public int compute(SymbolList symbolList) {
        return Integer.parseInt(token.getContent());
    }
}
