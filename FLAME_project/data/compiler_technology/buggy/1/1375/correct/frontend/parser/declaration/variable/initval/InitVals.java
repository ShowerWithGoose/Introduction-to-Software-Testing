package frontend.parser.declaration.variable.initval;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;

import java.util.ArrayList;

public class InitVals implements InitValEle{
    public Token leftBrace;
    public Exp first; // may not exist
    public ArrayList<Token> commas;
    public ArrayList<Exp> exps;
    public Token rightBrace;

    public InitVals(Token leftBrace,
                    Exp first,
                    ArrayList<Token> commas,
                    ArrayList<Exp> exps,
                    Token rightBrace) {
        this.leftBrace = leftBrace;
        this.first = first;
        this.commas = commas;
        this.exps = exps;
        this.rightBrace = rightBrace;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.leftBrace.syntaxOutput());
        if (first != null) {
            sb.append(this.first.syntaxOutput());
            if (this.commas != null && this.exps != null &&
                    this.commas.size() == this.exps.size()) {
                int len = this.commas.size();
                for (int i = 0; i < len; i++) {
                    sb.append(this.commas.get(i).syntaxOutput());
                    sb.append(this.exps.get(i).syntaxOutput());
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
