package ast;

import error.ParserError;
import error.SemanticError;
import lexical.TokenType;
import semantic.*;

public class LVal extends Symbol {

    private String ident;

    private DecType type;

    private IdType idType;

    private int identLine;

    public static Symbol of(SymbolTable table) {
        Symbol symbol;
        LVal lVal = new LVal();
        if ((symbol = Ident.of()) == null) {
            return null;
        }
        lVal.identLine = symbol.getLine();
        lVal.ident = ((Ident) symbol).getIdent();
        Info info;
        if ((info = table.getInfo(lVal.ident)) == null) {
            logger.log(new SemanticError(lVal.getIdentLine(), "c"));
        }
        if (info instanceof FuncInfo) {
            lVal.idType = IdType.Func;
        } else if (info instanceof ConstCharArrayInfo ||
                    info instanceof ConstIntArrayInfo ||
                    info instanceof VarCharArrayInfo ||
                    info instanceof VarIntArrayInfo) {
            lVal.idType = IdType.Array;
        } else {
            lVal.idType = IdType.Var;
        }
        if (info instanceof VarCharArrayInfo ||
            info instanceof VarCharInfo ||
            info instanceof ConstCharArrayInfo ||
            info instanceof ConstCharInfo ||
            info instanceof CharFuncInfo) {
            lVal.type = DecType.Char;
        } else if (info instanceof VoidFuncInfo) {
            lVal.type = DecType.Void;
        } else {
            lVal.type = DecType.Int;
        }
        lVal.add(symbol);
        if (token.getType().equals(TokenType.LBRACK)) {
            lVal.add(token);
            token = lexer.nextToken();
            if (lVal.idType.equals(IdType.Array)) {
                lVal.idType = IdType.Var;
            }
            if ((symbol = Exp.of(table)) == null) {
                return null;
            }
            lVal.add(symbol);
            if (!token.getType().equals(TokenType.RBRACK)) {
                logger.log(new ParserError(symbol.getLine(), "k"));
                return lVal;
            }
            lVal.add(token);
            token = lexer.nextToken();
        }
        return lVal;
    }

    public String getIdent() {
        return ident;
    }

    public int getIdentLine() {
        return identLine;
    }

    protected DecType getType() {
        return type;
    }

    protected IdType getIdType() {
        return idType;
    }

}
