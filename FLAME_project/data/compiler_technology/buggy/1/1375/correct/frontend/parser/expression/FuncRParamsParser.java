package frontend.parser.expression;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class FuncRParamsParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* FuncRParams Attributes */
    public Exp first = null;
    public ArrayList<Token> commas = new ArrayList<>();
    public ArrayList<Exp> exps = new ArrayList<>();

    public FuncRParamsParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public FuncRParams parseFuncRParams() {
        this.commas = new ArrayList<>();
        this.exps = new ArrayList<>();
        ExpParser expParser = new ExpParser(this.iterator,this.error_tokens);
        first = expParser.parseExp();
        Token token = this.iterator.readNextToken();
        while (token.type.equals(TokenType.COMMA)) { // ','
            this.commas.add(token);
            ExpParser expParser1 = new ExpParser(this.iterator,this.error_tokens);
            this.exps.add(expParser1.parseExp());
            token = this.iterator.readNextToken();
        }
        this.iterator.unReadToken(1);
        FuncRParams funcRParams = new FuncRParams(this.first, this.commas, this.exps);
        return funcRParams;
    }
}
