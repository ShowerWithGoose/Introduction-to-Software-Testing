package ast;

import lexical.TokenType;
import semantic.SymbolTable;

public class LOrExp extends Symbol {

    public static Symbol of(SymbolTable table) {
        Symbol symbol, symbol1;
        Symbol lOrExp = new LOrExp();
        if ((symbol = LAndExp.of(table)) == null) {
            return null;
        }
        lOrExp.add(symbol);
        while (token.getType().equals(TokenType.OR)) {
            symbol1 = new LOrExp();
            symbol1.add(lOrExp);
            lOrExp = symbol1;
            lOrExp.add(token);
            token = lexer.nextToken();
            if ((symbol = LAndExp.of(table)) == null) {
                return null;
            }
            lOrExp.add(symbol);
        }
        return lOrExp;
    }
}
