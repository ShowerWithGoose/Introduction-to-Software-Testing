package parser_part.expression.primaryExpression;

import error_part.Debug;
import error_part.Error;
import error_part.ErrorList;
import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.Ident;
import parser_part.IdentParser;
import parser_part.expression.Exp;
import parser_part.expression.ExpParser;
import symbol_part.Symbol;
import symbol_part.SymbolList;

import java.util.ArrayList;

public class LValParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public LValParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public LVal parseLVal() {
        IdentParser identParser = new IdentParser(tokenList);
        Ident ident = identParser.parseIdent();
        ArrayList<Token> leftBrackets = new ArrayList<>();
        ArrayList<Exp> exps = new ArrayList<>();
        ArrayList<Token> rightBrackets = new ArrayList<>();
        Token token = tokenList.getNextToken();
        while (token != null && token.getType() == Token.TokenType.LBRACK) {
            leftBrackets.add(token);
            ExpParser expParser = new ExpParser(tokenList, symbolList);
            exps.add(expParser.parseExp());
            Token token1 = tokenList.getNextToken();
            rightBrackets.add(token1);
            if (token1.getType() != Token.TokenType.RBRACK && Debug.status) {
                tokenList.moveBack(2);
                ErrorList.addError(new Error(tokenList.getNextToken().getLineIndex(), Error.ErrorType.LACK_RIGHT_BRACK));
            }
            token = tokenList.getNextToken();
        }
        tokenList.moveBack(1);
        LVal lVal = new LVal(ident, leftBrackets, exps, rightBrackets);
        if (symbolList.hasUndefinedIdent(ident.getName())) {
            lVal.setUndefined(true);
            ErrorList.addError(new Error(ident.getLineIndex(), Error.ErrorType.UNDECLARED_NAME));
        } else {
            lVal.setSymbolType(symbolList.getSymbol(ident.getName()).getSymbolType());
        }
        return lVal;
    }
}
