package frontend.statement.stmt;

import frontend.Token;
import frontend.expression.primaryexp.LVal;

/**
 * 语句: StmtGetchar (LVal = getchar();)
 * 对应文法: StmtGetchar -> LVal '=' 'getchar' '(' ')' ';'
 *
 * 解析 LVal 赋值为从标准输入获取字符的表达式。
 */
public class StmtGetchar implements StmtEle {
    private final LVal lval;
    private final Token eq; // '='
    private final Token getchar; // 'getchar'
    private final Token leftParent; // '('
    private final Token rightParent; // ')'
    private final Token semicn; // ';'

    public StmtGetchar(LVal lval,
                       Token eq,
                       Token getchar,
                       Token leftParent,
                       Token rightParent,
                       Token semicn) {
        this.lval = lval;
        this.eq = eq;
        this.getchar = getchar;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.semicn = semicn;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lval.syntaxOutput());
        sb.append(this.eq.syntaxOutput());
        sb.append(this.getchar.syntaxOutput());
        sb.append(this.leftParent.syntaxOutput());
        sb.append(this.rightParent.syntaxOutput());
        sb.append(this.semicn.syntaxOutput());
        return sb.toString();
    }
}