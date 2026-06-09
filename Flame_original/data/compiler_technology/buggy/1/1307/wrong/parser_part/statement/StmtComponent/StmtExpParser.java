package parser_part.statement.StmtComponent;

import error_part.Error;
import error_part.ErrorList;
import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.expression.Exp;
import parser_part.expression.ExpParser;
import symbol_part.SymbolList;

public class StmtExpParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public StmtExpParser(TokenList tokenList,SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public StmtExp parseStmtExp() {
        ExpParser expParser = new ExpParser(tokenList,symbolList);
        Exp exp = expParser.parseExp();
        Token semicn = tokenList.getNextToken();
        if (semicn.getType() != Token.TokenType.SEMICN) {
            //System.err.println("expect semicn in parseStmtExp");
            tokenList.moveBack(2);
            ErrorList.addError(new Error(tokenList.getNextToken().getLineIndex(), Error.ErrorType.LACK_SEMICN));
        }
        return new StmtExp(exp, semicn);
    }
}
