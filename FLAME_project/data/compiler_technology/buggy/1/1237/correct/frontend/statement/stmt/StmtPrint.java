package frontend.statement.stmt;

import frontend.Token;
import frontend.expression.Exp;
import frontend.terminal.StringConst;

import java.util.ArrayList;

public class StmtPrint implements StmtEle {
    private Token printf; // 'printf'
    private Token leftParent; // '('
    private StringConst formatString;
    private ArrayList<Token> commmas; // ',' MAY exist
    private ArrayList<Exp> exps;
    private Token rightParent; // ')'
    private Token semicn; // ';'

    public StmtPrint(Token printf,
                     Token leftParent,
                     StringConst formatString,
                     ArrayList<Token> commas,
                     ArrayList<Exp> exps,
                     Token rightParent,
                     Token semicn) {
        this.printf = printf;
        this.leftParent = leftParent;
        this.formatString = formatString;
        this.commmas = commas;
        this.exps = exps;
        this.rightParent = rightParent;
        this.semicn = semicn;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.printf.syntaxOutput());
        sb.append(this.leftParent.syntaxOutput());
        sb.append(this.formatString.syntaxOutput());
        if (this.commmas != null && this.exps != null &&
            this.commmas.size() == this.exps.size()) {
            int len = this.commmas.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.commmas.get(i).syntaxOutput());
                sb.append(this.exps.get(i).syntaxOutput());
            }
        }
        sb.append(this.rightParent.syntaxOutput());
        sb.append(this.semicn.syntaxOutput());
        return sb.toString();
    }
}
