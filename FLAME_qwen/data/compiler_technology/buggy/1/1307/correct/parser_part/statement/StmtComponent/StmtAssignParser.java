package parser_part.statement.StmtComponent;

import error_part.Debug;
import error_part.Error;
import error_part.ErrorList;
import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.expression.Exp;
import parser_part.expression.ExpParser;
import parser_part.expression.primaryExpression.LVal;
import parser_part.expression.primaryExpression.LValParser;
import symbol_part.Symbol;
import symbol_part.SymbolList;

import static error_part.Error.ErrorType.LACK_SEMICN;

public class StmtAssignParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public StmtAssignParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public StmtAssign parseStmtAssign() {
        LValParser lValParser = new LValParser(tokenList, symbolList);
        LVal lVal = lValParser.parseLVal();
        // check h error
        if (lVal.isConstVar()) {
            ErrorList.addError(new Error(lVal.getLineIndex(), Error.ErrorType.MODIFY_CONST));
        }
        Token assign = tokenList.getNextToken();
        ExpParser expParser = new ExpParser(tokenList, symbolList);
        Exp exp = expParser.parseExp();
        Token semicn = tokenList.getNextToken();
        if (semicn.getType() != Token.TokenType.SEMICN) {
            //System.err.println("expect semicn in parseStmtAssign");
            tokenList.moveBack(2);
            ErrorList.addError(new Error(tokenList.getNextToken().getLineIndex(), LACK_SEMICN));
        }
        return new StmtAssign(lVal, assign, exp, semicn);
    }
}
