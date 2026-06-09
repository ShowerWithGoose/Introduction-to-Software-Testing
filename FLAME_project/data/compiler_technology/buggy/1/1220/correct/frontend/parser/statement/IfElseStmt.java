package frontend.parser.statement;

import frontend.lexer.Token;
import frontend.lexer.TokenType;
import frontend.parser.expression.Cond;

public class IfElseStmt implements StmtUnit{
     //'if' '(' Cond ')' Stmt [ 'else' Stmt ]

    private Token ifTk;
    private Token leftParent;
    private Cond cond;
    private Token rightParent;
    private Stmt first;
    private Token elseTk;
    private Stmt second;

    public IfElseStmt(Token ifTk, Token leftParent, Cond cond,
                      Token rightParent, Stmt first, Token elseTk,
                      Stmt second) {
        this.ifTk = ifTk;
        this.leftParent = leftParent;
        this.cond = cond;
        this.rightParent = rightParent;
        this.first = first;
        this.elseTk = elseTk;
        this.second = second;
    }

    @Override
    public String syntaxPrint() {
        //'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        StringBuilder sb = new StringBuilder();
        sb.append(ifTk.syntaxPrint());
        sb.append(leftParent.syntaxPrint());
        sb.append(cond.syntaxPrint());
        if (rightParent != null) {
            sb.append(rightParent.syntaxPrint());
        }
        sb.append(first.syntaxPrint());
        if (elseTk != null) {
            sb.append(elseTk.syntaxPrint());
        }
        if (second != null) {
            sb.append(second.syntaxPrint());
        }
        return sb.toString();
    }
}
