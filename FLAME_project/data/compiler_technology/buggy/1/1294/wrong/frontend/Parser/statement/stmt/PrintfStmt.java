package frontend.Parser.statement.stmt;

import frontend.Lexer.Token;
import frontend.Parser.expression.Exp;
import frontend.Parser.statement.StmtPort;
import frontend.Parser.terminal.StringConst;

import java.util.ArrayList;

public class PrintfStmt implements StmtPort {
    private Token printfTk;
    private Token lParent;
    private StringConst stringConst;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;
    private Token rParent;
    private Token semicn;

    public PrintfStmt(Token printfTk,Token lParent,StringConst stringConst,
                      ArrayList<Token> commas,ArrayList<Exp> exps,Token rParent,Token semicn){
        this.printfTk = printfTk;
        this.lParent = lParent;
        this.stringConst = stringConst;
        this.commas = commas;
        this.exps = exps;
        this.rParent = rParent;
        this.semicn = semicn;
    }
    @Override
    public String grammarOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(printfTk.grammarOutput());
        sb.append(lParent.grammarOutput());
        sb.append(stringConst.getToken().grammarOutput());
        if (commas != null && exps != null && commas.size() == exps.size()) {
            for (int i = 0; i < exps.size(); i++) {
                sb.append(commas.get(i).grammarOutput());
                sb.append(exps.get(i).grammarOutput());
            }
        }
        sb.append(rParent.grammarOutput());
        sb.append(semicn.grammarOutput());
        return sb.toString();
    }
}
