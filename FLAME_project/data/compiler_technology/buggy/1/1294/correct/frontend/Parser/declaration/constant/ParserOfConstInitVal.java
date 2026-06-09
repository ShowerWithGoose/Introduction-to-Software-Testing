package frontend.Parser.declaration.constant;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.Parser.expression.ConstExp;
import frontend.Parser.expression.ParserOfConstExp;
import frontend.Parser.terminal.StringConst;

import java.util.ArrayList;

public class ParserOfConstInitVal {
    private TokenListManager tokenListManager;
    private ConstExp constExp; //ConstInitVal -> ConstExp

    private ConstExpArray constExpArray; //ConstInitVal ->'{' [ ConstExp { ',' ConstExp } ] '}'

    private StringConst stringConst; //ConstInitVal -> StringConst
    private ArrayList<Error> errors;
    public ParserOfConstInitVal(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public ConstInitVal parserConstInitVal() {
        this.constExp = null;
        this.constExpArray = null;
        this.stringConst = null;
        this.errors = new ArrayList<>();
        Token fir = tokenListManager.getTokenAndMove();
        if(fir.getTokenType().equals(TokenType.STRCON)){
            StringConst strConst = new StringConst(fir);
            this.stringConst = strConst;
        } else if(fir.getTokenType().equals(TokenType.LBRACE)){
            tokenListManager.lookBackToken(1);
            ParserOfConstExpArray parserOfConstExpArray = new ParserOfConstExpArray(tokenListManager);
            this.constExpArray = parserOfConstExpArray.parseConstExpArray();
            this.errors.addAll(parserOfConstExpArray.getErrors());
        } else {
            tokenListManager.lookBackToken(1);
            ParserOfConstExp parserOfConstExp = new ParserOfConstExp(tokenListManager);
            this.constExp = parserOfConstExp.parseConstExp();
            this.errors.addAll(parserOfConstExp.getErrors());
        }
        return new ConstInitVal(this.constExp, this.constExpArray, this.stringConst);
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }
}
