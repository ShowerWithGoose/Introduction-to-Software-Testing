package frontend.parser.Block;

import error.ErrorHandling;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Exp.Exp;

public class StmtExp implements StmtElement {
    private Exp exp; //必须得有，没有的话变成StmtSemicn
    private Token semicn; //由于源程序错误，可能没有这个分号
    private TokenList tokens;
    private int errorNum;

    public StmtExp(TokenList tokens) {
        this.exp = null;
        this.semicn = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        exp = new Exp(tokens);
        errorNum += exp.parse();
        Token token = tokens.nextToken();
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
        sb.append(exp.toSyntaxTree());
        if (semicn != null) {
            sb.append(semicn);
        }
        return sb.toString();
    }
}
