package parser_part.expression.unaryExpression;

import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.expression.primaryExpression.PrimaryExpParser;
import symbol_part.SymbolList;

/**
 * 一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
 **/
public class UnaryExpParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public UnaryExpParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public UnaryExp parseUnaryExp() {
        Token first = tokenList.getNextToken();
        Token second = tokenList.getNextToken();
        UnaryExpComponent unaryExpComponent = null;
        if (isFuncIdent(first) && second.getType() == Token.TokenType.LPARENT) {
            tokenList.moveBack(2);
            UnaryFunctionParser unaryFunctionParser = new UnaryFunctionParser(tokenList, symbolList);
            unaryExpComponent = unaryFunctionParser.parseUnaryFunction();
        } else if (first.getType() == Token.TokenType.LPARENT ||
                first.getType() == Token.TokenType.IDENFR ||
                first.getType() == Token.TokenType.INTCON ||
                first.getType() == Token.TokenType.FLOATCON ||
                first.getType() == Token.TokenType.CHRCON) {
            tokenList.moveBack(2);
            PrimaryExpParser primaryExpParser = new PrimaryExpParser(tokenList, symbolList);
            unaryExpComponent = primaryExpParser.parsePrimaryExp();
        } else if (first.getType() == Token.TokenType.PLUS ||
                first.getType() == Token.TokenType.MINU ||
                first.getType() == Token.TokenType.NOT) {

            /* UnaryExp -> UnaryOp UnaryExp */

            tokenList.moveBack(2);
            UnaryOpExpParser unaryOpExpParser = new UnaryOpExpParser(tokenList, symbolList);
            unaryExpComponent = unaryOpExpParser.parseUnaryOpExp();
        }
        return new UnaryExp(unaryExpComponent);
    }

    public boolean isFuncIdent(Token token) {
        return token.getType() == Token.TokenType.IDENFR ||
                token.getType() == Token.TokenType.MAINTK;
    }
}
