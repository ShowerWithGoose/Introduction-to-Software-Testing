package frontend.Parser.statement.stmt;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.MyErrorType;
import frontend.Parser.expression.Exp;
import frontend.Parser.expression.LVal;
import frontend.Parser.expression.ParserOfExp;
import frontend.Parser.expression.ParserOfLVal;

import java.util.ArrayList;

public class ParserOfAssignStmt {
    private TokenListManager tokenListManager;
    private LVal lVal;
    private Token assignSign;
    private Exp exp;
    private Token semicn;
    private ArrayList<Error> errors;
    public ParserOfAssignStmt(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }
    public AssignStmt parseAssignStmt() {
        this.errors = new ArrayList<>();
        ParserOfLVal parserOfLVal = new ParserOfLVal(tokenListManager);
        this.lVal = parserOfLVal.parseLVal();
        this.errors.addAll(parserOfLVal.getErrors());
        Token token = tokenListManager.getTokenAndMove();
        if(token.getTokenType().equals(TokenType.ASSIGN)){
            this.assignSign = token;
        } else {
            System.out.println("expected assign token in AssignStmt");
        }
        ParserOfExp parserOfExp = new ParserOfExp(tokenListManager);
        this.exp = parserOfExp.parseExp();
        this.errors.addAll(parserOfExp.getErrors());
        token = tokenListManager.getTokenAndMove();
        if(token.getTokenType().equals(TokenType.SEMICN)){
            this.semicn = token;
        } else {
            tokenListManager.lookBackToken(2);
            token = tokenListManager.getTokenAndMove();
            Error error = new Error(token.getLineNo(), MyErrorType.i);
            this.errors.add(error);
            System.out.println("expected semicn token in AssignStmt");
        }
        return new AssignStmt(this.lVal, this.assignSign, this.exp, this.semicn);
    }
    public ArrayList<Error> getErrors() {
        return errors;
    }
}
