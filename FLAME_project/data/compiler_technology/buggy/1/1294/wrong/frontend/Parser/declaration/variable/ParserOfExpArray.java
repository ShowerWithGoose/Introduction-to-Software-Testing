package frontend.Parser.declaration.variable;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.Parser.expression.Exp;
import frontend.Parser.expression.ParserOfExp;

import java.util.ArrayList;

public class ParserOfExpArray {
    private TokenListManager tokenListManager;
    private Token lBrace;
    private Exp firstExp;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;
    private Token rBrace;
    private ArrayList<Error> errors;

    public ParserOfExpArray(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public ExpArray parseExpArray() {
        this.firstExp = null;
        this.commas = new ArrayList<>();
        this.exps = new ArrayList<>();
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
            ParserOfExp parserOfExp = new ParserOfExp(tokenListManager);
            this.firstExp = parserOfExp.parseExp();
            this.errors.addAll(parserOfExp.getErrors());
            Token next = tokenListManager.getTokenAndMove();
            while (next.getTokenType().equals(TokenType.COMMA)) {
                this.commas.add(next);
                Exp exp = parserOfExp.parseExp();
                this.exps.add(exp);
                this.errors.addAll(parserOfExp.getErrors());
                next = tokenListManager.getTokenAndMove();
            }
            if (next.getTokenType().equals(TokenType.RBRACE)) {
                this.rBrace = next;
            }
        }
        ExpArray expArray = new ExpArray(this.lBrace, this.firstExp,
                this.commas, this.exps, this.rBrace);
        return expArray;
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }
}
