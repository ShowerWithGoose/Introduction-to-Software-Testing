package parser_part.statement.StmtComponent;

import error_part.Error;
import error_part.ErrorList;
import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.expression.Exp;
import parser_part.expression.ExpParser;
import symbol_part.SymbolList;

public class StmtReturnParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public StmtReturnParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public StmtReturn parseStmtReturn() {
        Token returnToken = tokenList.getNextToken();
        if (returnToken.getType() != Token.TokenType.RETURNTK) {
            System.err.println("expect return in parseStmtReturn");
        }
        Token token = tokenList.getNextToken();
        if (token.getType() == Token.TokenType.LPARENT ||
                token.getType() == Token.TokenType.INTCON ||
                token.getType() == Token.TokenType.PLUS ||
                token.getType() == Token.TokenType.MINU ||
                token.getType() == Token.TokenType.CHRCON ||
                token.getType() == Token.TokenType.IDENFR) {
            tokenList.moveBack(1);
            ExpParser expParser = new ExpParser(tokenList, symbolList);
            Exp exp = expParser.parseExp();
            token = tokenList.getNextToken();
            // check i error
            if (token.getType() != Token.TokenType.SEMICN) {
                tokenList.moveBack(2);
                ErrorList.addError(new Error(tokenList.getNextToken().getLineIndex(),
                        Error.ErrorType.LACK_SEMICN));
            }
            return new StmtReturn(returnToken, exp, token);
        } else {
            if (token.getType() != Token.TokenType.SEMICN) {
                tokenList.moveBack(2);
                ErrorList.addError(new Error(tokenList.getNextToken().getLineIndex(),
                        Error.ErrorType.LACK_SEMICN));
            }
            return new StmtReturn(returnToken, null, token);
        }
    }
}
