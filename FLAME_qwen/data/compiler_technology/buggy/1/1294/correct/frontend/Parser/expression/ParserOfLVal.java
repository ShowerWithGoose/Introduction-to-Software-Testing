package frontend.Parser.expression;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.MyErrorType;
import frontend.Parser.terminal.Ident;

import java.util.ArrayList;

public class ParserOfLVal {
    private TokenListManager tokenListManager;
    private Ident ident;
    private Token lBrack;
    private Exp exp;
    private Token rBrack;
    private ArrayList<Error> errors;
    public ParserOfLVal(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }
    public LVal parseLVal(){
        this.lBrack = null;
        this.exp = null;
        this.rBrack = null;
        this.errors = new ArrayList<>();
        Token token = tokenListManager.getTokenAndMove();
        if(token.getTokenType().equals(TokenType.IDENFR)){
            this.ident = new Ident(token);
        } else{
            System.out.println("expected Ident here in parseLVal");
        }
        token = tokenListManager.getTokenAndMove();
        if(token.getTokenType().equals(TokenType.LBRACK)){
            this.lBrack = token;
            ParserOfExp parserOfExp = new ParserOfExp(tokenListManager);
            this.exp = parserOfExp.parseExp();
            this.errors.addAll(parserOfExp.getErrors());
            token = tokenListManager.getTokenAndMove();
            if(token.getTokenType().equals(TokenType.RBRACK)){
                this.rBrack = token;
            } else {
                tokenListManager.lookBackToken(2);
                token = tokenListManager.getTokenAndMove();
                Error error = new Error(token.getLineNo(), MyErrorType.k);
                this.errors.add(error);
                System.out.println("expected RBrack here in parseLVal");
            }
        } else{
            tokenListManager.lookBackToken(1);
        }
        return new LVal(this.ident,this.lBrack,this.exp,this.rBrack);
    }

    public ArrayList<Error> getErrors() {
        return this.errors;
    }
}
