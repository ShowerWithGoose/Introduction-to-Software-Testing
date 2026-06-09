package frontend.Parser.declaration.variable;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.Parser.expression.Exp;
import frontend.Parser.expression.ParserOfExp;
import frontend.Parser.terminal.StringConst;

import java.util.ArrayList;

public class ParserOfInitVal {
    private TokenListManager tokenListManager;
    private Exp exp;
    private ExpArray expArray;
    private StringConst stringConst;
    private ArrayList<Error> errors;
    public ParserOfInitVal(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }
    public InitVal parseInitVal() {
        this.exp = null;
        this.expArray = null;
        this.stringConst = null;
        this.errors = new ArrayList<>();
        Token fir = tokenListManager.getTokenAndMove();
        if(fir.getTokenType().equals(TokenType.STRCON)){
            StringConst stringConst = new StringConst(fir);
            this.stringConst = stringConst;
        } else if(fir.getTokenType().equals(TokenType.LBRACE)){
            tokenListManager.lookBackToken(1);
            ParserOfExpArray parserOfExpArray = new ParserOfExpArray(tokenListManager);
            this.expArray = parserOfExpArray.parseExpArray();
            this.errors.addAll(parserOfExpArray.getErrors());
        } else{
            tokenListManager.lookBackToken(1);
            ParserOfExp parserOfExp = new ParserOfExp(tokenListManager);
            this.exp = parserOfExp.parseExp();
            this.errors.addAll(parserOfExp.getErrors());
        }
        return new InitVal(this.exp, this.expArray, this.stringConst);
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }
}
