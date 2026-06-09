package parser_part.declaration.constance;

import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.expression.ConstExp;
import parser_part.expression.ConstExpParser;
import symbol_part.SymbolList;

import java.util.ArrayList;

public class ArrayConstInitValParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public ArrayConstInitValParser(TokenList tokenList,SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public ArrayConstInitVal parseArrayConstInitVal() {
        Token leftBrace = tokenList.getNextToken();
        Token rightBrace;
        ConstExp first = null;
        if (leftBrace.getType() != Token.TokenType.LBRACE) {
            System.err.println("expect left brace in parseArrayConstInitVal");
        }
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<ConstExp> constInitVals = new ArrayList<>();
        Token token = tokenList.getNextToken();
        if (token.getType() == Token.TokenType.RBRACE) {
            rightBrace = token;
        } else {
            tokenList.moveBack(1);
            ConstExpParser constExpParser = new ConstExpParser(tokenList,symbolList);
            first = constExpParser.parseConstExp();
            Token token1 = tokenList.getNextToken();
            while (token1.getType() == Token.TokenType.COMMA) {
                commas.add(token1);
                constInitVals.add(constExpParser.parseConstExp());
                token1 = tokenList.getNextToken();
            }
            rightBrace = token1;
        }
        if (rightBrace.getType() != Token.TokenType.RBRACE) {
            System.err.println("expect right brace in parseArrayConstInitVal");
        }
        return new ArrayConstInitVal(leftBrace, first, commas, constInitVals, rightBrace);
    }
}
