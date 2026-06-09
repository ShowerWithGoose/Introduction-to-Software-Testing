package frontend.Parser.declaration.constant;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.MyErrorType;
import frontend.Parser.expression.ConstExp;
import frontend.Parser.expression.ParserOfConstExp;

import java.util.ArrayList;

public class ParserOfConstDef {
    private TokenListManager tokenListManager;
    private Token ident;
    private Token lBrack;  //'['
    private ConstExp constExp;
    private Token rBrack;  //']'
    private Token equalAssign; //'='
    private ConstInitVal constInitVal;
    private ArrayList<Error> errors;

    public ParserOfConstDef(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public ConstDef parserConstDef() {
        this.lBrack = null;
        this.constExp = null;
        this.rBrack = null;
        this.errors = new ArrayList<>();
        Token fir = tokenListManager.getTokenAndMove();
        if (fir.getTokenType().equals(TokenType.IDENFR)) {
            this.ident = fir;
        } else {
            System.out.println("expected indent here!");
        }
        Token sec = tokenListManager.getTokenAndMove();
        if (sec.getTokenType().equals(TokenType.LBRACK)) {
            this.lBrack = sec;
            ParserOfConstExp parserOfConstExp = new ParserOfConstExp(tokenListManager);
            this.constExp = parserOfConstExp.parseConstExp();
            this.errors.addAll(parserOfConstExp.getErrors());
            Token next = tokenListManager.getTokenAndMove();
            if (!next.getTokenType().equals(TokenType.RBRACK)) {
                tokenListManager.lookBackToken(2);
                Token beforeError = tokenListManager.getTokenAndMove();
                Error error = new Error(beforeError.getLineNo(), MyErrorType.k);
                this.errors.add(error);
                System.out.println("expected rbrack here!");
            } else {
                this.rBrack = next;
            }
            sec = tokenListManager.getTokenAndMove();
        }
        if(!sec.getTokenType().equals(TokenType.ASSIGN)){
            System.out.println("expected assign here!");
        }
        this.equalAssign = sec;
        ParserOfConstInitVal parserOfConstInitVal = new ParserOfConstInitVal(tokenListManager);
        this.constInitVal = parserOfConstInitVal.parserConstInitVal();
        this.errors.addAll(parserOfConstInitVal.getErrors());
        ConstDef constDef = new ConstDef(this.ident,this.equalAssign,
                this.constInitVal,this.constExp,this.lBrack,this.rBrack);
        return constDef;
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }
}
