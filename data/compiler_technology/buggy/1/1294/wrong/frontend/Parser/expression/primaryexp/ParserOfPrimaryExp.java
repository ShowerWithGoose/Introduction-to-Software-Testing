package frontend.Parser.expression.primaryexp;

import frontend.Error;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.Token;
import frontend.Lexer.TokenType;
import frontend.Parser.expression.LVal;
import frontend.Parser.expression.ParserOfLVal;

import java.util.ArrayList;

public class ParserOfPrimaryExp {
    private TokenListManager tokenListManager;
    private PrimaryExpPort primaryExpPort;
    private ArrayList<Error> errors;

    public ParserOfPrimaryExp(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }
    public PrimaryExp parsePrimaryExp() {
        this.errors = new ArrayList<>();
        Token fir = this.tokenListManager.getTokenAndMove();
        if(fir.getTokenType().equals(TokenType.LPARENT)){
            this.tokenListManager.lookBackToken(1);
            ParserOfPrimaryParentExp parser = new ParserOfPrimaryParentExp(tokenListManager);
            PrimaryParentExp primaryParentExp = parser.parsePrimaryParentExp();
            this.primaryExpPort = primaryParentExp;
            this.errors.addAll(parser.getErrors());
        } else if(fir.getTokenType().equals(TokenType.IDENFR)){
            this.tokenListManager.lookBackToken(1);
            ParserOfLVal parserOfLVal = new ParserOfLVal(tokenListManager);
            LVal lVal = parserOfLVal.parseLVal();
            this.primaryExpPort = lVal;
            this.errors.addAll(parserOfLVal.getErrors());
        } else if(fir.getTokenType().equals(TokenType.INTCON)){
            this.tokenListManager.lookBackToken(1);
            ParserOfNumber parser = new ParserOfNumber(tokenListManager);
            Number number = parser.parseNumber();
            this.primaryExpPort = number;
        } else if(fir.getTokenType().equals(TokenType.CHRCON)){
            this.tokenListManager.lookBackToken(1);
            ParserOfCharacter parser = new ParserOfCharacter(tokenListManager);
            Character character = parser.parseCharacter();
            this.primaryExpPort = character;
        } else {
            System.out.println("illegal first token in PrimaryExp");
        }
        return new PrimaryExp(this.primaryExpPort);
    }
    public ArrayList<Error> getErrors() {
        return this.errors;
    }
}
