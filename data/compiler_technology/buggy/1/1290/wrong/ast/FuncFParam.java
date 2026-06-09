package ast;

import error.ParserError;
import lexical.TokenType;

public class FuncFParam extends Symbol {

    private DecType decType;

    private IdType idType;

    private String ident;

    private int identLine;

    public static Symbol of() {
        Symbol symbol;
        FuncFParam funcFParam = new FuncFParam();
        if ((symbol = BType.of()) == null) {
            return null;
        }
        funcFParam.decType = ((BType) symbol).getType();
        funcFParam.add(symbol);
        if ((symbol = Ident.of()) == null) {
            return null;
        }
        funcFParam.ident = ((Ident) symbol).getIdent();
        funcFParam.identLine = symbol.getLine();
        funcFParam.add(symbol);
        if (token.getType().equals(TokenType.LBRACK)) {
            funcFParam.idType = IdType.Array;
            funcFParam.add(token);
            token = lexer.nextToken();
            if (!token.getType().equals(TokenType.RBRACK)) {
                logger.log(new ParserError(symbol.getLine(), "k"));
                return funcFParam;
            }
            funcFParam.add(token);
            token = lexer.nextToken();
        } else {
            funcFParam.idType = IdType.Var;
        }
        return funcFParam;
    }

    public DecType getDecType() {
        return decType;
    }

    public IdType getIdType() {
        return idType;
    }

    public String getIdent() {
        return ident;
    }

    public int getIdentLine() {
        return identLine;
    }
}
