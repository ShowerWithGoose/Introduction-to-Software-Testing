package parser_part.declaration.var.varDef;

import lexer_part.Token;
import parser_part.Ident;
import parser_part.declaration.Def;
import parser_part.declaration.var.initVal.InitVal;
import parser_part.expression.ConstExp;
import symbol_part.SymbolList;

import java.util.ArrayList;

public class VarDef implements Def {
    private Ident ident;
    private ArrayList<Token> leftBrackets;
    private ArrayList<ConstExp> constExps;
    private ArrayList<Token> rightBrackets;
    private Token assign;
    private InitVal initVal;

    public VarDef(Ident ident, ArrayList<Token> leftBrackets, ArrayList<ConstExp> constExps,
                  ArrayList<Token> rightBrackets, Token assign, InitVal initVal) {
        this.ident = ident;
        this.leftBrackets = leftBrackets;
        this.constExps = constExps;
        this.rightBrackets = rightBrackets;
        this.assign = assign;
        this.initVal = initVal;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(ident.toString());
        int len = leftBrackets.size();
        for (int i = 0; i < len; i++) {
            sb.append(leftBrackets.get(i).toString());
            sb.append(constExps.get(i).toString());
            sb.append(rightBrackets.get(i).toString());
        }
        if (assign != null && initVal != null) {
            sb.append(assign.toString()).append(initVal.toString());
        }
        return sb + "<VarDef>\n";
    }
    
    public ArrayList<ConstExp> getConstExps() {
        return constExps;
    }

    @Override
    public Ident getIdent() {
        return ident;
    }

    public int getInitVal(SymbolList symbolList) {
        return initVal.getInitVal(symbolList);
    }

    public ArrayList<Integer> getArrayInitVals(SymbolList symbolList) {
        return initVal.getArrayInitVals(symbolList);
    }

    public boolean hasInitVal(){
        return assign != null && initVal != null;
    }

}
