package ast;

import lexical.TokenType;
import semantic.SymbolTable;

public class LAndExp extends Symbol {

    public static Symbol of(SymbolTable table) {
        Symbol symbol, symbol1;
        Symbol lAndExp = new LAndExp();
        if ((symbol = EqExp.of(table)) == null) {
            return null;
        }
        lAndExp.add(symbol);
        while (token.getType().equals(TokenType.AND)) {
            symbol1 = new LAndExp();
            symbol1.add(lAndExp);
            lAndExp = symbol1;
            lAndExp.add(token);
            token = lexer.nextToken();
            if ((symbol = EqExp.of(table)) == null) {
                return null;
            }
            lAndExp.add(symbol);
        }
        return lAndExp;
    }
}
