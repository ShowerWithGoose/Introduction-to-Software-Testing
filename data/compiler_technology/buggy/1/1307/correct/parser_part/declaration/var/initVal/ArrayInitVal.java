package parser_part.declaration.var.initVal;

import lexer_part.Token;
import parser_part.expression.Exp;

import java.util.ArrayList;

public class ArrayInitVal implements InitValComponent {
    private Token leftBrace;
    private Exp initVal;
    private ArrayList<Token> commas;
    private ArrayList<Exp> initVals;
    private Token rightBrace;
    private int depth;
    private int index;

    public ArrayInitVal(Token leftBrace, Exp initVal, ArrayList<Token> commas,
                        ArrayList<Exp> initVals, Token rightBrace) {
        this.leftBrace = leftBrace;
        this.initVal = initVal;
        this.commas = commas;
        this.initVals = initVals;
        this.rightBrace = rightBrace;
        index = 0;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder(leftBrace.toString());
        if (initVal != null) {
            sb.append(initVal);
            int len = initVals.size();
            for (int i = 0; i < len; i++) {
                sb.append(commas.get(i));
                sb.append(initVals.get(i));
            }
        }
        sb.append(rightBrace);
        return sb.toString();
    }

    public void setDepth(int depth) {
        this.depth = depth;
    }

    public Exp getFirst() {
        return initVal;
    }

    public ArrayList<Exp> getInitVals() {
        return initVals;
    }
}
