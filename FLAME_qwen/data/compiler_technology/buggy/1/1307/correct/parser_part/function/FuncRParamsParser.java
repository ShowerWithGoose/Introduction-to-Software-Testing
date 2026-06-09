package parser_part.function;

import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.expression.Exp;
import parser_part.expression.ExpParser;
import symbol_part.SymbolList;

import java.util.ArrayList;

public class FuncRParamsParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public FuncRParamsParser(TokenList tokenList,SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public FuncRParams parseFuncRParams() {
        ExpParser expParser = new ExpParser(tokenList,symbolList);
        Exp exp = expParser.parseExp();
        Token token = tokenList.getNextToken();
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<Exp> exps = new ArrayList<>();
        while (token != null && token.getType() == Token.TokenType.COMMA) {
            commas.add(token);
            exps.add(expParser.parseExp());
            token = tokenList.getNextToken();
        }
        tokenList.moveBack(1);
        return new FuncRParams(exp, commas, exps);
    }
}
