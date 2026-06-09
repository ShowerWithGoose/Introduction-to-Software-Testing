package frontend.parser.init;

import frontend.lexer.Token;
import frontend.parser.expression.ConstExp;

import java.util.ArrayList;

public class ConstInitValMulti implements ConstInitValUnit{
    // '{' [ ConstExp { ',' ConstExp } ] '}'
    private Token leftBrace;
    private Token rightBrace;
    private ConstExp first;
    private ArrayList<Token> commas;
    private ArrayList<ConstExp> constExps;

    public ConstInitValMulti(Token leftBrace, Token rightBrace, ConstExp first,
                             ArrayList<Token> commas, ArrayList<ConstExp> constExps) {
        this.leftBrace = leftBrace;
        this.rightBrace = rightBrace;
        this.first = first;
        this.commas = commas;
        this.constExps = constExps;
    }

    @Override
    public String syntaxPrint() {
        // '{' [ ConstExp { ',' ConstExp } ] '}'
        StringBuilder sb = new StringBuilder();
        sb.append(leftBrace.syntaxPrint());
        if (first != null) {
            sb.append(first.syntaxPrint());
            if (commas != null && constExps != null) {
                for (int i = 0; i < commas.size(); i++) {
                    sb.append(commas.get(i).syntaxPrint());
                    sb.append(constExps.get(i).syntaxPrint());
                }
            }
        }
        if (rightBrace != null) {
            sb.append(rightBrace.syntaxPrint());
        }
        return sb.toString();
    }
}
