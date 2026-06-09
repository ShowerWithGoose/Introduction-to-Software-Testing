package frontend.Parser.function;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.MyErrorType;
import frontend.Parser.declaration.BType;
import frontend.Parser.terminal.Ident;

import java.util.ArrayList;

public class ParserOfFuncFParam {
    private TokenListManager tokenListManager;
    private BType bType; //int or char
    private Ident ident; //变量名
    private Token lBrack; // '['
    private Token rBrack; // ']'
    private ArrayList<Error> errors;

    public ParserOfFuncFParam(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public FuncFParam parseFuncFParam() {
        this.lBrack = null;
        this.rBrack = null;
        this.errors = new ArrayList<>();
        Token token = tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.INTTK)
                || token.getTokenType().equals(TokenType.CHARTK)) {
            this.bType = new BType(token);
        } else {
            System.out.println("not int or char here in parseFuncFParam");
        }
        token = tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.IDENFR)) {
            this.ident = new Ident(token);
        } else {
            System.out.println("not ident here in parseFuncFParam");
        }
        token = tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.LBRACK)) {
            this.lBrack = token;
            token = tokenListManager.getTokenAndMove();
            if (token.getTokenType().equals(TokenType.RBRACK)) {
                this.rBrack = token;
            } else {
                tokenListManager.lookBackToken(2);
                token = tokenListManager.getTokenAndMove();
                Error error = new Error(token.getLineNo(), MyErrorType.k);
                this.errors.add(error);
                System.out.println("not rBrack here in parseFuncFParam");
            }
        } else {
            tokenListManager.lookBackToken(1);
        }
        return new FuncFParam(this.bType, this.ident, this.lBrack, this.rBrack);
    }
    public ArrayList<Error> getErrors() {
        return this.errors;
    }
}
