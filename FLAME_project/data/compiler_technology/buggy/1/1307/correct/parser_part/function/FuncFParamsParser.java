package parser_part.function;

import lexer_part.Token;
import lexer_part.TokenList;
import symbol_part.Symbol;
import symbol_part.SymbolList;

import java.util.ArrayList;

public class FuncFParamsParser {
    private TokenList tokenList;
    private SymbolList symbolList;
    private ArrayList<Symbol> paramSymbols;

    public FuncFParamsParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
        paramSymbols = new ArrayList<>();
    }

    public FuncFParams parseFuncFParams() {
        FuncFParamParser funcFParamParser = new FuncFParamParser(tokenList, symbolList);
        FuncFParam funcFParam = funcFParamParser.parseFuncFParam();
        paramSymbols.add(funcFParamParser.getSymbol());
        Token token = tokenList.getNextToken();
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<FuncFParam> funcFParams = new ArrayList<>();
        while (token != null && token.getType() == Token.TokenType.COMMA) {
            FuncFParamParser funcFParamParser1 = new FuncFParamParser(tokenList, symbolList);
            commas.add(token);
            funcFParams.add(funcFParamParser1.parseFuncFParam());
            paramSymbols.add(funcFParamParser1.getSymbol());
            token = tokenList.getNextToken();
        }
        tokenList.moveBack(1);
        return new FuncFParams(funcFParam, commas, funcFParams);
    }

    public ArrayList<Symbol> getParamSymbols() {
        return paramSymbols;
    }
}
