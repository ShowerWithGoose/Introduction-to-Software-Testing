package frontend.Parser.expression;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;

import java.util.ArrayList;

public class ParserOfFuncRParams {
    private TokenListManager tokenListManager;
    private Exp firstExp;
    private ArrayList<Token> commas;
    private ArrayList<Exp> expList;
    private ArrayList<Error> errors;
    public ParserOfFuncRParams(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }
    public FuncRParams parseFuncRParams() {
        this.commas = new ArrayList<>();
        this.expList = new ArrayList<>();
        this.errors = new ArrayList<>();
        ParserOfExp parserOfExp = new ParserOfExp(tokenListManager);
        this.firstExp = parserOfExp.parseExp();
        this.errors.addAll(parserOfExp.getErrors());
        Token next = tokenListManager.getTokenAndMove();
        while(next.getTokenType().equals(TokenType.COMMA)){
            this.commas.add(next);
            Exp exp = parserOfExp.parseExp();
            this.expList.add(exp);
            this.errors.addAll(parserOfExp.getErrors());
            next = tokenListManager.getTokenAndMove();
        }
        this.tokenListManager.lookBackToken(1);
        return new FuncRParams(this.firstExp, this.commas, this.expList);
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }
}
