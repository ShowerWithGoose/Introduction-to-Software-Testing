package frontend.Parser.function;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;

import java.util.ArrayList;

public class ParserOfFuncFParams {
    private TokenListManager tokenListManager;
    private FuncFParam firstParam;
    private ArrayList<Token> commas;
    private ArrayList<FuncFParam> funcParams;
    private ArrayList<Error> errors;
    public ParserOfFuncFParams(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }
    public FuncFParams parseFuncFParams() {
        this.commas = new ArrayList<>();
        this.funcParams = new ArrayList<>();
        this.errors = new ArrayList<>();
        ParserOfFuncFParam parserOfFuncFParam = new ParserOfFuncFParam(tokenListManager);
        this.firstParam = parserOfFuncFParam.parseFuncFParam();
        this.errors.addAll(parserOfFuncFParam.getErrors());
        Token next = tokenListManager.getTokenAndMove();
        while(next.getTokenType().equals(TokenType.COMMA)){
            this.commas.add(next);
            FuncFParam funcFParam = parserOfFuncFParam.parseFuncFParam();
            this.funcParams.add(funcFParam);
            this.errors.addAll(parserOfFuncFParam.getErrors());
            next = tokenListManager.getTokenAndMove();
        }
        this.tokenListManager.lookBackToken(1);
        return new FuncFParams(this.firstParam, this.commas, this.funcParams);
    }
    public ArrayList<Error> getErrors() {
        return errors;
    }
}
