package frontend.parser.Block;

import error.ErrorHandling;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Exp.Exp;

import java.util.ArrayList;

public class StmtPrintf implements StmtElement {
    private Token printfTk;
    private Token lparent;
    private Token stringConst;
    private ArrayList<Token> commas; //可以没有
    private ArrayList<Exp> exps; //可以没有
    private Token rparent;
    private Token semicn;
    private TokenList tokens;
    private int errorNum;

    public StmtPrintf(TokenList tokens) {
        this.printfTk = null;
        this.lparent = null;
        this.stringConst = null;
        this.commas = new ArrayList<>();
        this.exps = new ArrayList<>();
        this.rparent = null;
        this.semicn = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        printfTk = tokens.nextToken();
        lparent = tokens.nextToken();
        stringConst = tokens.nextToken();
        Token token = tokens.nextToken();
        while (token.equals(LexType.COMMA)) {
            commas.add(token);
            Exp exp = new Exp(tokens);
            errorNum += exp.parse();
            exps.add(exp);
            token = tokens.nextToken();
        }
        if (token.equals(LexType.RPARENT)) {
            rparent = token;
        } else {
            ErrorHandling.printError(tokens.preNonTerminalLineNum(),'j');
            errorNum++;
            tokens.rollBack(1);
        }
        token = tokens.nextToken();
        if (token.equals(LexType.SEMICN)) {
            semicn = token;
        } else {
            ErrorHandling.printError(tokens.preNonTerminalLineNum(),'i');
            errorNum++;
            tokens.rollBack(1);
        }
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(printfTk).append(lparent).append(stringConst);
        for (int i = 0;i < exps.size();i++) {
            sb.append(commas.get(i)).append(exps.get(i).toSyntaxTree());
        }
        if (rparent != null) {
            sb.append(rparent);
        }
        if (semicn != null) {
            sb.append(semicn);
        }
        return sb.toString();
    }
}
