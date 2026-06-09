package frontend.Parser.declaration.variable;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.MyErrorType;
import frontend.Parser.expression.ConstExp;
import frontend.Parser.expression.ParserOfConstExp;

import java.util.ArrayList;

public class ParserOfVarDef {
    private TokenListManager tokenListManager;
    private Token ident;
    private Token lBrack;
    private ConstExp constExp;
    private Token rBrack;
    private Token equalAssign; //'='
    private InitVal initVal;
    private ArrayList<Error> errors;

    public ParserOfVarDef(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public VarDef parseVarDef() {
        this.lBrack = null;
        this.constExp = null;
        this.rBrack = null;
        this.equalAssign = null;
        this.initVal = null;
        this.errors = new ArrayList<>();
        Token fir = tokenListManager.getTokenAndMove();
        if (fir.getTokenType().equals(TokenType.IDENFR)) {
            this.ident = fir;
        } else {
            System.out.println("VarDef 's first is not ident");
        }
        Token sec = tokenListManager.getTokenAndMove();
        if (sec.getTokenType().equals(TokenType.LBRACK)) {
            this.lBrack = sec;
            ParserOfConstExp parserOfConstExp = new ParserOfConstExp(tokenListManager);
            ConstExp constExp = parserOfConstExp.parseConstExp();
            this.constExp = constExp;
            this.errors.addAll(parserOfConstExp.getErrors());
            Token next = tokenListManager.getTokenAndMove();
            if (next.getTokenType().equals(TokenType.RBRACK)) {
                this.rBrack = next;
            } else {
                tokenListManager.lookBackToken(2);
                Token beforeError = tokenListManager.getTokenAndMove();
                Error error = new Error(beforeError.getLineNo(), MyErrorType.k);
                this.errors.add(error);
                System.out.println("expected RBRACK not here");
            }
            sec = tokenListManager.getTokenAndMove();
        }
        if (sec.getTokenType().equals(TokenType.ASSIGN)) {
            this.equalAssign = sec;
            ParserOfInitVal parserOfInitVal = new ParserOfInitVal(tokenListManager);
            InitVal initVal = parserOfInitVal.parseInitVal();
            this.initVal = initVal;
            this.errors.addAll(parserOfInitVal.getErrors());
        } else {
            tokenListManager.lookBackToken(1);
        }
        VarDef varDef = new VarDef(this.ident, this.lBrack,
                this.constExp, this.rBrack, this.equalAssign, this.initVal);
        return varDef;
    }

    public ArrayList<Error> getErrors() {
        return this.errors;
    }
}
