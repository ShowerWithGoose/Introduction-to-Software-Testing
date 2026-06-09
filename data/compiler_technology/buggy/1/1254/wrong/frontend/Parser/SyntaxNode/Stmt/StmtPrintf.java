package frontend.Parser.SyntaxNode.Stmt;

import frontend.Lexer.Token.Token;
import frontend.Parser.SyntaxNode.Exp;

import java.util.ArrayList;

public class StmtPrintf extends Stmt {
    private Token printfTk;
    private Token lParent;
    private Token stringConst;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;
    private Token rParent;
    private Token semicn;

    public StmtPrintf(Token printfTk, Token lParent, Token stringConst,
                      ArrayList<Token> commas, ArrayList<Exp> exps, Token rParent,
                      Token semicn) {
        this.printfTk = printfTk;
        this.lParent = lParent;
        this.stringConst = stringConst;
        this.rParent = rParent;
        this.semicn = semicn;
        this.commas = commas;
        this.exps = exps;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(printfTk);
        sb.append(lParent);
        sb.append(stringConst);

        for (int i = 0; i < commas.size(); i++) {
            sb.append(commas.get(i));
            sb.append(exps.get(i));
        }

        sb.append(rParent);
        sb.append(semicn);
        sb.append(name + "\n");
        return sb.toString();
    }
}
