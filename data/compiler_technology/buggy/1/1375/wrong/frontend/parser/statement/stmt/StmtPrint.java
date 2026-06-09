package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;
import frontend.parser.terminal.FormatString;

import java.util.ArrayList;

public class StmtPrint implements StmtEle {
    public Token printf; // 'printf'
    public Token leftParent; // '('
    public FormatString formatString;
    public ArrayList<Token> commmas; // ',' MAY exist
    public ArrayList<Exp> exps;
    public Token rightParent; // ')'
    public Token semicn; // ';'

    public StmtPrint(Token printf,
                     Token leftParent,
                     FormatString formatString,
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
    public int my_line_num(){
        if(semicn!=null){
            return semicn.linenum;
        }else if(rightParent!=null){
            return rightParent.linenum;
        }else if(!exps.isEmpty()){
            return exps.get(exps.size()-1).my_line_num();
        }else{
            return formatString.my_line_num();
        }
    }
}
