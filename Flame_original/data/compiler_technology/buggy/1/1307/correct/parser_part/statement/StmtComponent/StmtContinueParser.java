package parser_part.statement.StmtComponent;

import error_part.Error;
import error_part.ErrorList;
import lexer_part.Token;
import lexer_part.TokenList;
import symbol_part.SymbolList;

public class StmtContinueParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public StmtContinueParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public StmtContinue parseStmtContinue() {
        Token token = tokenList.getNextToken();
        if (token.getType() != Token.TokenType.CONTINUETK) {
            System.err.println("expect break in parseStmtBreak");
        }
        // check m error
        if (symbolList.getCycleDepth() < 1) {
            ErrorList.addError(new Error(token.getLineIndex(), Error.ErrorType.WRONG_BREAK_CONTINUE));
        }
        Token semicn = tokenList.getNextToken();
        if (semicn.getType() != Token.TokenType.SEMICN) {
            tokenList.moveBack(2);
            //System.err.println("expect semicn in parseStmtAssign");
            ErrorList.addError(new Error(tokenList.getNextToken().getLineIndex(), Error.ErrorType.LACK_SEMICN));
        }
        return new StmtContinue(token, semicn);
    }
}
