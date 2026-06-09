package ast;

import lexical.TokenType;
import semantic.SymbolTable;

public class MulExp extends Symbol {

    private DecType type;

    private IdType idType;

    public static Symbol of(SymbolTable table) {
        Symbol symbol;
        MulExp symbol1;
        MulExp mulExp = new MulExp();
        if ((symbol = UnaryExp.of(table)) == null) {
            return null;
        }
        mulExp.type = ((UnaryExp) symbol).getType();
        mulExp.idType = ((UnaryExp) symbol).getIdType();
        mulExp.add(symbol);
        while (token.getType().equals(TokenType.MULT) ||
                token.getType().equals(TokenType.DIV) ||
                token.getType().equals(TokenType.MOD)) {
            // TODO 输出Mul结束
            symbol1 = new MulExp();
            symbol1.add(mulExp);
            symbol1.type = mulExp.type;
            symbol1.idType = mulExp.idType;
            mulExp = symbol1;
            mulExp.add(token);
            token = lexer.nextToken();
            if ((symbol = UnaryExp.of(table)) == null) {
                return null;
            }
            mulExp.add(symbol);
        }
        return mulExp;
    }

    protected DecType getType() {
        return type;
    }

    protected IdType getIdType() {
        return idType;
    }

}
