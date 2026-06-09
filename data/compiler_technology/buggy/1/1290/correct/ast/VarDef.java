package ast;

import error.ParserError;
import lexical.TokenType;
import semantic.SymbolTable;

import java.util.ArrayList;

public class VarDef extends Symbol {

    private String ident;

    private IdType type;

    private String stringValue = null;

    private AddExp expValue = null;

    private ArrayList<AddExp> list = null;

    private AddExp exp = null;

    private int identLine;

    public int getIdentLine() {
        return identLine;
    }

    public static Symbol of(SymbolTable table) {
        VarDef varDef = new VarDef();
        Symbol symbol;
        if ((symbol = Ident.of()) == null) {
            return null;
        }
        varDef.ident = ((Ident) symbol).getIdent();
        varDef.identLine = symbol.getLine();
        varDef.add(symbol);
        if (token.getType().equals(TokenType.LBRACK)) {
            varDef.add(token);
            token = lexer.nextToken();
            varDef.type = IdType.Array;
            if ((symbol = ConstExp.of(table)) == null) {
                return null;
            }
            varDef.exp = ((ConstExp) symbol).getExp();
            varDef.add(symbol);
            if (!token.getType().equals(TokenType.RBRACK)) {
                logger.log(new ParserError(symbol.getLine(), "k"));
            } else {
                varDef.add(token);
                token = lexer.nextToken();
            }
        } else {
            varDef.type = IdType.Var;
        }
        if (token.getType().equals(TokenType.ASSIGN)) {
            varDef.add(token);
            token = lexer.nextToken();
            if ((symbol = InitVal.of(table)) == null) {
                return null;
            }
            if (((InitVal) symbol).getType().equals(IdType.Var)) {
                varDef.expValue = ((InitVal) symbol).getExp();
            } else if (((InitVal) symbol).getType().equals(IdType.Array)) {
                varDef.list = ((InitVal) symbol).getVarList();
            } else if (((InitVal) symbol).getType().equals(IdType.String)) {
                varDef.stringValue = ((InitVal) symbol).getStringValue();
            }
            varDef.add(symbol);
        }
        return varDef;
    }

    public String getIdent() {
        return ident;
    }

    public IdType getType() {
        return type;
    }

    public String getStringValue() {
        return stringValue;
    }

    public AddExp getExpValue() {
        return expValue;
    }

    public ArrayList<AddExp> getVarList() {
        return list;
    }

    public AddExp getExp() {
        return exp;
    }
}
