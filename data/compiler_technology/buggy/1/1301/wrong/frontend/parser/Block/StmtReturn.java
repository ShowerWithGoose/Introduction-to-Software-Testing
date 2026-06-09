package frontend.parser.Block;

import error.ErrorHandling;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Exp.Exp;

public class StmtReturn implements StmtElement {
    private Token returnTk;
    private Exp exp; //可能没有
    private Token semicn;
    private TokenList tokens;
    private int errorNum;

    public StmtReturn(TokenList tokens) {
        this.returnTk = null;
        this.exp = null;
        this.semicn = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        returnTk = tokens.nextToken();
        Token token = tokens.nextToken();
        if (startIsExp(token)){
            tokens.rollBack(1);
            exp = new Exp(tokens);
            errorNum += exp.parse();
            token = tokens.nextToken();
        }
        if (token.equals(LexType.SEMICN)) {
            semicn = token;
        } else {
            ErrorHandling.printError(tokens.preNonTerminalLineNum(),'i');
            errorNum++;
            tokens.rollBack(1);
        }
        return errorNum;
    }

    private boolean startIsExp(Token token) {
        if (token.equals(LexType.PLUS) || token.equals(LexType.MINU) || token.equals(LexType.NOT)) {
            return true; //unaryOp
        }
        if (token.equals(LexType.LPARENT) || token.equals(LexType.IDENFR) || token.equals(LexType.INTCON) || token.equals(LexType.CHRCON)) {
            return true; //primaryExp and function
        }
        return false;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(returnTk);
        if (exp != null) {
            sb.append(exp.toSyntaxTree());
        }
        if (semicn != null) {
            sb.append(semicn);
        }
        return sb.toString();
    }
}
