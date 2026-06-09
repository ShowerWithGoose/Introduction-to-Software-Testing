package parser_part.declaration.constance;

import lexer_part.Token;
import parser_part.Ident;
import parser_part.Node;
import parser_part.declaration.Def;
import parser_part.expression.ConstExp;

import java.util.ArrayList;

public class ConstDef implements Def {
    private Ident ident;
    private ArrayList<Token> leftBrackets;
    private ArrayList<ConstExp> constExps;
    private ArrayList<Token> rightBrackets;
    private Token assign;      // '='
    private ConstInitVal constInitVal;

    private boolean isPreDeclared;
    private ArrayList<Integer> dimensions;
    private int size;

    public ConstDef(Ident ident, ArrayList<Token> leftBrackets, ArrayList<ConstExp> constExps,
                    ArrayList<Token> rightBrackets, Token assign, ConstInitVal constInitVal) {
        this.ident = ident;
        this.leftBrackets = leftBrackets;
        this.constExps = constExps;
        this.rightBrackets = rightBrackets;
        this.assign = assign;
        this.constInitVal = constInitVal;
        isPreDeclared = false;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(ident.toString());
        int len = leftBrackets.size();
        for (int i = 0; i < len; i++) {
            sb.append(leftBrackets.get(i));
            sb.append(constExps.get(i));
            sb.append(rightBrackets.get(i));
        }
        sb.append(assign).append(constInitVal).append("<ConstDef>\n");
        return sb.toString();
    }

    @Override
    public Ident getIdent() {
        return ident;
    }

    public ArrayList<ConstExp> getConstExps() {
        return constExps;
    }

    public ConstInitVal getConstInitVal() {
        return constInitVal;
    }
}
