package frontend.parser.declaration.variable.initval;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;

import java.util.ArrayList;

/**
 * <Exp> 多个Exp子节点接口
 * '{' [ <Exp> { ',' <Exp> } ] '}'
 */
public class InitValMultiExp implements InitValEle {
    private Token leftBrace;
    private Exp first; // may not exist
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;
    private Token rightBrace;

    public InitValMultiExp(Token leftBrace,
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
}
