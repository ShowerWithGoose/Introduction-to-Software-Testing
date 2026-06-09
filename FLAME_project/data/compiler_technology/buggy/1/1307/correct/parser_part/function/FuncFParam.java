package parser_part.function;

import lexer_part.Token;
import parser_part.Ident;
import parser_part.Node;
import parser_part.declaration.BType;
import parser_part.expression.ConstExp;

import java.util.ArrayList;

public class FuncFParam implements Node {
    private BType bType;
    private Ident ident;
    private Token leftBracket;
    private Token rightBracket;
    private ArrayList<Token> leftBrackets;
    private ArrayList<ConstExp> constExps;
    private ArrayList<Token> rightBrackets;

    public FuncFParam(BType bType, Ident ident, Token leftBracket, Token rightBracket,
                      ArrayList<Token> leftBrackets, ArrayList<ConstExp> constExps,
                      ArrayList<Token> rightBrackets) {
        this.bType = bType;
        this.ident = ident;
        this.leftBracket = leftBracket;
        this.rightBracket = rightBracket;
        this.leftBrackets = leftBrackets;
        this.constExps = constExps;
        this.rightBrackets = rightBrackets;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(bType.toString() + ident.toString());
        if (leftBracket != null && rightBracket != null) {
            sb.append(leftBracket).append(rightBracket);
            int len = leftBrackets.size();
            for (int i = 0; i < len; i++) {
                sb.append(leftBrackets.get(i));
                sb.append(constExps.get(i));
                sb.append(rightBrackets.get(i));
            }
        }
        sb.append("<FuncFParam>\n");
        return sb.toString();
    }
}
