package parser_part.statement.StmtComponent;

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

public class ForStmtParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public ForStmtParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public ForStmt parseForStmt() {
        LValParser lValParser = new LValParser(tokenList, symbolList);
        LVal lVal = lValParser.parseLVal();
        if (lVal.getSymbolType() != null && lVal.getSymbolType().isConst()) {
            ErrorList.addError(new Error(lVal.getLineIndex(), Error.ErrorType.MODIFY_CONST));
        }
        Token assign = tokenList.getNextToken();
        if (assign.getType() != Token.TokenType.ASSIGN) {
            System.err.println("expect assign in parseForStmt");
        }
        ExpParser expParser = new ExpParser(tokenList, symbolList);
        Exp exp = expParser.parseExp();
        return new ForStmt(lVal, assign, exp);
    }
}
