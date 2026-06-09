package parser_part.declaration.constance;

import lexer_part.Token;
import parser_part.expression.ConstExp;
import parser_part.expression.ConstExpParser;

import java.util.ArrayList;

public class ArrayConstInitVal implements ConstInitValComponent {
    private Token leftBrace;
    private ConstExp first;
    private ArrayList<Token> commas;
    private ArrayList<ConstExp> constInitVals;
    private Token rightBrace;
    private int index;
    private int depth;
    public ArrayConstInitVal(Token leftBrace, ConstExp first, ArrayList<Token> commas,
                             ArrayList<ConstExp> constInitVals, Token rightBrace) {
        this.leftBrace = leftBrace;
        this.first = first;
        this.commas = commas;
        this.constInitVals = constInitVals;
        this.rightBrace = rightBrace;
        index = 0;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(leftBrace.toString());
        if (first != null) {
            sb.append(first);
            int len = constInitVals.size();
            for (int i = 0; i < len; i++) {
                sb.append(commas.get(i));
                sb.append(constInitVals.get(i));
            }
        }
        sb.append(rightBrace);
        return sb.toString();
    }
    public void setDepth(int depth) {
        this.depth = depth;
    }

    public ConstExp getFirst() {
        return first;
    }

    public ArrayList<ConstExp> getConstInitVals() {
        return constInitVals;
    }
}
