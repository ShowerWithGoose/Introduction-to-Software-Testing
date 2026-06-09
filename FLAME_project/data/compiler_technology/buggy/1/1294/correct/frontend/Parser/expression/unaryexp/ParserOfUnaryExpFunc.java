package frontend.Parser.expression.unaryexp;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.MyErrorType;
import frontend.Parser.expression.FuncRParams;
import frontend.Parser.expression.ParserOfFuncRParams;
import frontend.Parser.terminal.Ident;

import java.util.ArrayList;

public class ParserOfUnaryExpFunc {
    private TokenListManager tokenListManager;
    private Ident ident;
    private Token lParent;
    private FuncRParams funcRParams;
    private Token rParent;
    private ArrayList<Error> errors;
    public ParserOfUnaryExpFunc(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }
    public UnaryExpFuncRParams parseUnaryExpFunc() {
        this.funcRParams = null;
        this.errors = new ArrayList<>();
        Token token = this.tokenListManager.getTokenAndMove();
        this.ident = new Ident(token);
        token = this.tokenListManager.getTokenAndMove();
        this.lParent = token;
        token = this.tokenListManager.getTokenAndMove();
        if(token.getTokenType().equals(TokenType.RPARENT)){
            this.rParent = token;
        } else if(token.getTokenType().equals(TokenType.SEMICN)){
            dealJError(token);
        }
        else {
            this.tokenListManager.lookBackToken(1);
            ParserOfFuncRParams parser = new ParserOfFuncRParams(tokenListManager);
            this.funcRParams = parser.parseFuncRParams();
            this.errors.addAll(parser.getErrors());
            token = this.tokenListManager.getTokenAndMove();
            if(token.getTokenType().equals(TokenType.RPARENT)){
                this.rParent = token;
            } else {
                dealJError(token);
            }
        }
        return new UnaryExpFuncRParams(this.ident,this.lParent,this.funcRParams,this.rParent);
    }

    public ArrayList<Error> getErrors() {
        return this.errors;
    }

    public void dealJError(Token token){
        if(!token.getTokenType().equals(TokenType.RPARENT)){
            this.rParent = new Token(TokenType.RPARENT,token.getLineNo(),")");
            this.tokenListManager.lookBackToken(2);
            Token next = tokenListManager.getTokenAndMove();
            Error error = new Error(next.getLineNo(), MyErrorType.j);
            this.errors.add(error);
        }
    }
}
