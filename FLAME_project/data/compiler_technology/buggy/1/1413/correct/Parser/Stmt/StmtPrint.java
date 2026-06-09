package Parser.Stmt;

import Lexer.Token;
import Parser.Exp.Exp;

import java.util.ArrayList;

public class StmtPrint implements StmtEle {
    private Token printf; // 'printf'
    private Token leftParent; // '('
    private Token stringConst;
    private ArrayList<Token> commmas; // ',' MAY exist
    private ArrayList<Exp> exps;
    private Token rightParent; // ')'
    private Token semicn; // ';'

    public StmtPrint(Token printf,
                     Token leftParent,
                     Token stringConst,
                     ArrayList<Token> commas,
                     ArrayList<Exp> exps,
                     Token rightParent,
                     Token semicn) {
        this.printf = printf;
        this.leftParent = leftParent;
        this.stringConst = stringConst;
        this.commmas = commas;
        this.exps = exps;
        this.rightParent = rightParent;
        this.semicn = semicn;
    }

    @Override
    public String print_tree() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.printf.toStringprint());
        sb.append(this.leftParent.toStringprint());
        sb.append(this.stringConst.toStringprint());
        for (int i = 0; i < commmas.size(); i++) {
            sb.append(this.commmas.get(i).toStringprint());
            sb.append(this.exps.get(i).print_tree());
        }
        sb.append(this.rightParent.toStringprint());
        sb.append(this.semicn.toStringprint());
        return sb.toString();

    }
}
