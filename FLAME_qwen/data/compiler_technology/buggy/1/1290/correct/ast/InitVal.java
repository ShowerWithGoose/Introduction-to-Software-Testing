package ast;

import lexical.TokenType;
import semantic.SymbolTable;

import java.util.ArrayList;

public class InitVal extends Symbol {

    private String stringValue;

    private ArrayList<AddExp> list = new ArrayList<>();

    private AddExp exp;

    private IdType type;

    public static Symbol of(SymbolTable table) {
        Symbol symbol;
        InitVal initVal = new InitVal();
        if ((symbol = Exp.of(table)) != null) {
            initVal.add(symbol);
            initVal.exp = ((Exp) symbol).getExp();
            initVal.type = IdType.Var;
            return initVal;
        } else if (token.getType().equals(TokenType.LBRACE)) {
            initVal.add(token);
            token = lexer.nextToken();
            initVal.type = IdType.Array;
            if ((symbol = Exp.of(table)) != null) {
                initVal.add(symbol);
                initVal.list.add(((Exp) symbol).getExp());
                while (token.getType().equals(TokenType.COMMA)) {
                    initVal.add(token);
                    token = lexer.nextToken();
                    if ((symbol = Exp.of(table)) == null) {
                        return null;
                    }
                    initVal.add(symbol);
                    initVal.list.add(((Exp) symbol).getExp());
                }
            }
            if (!token.getType().equals(TokenType.RBRACE)) {
                return null;
            }
            initVal.add(token);
            token = lexer.nextToken();
        } else if ((symbol = StringConst.of()) != null) {
            initVal.add(symbol);
            initVal.type = IdType.String;
            initVal.stringValue = ((StringConst) symbol).getValue();
        } else {
            return null;
        }
        return initVal;
    }

    public String getStringValue() {
        return stringValue;
    }

    public ArrayList<AddExp> getVarList() {
        return list;
    }

    public AddExp getExp() {
        return exp;
    }

    protected IdType getType() {
        return type;
    }
}
