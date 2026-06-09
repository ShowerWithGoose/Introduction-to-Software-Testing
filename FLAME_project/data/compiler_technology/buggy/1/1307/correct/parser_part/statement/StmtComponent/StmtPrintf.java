package parser_part.statement.StmtComponent;

import lexer_part.Token;
import parser_part.FormatString;
import parser_part.expression.Exp;

import java.util.ArrayList;

public class StmtPrintf implements StmtComponent {
    private Token printf;
    private Token leftParent;
    private FormatString formatString;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;
    private Token rightParent;
    private Token semicn;

    public StmtPrintf(Token printf, Token leftParent, FormatString formatString,
                      ArrayList<Token> commas, ArrayList<Exp> exps,
                      Token rightParent, Token semicn) {
        this.printf = printf;
        this.leftParent = leftParent;
        this.formatString = formatString;
        this.commas = commas;
        this.exps = exps;
        this.rightParent = rightParent;
        this.semicn = semicn;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(printf.toString() + leftParent.toString());
        sb.append(formatString.toString());
        int len = commas.size();
        for (int i = 0; i < len; i++) {
            sb.append(commas.get(i));
            sb.append(exps.get(i));
        }
        sb.append(rightParent).append(semicn);
        return sb.toString();
    }
}
