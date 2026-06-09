package frontend.parser.declaration.constant.constinitval;

import frontend.lexer.Token;
import frontend.parser.expression.ConstExp;

import java.util.ArrayList;

public class ConstInitValMulti implements ConstInitValEle{
    public Token leftBrace; // '{'
    public ConstExp first; // MAY exist
    public ArrayList<Token> commas; // MAY exist
    public ArrayList<ConstExp> constExps; // MAY exist
    public Token rightBrace; // '}'

    public ConstInitValMulti(Token leftBrace,
                             Token rightBrace) {
        this.leftBrace = leftBrace;
        this.rightBrace = rightBrace;
    }

    public ConstInitValMulti(Token leftBrace,
                             Token rightBrace,
                             ConstExp first) {
        this.leftBrace = leftBrace;
        this.rightBrace = rightBrace;
        this.first = first;
    }

    public ConstInitValMulti(Token leftBrace,
                             ConstExp first,
                             ArrayList<Token> commas,
                             ArrayList<ConstExp> constExps,
                             Token rightBrace) {
        this(leftBrace, rightBrace, first);
        this.commas = commas;
        this.constExps = constExps;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.leftBrace.syntaxOutput());
        if (this.first != null) {
            sb.append(this.first.syntaxOutput());
            if (this.commas != null && this.constExps != null
                    && this.commas.size() == this.constExps.size()) {
                int len = this.commas.size();
                for (int i = 0; i < len; i++) {
                    sb.append(this.commas.get(i).syntaxOutput());
                    sb.append(this.constExps.get(i).syntaxOutput());
                }
            }
        }
        sb.append(this.rightBrace.syntaxOutput());
        return sb.toString();
    }
    public int my_line_num() {
        return this.rightBrace.linenum;
    }
}
