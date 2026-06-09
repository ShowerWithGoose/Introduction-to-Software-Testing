package ast;

import lexical.TokenType;
import semantic.SymbolTable;

public class AddExp extends Symbol {

    private DecType type;

    private IdType idType;

    public static Symbol of(SymbolTable table) {
        Symbol symbol;
        AddExp symbol1;
        AddExp addExp = new AddExp();
        if ((symbol = MulExp.of(table)) == null) {
            return null;
        }
        addExp.add(symbol);
        addExp.type = ((MulExp) symbol).getType();
        addExp.idType = ((MulExp) symbol).getIdType();
        while (token.getType().equals(TokenType.PLUS) ||
                token.getType().equals(TokenType.MINU)) {
            symbol1 = new AddExp();
            symbol1.add(addExp);
            symbol1.type = addExp.type;
            symbol1.idType = addExp.idType;
            addExp = symbol1;
            addExp.add(token);
            token = lexer.nextToken();
            if ((symbol = MulExp.of(table)) == null) {
                return null;
            }
            addExp.add(symbol);
        }
        return addExp;
    }

    public int cal() {
        // TODO
        return 0;
    }

    protected DecType getType() {
        return type;
    }

    protected IdType getIdType() {
        return idType;
    }

}
