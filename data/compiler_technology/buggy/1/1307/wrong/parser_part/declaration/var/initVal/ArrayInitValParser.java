package parser_part.declaration.var.initVal;

import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.expression.Exp;
import parser_part.expression.ExpParser;
import symbol_part.SymbolList;

import java.util.ArrayList;

public class ArrayInitValParser {
    private final TokenList tokenList;
    private SymbolList symbolList;

    public ArrayInitValParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public ArrayInitVal parseArrayInitVal() {
        Token leftBrace = tokenList.getNextToken();
        Token rightBrace;
        if (leftBrace.getType() != Token.TokenType.LBRACE) {
            System.err.println("expect left Brace in parseInitVal");
        }
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<Exp> initVals = new ArrayList<>();
        Token token = tokenList.getNextToken();
        Exp first = null;
        if (token.getType() == Token.TokenType.RBRACE) {
            rightBrace = token;
        } else {
            tokenList.moveBack(1);
            ExpParser expParser = new ExpParser(tokenList,symbolList);
            first = expParser.parseExp();
            Token token1 = tokenList.getNextToken();
            while (token1.getType() == Token.TokenType.COMMA) {
                commas.add(token1);
                initVals.add(expParser.parseExp());
                token1 = tokenList.getNextToken();
            }
            rightBrace = token1;
        }
        if (rightBrace.getType() != Token.TokenType.RBRACE) {
            System.err.println("expect right brace in parseArrayConstInitVal");
        }
        return new ArrayInitVal(leftBrace, first, commas, initVals, rightBrace);
    }
}
