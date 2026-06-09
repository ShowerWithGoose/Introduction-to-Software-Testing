package frontend.Parser.expression.unaryexp;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.Parser.expression.primaryexp.ParserOfPrimaryExp;

import java.util.ArrayList;

public class ParserOfUnaryExp {
    private TokenListManager tokenListManager;
    private UnaryExpPort unaryExpPort;
    private ArrayList<Error> errors;
    public ParserOfUnaryExp(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public UnaryExp parseUnaryExp() {
        this.errors = new ArrayList<>();
        Token fir = tokenListManager.getTokenAndMove();
        Token sec = tokenListManager.getTokenAndMove();
        if(isUnaryExpSec(fir,sec)){
            tokenListManager.lookBackToken(2);
            ParserOfUnaryExpFunc parser = new ParserOfUnaryExpFunc(tokenListManager);
            this.unaryExpPort = parser.parseUnaryExpFunc();
            this.errors.addAll(parser.getErrors());
        } else if(isUnaryExpThi(fir)){
            tokenListManager.lookBackToken(2);
            ParserOfUnaryOpExp parser = new ParserOfUnaryOpExp(tokenListManager);
            this.unaryExpPort = parser.parseUnaryOpExp();
            this.errors.addAll(parser.getErrors());
        } else if(isUnaryExpFir(fir)){
            tokenListManager.lookBackToken(2);
            ParserOfPrimaryExp parser = new ParserOfPrimaryExp(tokenListManager);
            this.unaryExpPort = parser.parsePrimaryExp();
            this.errors.addAll(parser.getErrors());
        } else {
            System.out.println("Error in parser of unary expression");
        }
        return new UnaryExp(this.unaryExpPort);
    }

    //PrimaryExp
    private boolean isUnaryExpFir(Token fir){
        return fir.getTokenType().equals(TokenType.LPARENT) ||
                fir.getTokenType().equals(TokenType.IDENFR) ||
                fir.getTokenType().equals(TokenType.INTCON) ||
                fir.getTokenType().equals(TokenType.CHRCON);
    }

    //Ident '('  [FuncRParams] ')'
    private boolean isUnaryExpSec(Token fir,Token sec){
        return fir.getTokenType().equals(TokenType.IDENFR) &&
                sec.getTokenType().equals(TokenType.LPARENT);
    }

    //UnaryOp UnaryExp
    private boolean isUnaryExpThi(Token fir){
        return fir.getTokenType().equals(TokenType.PLUS) ||
                fir.getTokenType().equals(TokenType.MINU) ||
                fir.getTokenType().equals(TokenType.NOT);
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }
}
