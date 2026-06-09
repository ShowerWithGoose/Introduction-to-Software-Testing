package frontend.declaration.constant.constinitval;

import frontend.Token;
import frontend.expression.ConstExp;
import java.util.List;

/**
 * 常量初值 ConstInitValMulti -> '{' [ <ConstExp> { ',' <ConstExp> } ] '}'
 */
public class ConstInitValMulti implements ConstInitValEle {
    private final Token leftBrace; // '{'
    private final Token rightBrace; // '}'
    private ConstExp first; // MAY exist
    private List<Token> commas; // MAY exist
    private List<ConstExp> constExps; // MAY exist

    public ConstInitValMulti(Token leftBrace, Token rightBrace) {
        if (leftBrace == null || rightBrace == null) {
            throw new IllegalArgumentException("Braces cannot be null");
        }
        this.leftBrace = leftBrace;
        this.rightBrace = rightBrace;
        this.first = null;
        this.commas = null;
        this.constExps = null;
    }

    public ConstInitValMulti(Token leftBrace, Token rightBrace, ConstExp first) {
        this(leftBrace, rightBrace);
        this.first = first;
    }

    public ConstInitValMulti(Token leftBrace, ConstExp first, List<Token> commas, List<ConstExp> constExps, Token rightBrace) {
        this(leftBrace, rightBrace, first);
        if (commas != null && constExps != null && commas.size() != constExps.size()) {
            throw new IllegalArgumentException("Commas and constExps must have the same size");
        }
        this.commas = commas;
        this.constExps = constExps;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(leftBrace.syntaxOutput());
        if (first != null) {
            sb.append(first.syntaxOutput());
            if (commas != null && constExps != null) {
                for (int i = 0; i < commas.size(); i++) {
                    sb.append(commas.get(i).syntaxOutput());
                    sb.append(constExps.get(i).syntaxOutput());
                }
            }
        }
        sb.append(rightBrace.syntaxOutput());
        return sb.toString();
    }

    @Override
    public String toString() {
        return syntaxOutput();
    }
}
