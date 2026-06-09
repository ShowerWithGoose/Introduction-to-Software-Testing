package frontend.Parser.declaration.constant;

import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.Parser.expression.ConstExp;
import frontend.Parser.expression.ParserOfConstExp;
import frontend.Error;

import java.util.ArrayList;

public class ParserOfConstExpArray {
    private TokenListManager tokenListManager;
    private Token lBrace;
    private ConstExp firstConstExp;
    private ArrayList<Token> commas;
    private ArrayList<ConstExp> constExps;
    private Token rBrace;
    private ArrayList<Error> errors;

    public ParserOfConstExpArray(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public ConstExpArray parseConstExpArray() {
        this.firstConstExp = null;
        this.commas = new ArrayList<>();
        this.constExps = new ArrayList<>();
        this.errors = new ArrayList<>();
        Token fir = tokenListManager.getTokenAndMove();
        if (fir.getTokenType().equals(TokenType.LBRACE)) {
            this.lBrace = fir;
        }
        Token sec = tokenListManager.getTokenAndMove();
        if (sec.getTokenType().equals(TokenType.RBRACE)) {
            this.rBrace = sec;
        } else {
            tokenListManager.lookBackToken(1);
            ParserOfConstExp parserOfConstExp = new ParserOfConstExp(tokenListManager);
            this.firstConstExp = parserOfConstExp.parseConstExp();
            this.errors.addAll(parserOfConstExp.getErrors());
            Token next = tokenListManager.getTokenAndMove();
            while (next.getTokenType().equals(TokenType.COMMA)) {
                this.commas.add(next);
                ConstExp constExp = parserOfConstExp.parseConstExp();
                this.constExps.add(constExp);
                this.errors.addAll(parserOfConstExp.getErrors());
                next = tokenListManager.getTokenAndMove();
            }
            if (next.getTokenType().equals(TokenType.RBRACE)) {
                this.rBrace = next;
            }
        }
        ConstExpArray constExpArray = new ConstExpArray(this.lBrace, this.firstConstExp,
                this.rBrace, this.commas, this.constExps);
        return constExpArray;
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }
}
