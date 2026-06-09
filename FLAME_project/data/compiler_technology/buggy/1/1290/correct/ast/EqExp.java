package ast;

import lexical.TokenType;
import semantic.SymbolTable;

public class EqExp extends Symbol {

    public static Symbol of(SymbolTable table) {
        Symbol symbol, symbol1;
        Symbol eqExp = new EqExp();
        if ((symbol = RelExp.of(table)) == null) {
            return null;
        }
        eqExp.add(symbol);
        while (token.getType().equals(TokenType.EQL) ||
                token.getType().equals(TokenType.NEQ)) {
            symbol1 = new EqExp();
            symbol1.add(eqExp);
            eqExp = symbol1;
            eqExp.add(token);
            token = lexer.nextToken();
            if ((symbol = RelExp.of(table)) == null) {
                return null;
            }
            eqExp.add(symbol);
        }
        return eqExp;
    }
}
