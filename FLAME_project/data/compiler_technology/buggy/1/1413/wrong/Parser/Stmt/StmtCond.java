package Parser.Stmt;

import Lexer.Token;
import Parser.Exp.Cond;

public class StmtCond implements StmtEle {
    private Token ifTk; // 'if'
    private Token leftParent; // '('
    private Cond cond;
    private Token rightParent; // ')'
    private Stmt ifStmt;
    private Token elseTk; // 'else' MAY exist
    private Stmt elseStmt; // MAY exist

    public StmtCond(Token ifTk,
                    Token leftParent,
                    Cond cond,
                    Token rightParent,
                    Stmt ifStmt) {
        this.ifTk = ifTk;
        this.ifStmt = ifStmt;
        this.leftParent = leftParent;
        this.cond = cond;
        this.rightParent = rightParent;
    }

    public StmtCond(Token ifTk,
                    Token leftParent,
                    Cond cond,
                    Token rightParent,
                    Stmt ifStmt,
                    Token elseTk,
                    Stmt elseStmt) {
        this(ifTk, leftParent, cond, rightParent, ifStmt);
        this.elseTk = elseTk;
        this.elseStmt = elseStmt;
    }

    @Override
    public String print_tree() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.ifTk.toStringprint());
        sb.append(this.leftParent.toStringprint());
        sb.append(this.cond.print_tree());
        sb.append(this.rightParent.toStringprint());
        sb.append(this.ifStmt.print_tree());
        if (elseTk != null) {
            sb.append(this.elseTk.toStringprint());
            sb.append(this.elseStmt.print_tree());
        }
//        else {
//            System.out.println("神经病的elsetk"+this.ifTk.getLine());
//        }
        return sb.toString();
    }
}
