package frontend.Parser.Statement.StmtElements;

import frontend.Lexer.Token;
import frontend.Parser.Expression.Exp;
import frontend.Parser.Statement.StmtEle;
import frontend.Parser.Terminators.StringConst;

import java.util.ArrayList;

public class PrintfStmtEle implements StmtEle {
    private Token printfToken;
    private Token lparentToken;
    private StringConst stringConst;
    private ArrayList<Token> commaTokens;       // 可选
    private ArrayList<Exp> exps;                // 可选
    private Token rparentToken;
    private Token semicnToken;

    public PrintfStmtEle(Token printfToken,
                        Token lparentToken,
                        StringConst stringConst,
                        ArrayList<Token> commaTokens,
                        ArrayList<Exp> exps,
                        Token rparentToken,
                        Token semicnToken) {
        this.printfToken = printfToken;
        this.lparentToken = lparentToken;
        this.stringConst = stringConst;
        this.commaTokens = commaTokens;
        this.exps = exps;
        this.rparentToken = rparentToken;
        this.semicnToken = semicnToken;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(printfToken);
        sb.append(lparentToken);
        sb.append(stringConst.printString());
        if (!commaTokens.isEmpty()) {
            for (int i = 0; i < commaTokens.size(); i++) {
                sb.append(commaTokens.get(i));
                sb.append(exps.get(i).printString());
            }
        }
        if (rparentToken != null) {
            sb.append(rparentToken);
        }
        if (semicnToken != null) {
            sb.append(semicnToken);
        }
        return sb.toString();
    }
    
}
