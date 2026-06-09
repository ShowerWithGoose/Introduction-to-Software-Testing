package frontend.parser.statement;

import frontend.lexer.Token;
import frontend.parser.expression.Exp;
import frontend.parser.init.StringConst;

import java.util.ArrayList;

public class PrintfStmt implements StmtUnit{
    private Token printfTk;
    private Token leftParent;
    private StringConst strConst;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;
    private Token rightParent;
    private Token semicn;

    public PrintfStmt(Token printfTk, Token leftParent, StringConst strConst, ArrayList<Token> commas, ArrayList<Exp> exps, Token rightParent, Token semicn) {
        this.printfTk = printfTk;
        this.leftParent = leftParent;
        this.strConst = strConst;
        this.commas = commas;
        this.exps = exps;
        this.rightParent = rightParent;
        this.semicn = semicn;
    }

    @Override
    public String syntaxPrint() {
        //'printf''('StringConst {','Exp}')'';' /
        StringBuilder sb = new StringBuilder();
        sb.append(printfTk.syntaxPrint());
        sb.append(leftParent.syntaxPrint());
        sb.append(strConst.syntaxPrint());
        if (commas != null && exps != null) {
            for (int i = 0; i < commas.size(); i++) {
                sb.append(commas.get(i).syntaxPrint());
                sb.append(exps.get(i).syntaxPrint());
            }
        }
        if (rightParent != null) {
            sb.append(rightParent.syntaxPrint());
        }
        if (semicn != null) {
            sb.append(semicn.syntaxPrint());
        }
        return sb.toString();
    }
}
