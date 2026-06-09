package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/13 13:47
 */
public class StmtNodeOfPrintf implements SyntaxNode{
    private Token printfTk;
    private Token leftParent; // '('
    private StringConst stringConst;
    private ArrayList<Token> commmas; // ',' MAY exist
    private ArrayList<Exp> exps;
    private Token rightParent; // ')'
    private Token semicn; // ';'

    public StmtNodeOfPrintf(Token printfTk, Token leftParent, StringConst stringConst, ArrayList<Token> commmas, ArrayList<Exp> exps, Token rightParent, Token semicn) {
        this.printfTk = printfTk;
        this.leftParent = leftParent;
        this.stringConst = stringConst;
        this.commmas = commmas;
        this.exps = exps;
        this.rightParent = rightParent;
        this.semicn = semicn;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.printfTk.output());
        sb.append(this.leftParent.output());
        sb.append(this.stringConst.output());
        if (!this.commmas.isEmpty() && !this.exps.isEmpty() &&
                this.commmas.size() == this.exps.size()) {
            int len = this.commmas.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.commmas.get(i).output());
                sb.append(this.exps.get(i).output());
            }
        }
        sb.append(this.rightParent.output());
        sb.append(this.semicn.output());
        return sb.toString();
    }
}
