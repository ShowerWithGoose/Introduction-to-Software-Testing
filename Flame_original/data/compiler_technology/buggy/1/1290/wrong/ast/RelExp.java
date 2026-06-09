package ast;

import lexical.TokenType;
import semantic.SymbolTable;

public class RelExp extends Symbol {

    public static Symbol of(SymbolTable table) {
        Symbol symbol, symbol1;
        Symbol relExp = new RelExp();
        if ((symbol = AddExp.of(table)) == null) {
            return null;
        }
        relExp.add(symbol);
        while (token.getType().equals(TokenType.LSS) ||
                token.getType().equals(TokenType.LEQ) ||
                token.getType().equals(TokenType.GRE) ||
                token.getType().equals(TokenType.GEQ)) {
            // TODO 输出Rel输出
            symbol1 = new RelExp();
            symbol1.add(relExp);
            relExp = symbol1;
            relExp.add(token);
            token = lexer.nextToken();
            if ((symbol = AddExp.of(table)) == null) {
                return null;
            }
            relExp.add(symbol);
        }
        return relExp;
    }
}
