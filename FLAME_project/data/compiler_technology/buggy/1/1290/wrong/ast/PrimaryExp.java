package ast;

import error.ParserError;
import lexical.TokenType;
import semantic.SymbolTable;

public class PrimaryExp extends Symbol {

    private DecType type;

    private IdType idType;

    public static Symbol of(SymbolTable table) {
        Symbol symbol;
        PrimaryExp primaryExp = new PrimaryExp();
        if (token.getType().equals(TokenType.LPARENT)) {
            primaryExp.add(token);
            token = lexer.nextToken();
            if ((symbol = Exp.of(table)) == null) {
                return null;
            }
            primaryExp.type = ((Exp) symbol).getType();
            primaryExp.idType = ((Exp) symbol).getIdType();

            primaryExp.add(symbol);
            if (!token.getType().equals(TokenType.RPARENT)) {
                logger.log(new ParserError(symbol.getLine(), "j"));
                return primaryExp;
            }
            primaryExp.add(token);
            token = lexer.nextToken();
            return primaryExp;
        }
        if ((symbol = LVal.of(table)) != null) {
            primaryExp.add(symbol);
            primaryExp.type = ((LVal) symbol).getType();
            primaryExp.idType = ((LVal) symbol).getIdType();
            return primaryExp;
        }
        if ((symbol = Number.of()) != null) {
            primaryExp.add(symbol);
            primaryExp.idType = IdType.Var;
            primaryExp.type = DecType.Int;
            return primaryExp;
        }
        if ((symbol = Char.of()) != null) {
            primaryExp.type = DecType.Char;
            primaryExp.idType = IdType.Var;
            primaryExp.add(symbol);
            return primaryExp;
        }
        return null;
    }

    protected DecType getType() {
        return type;
    }

    protected IdType getIdType() {
        return idType;
    }

}
