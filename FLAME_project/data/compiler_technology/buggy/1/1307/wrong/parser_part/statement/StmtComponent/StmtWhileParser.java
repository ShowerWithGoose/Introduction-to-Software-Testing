package parser_part.statement.StmtComponent;

import error_part.Error;
import error_part.ErrorList;
import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.expression.Cond;
import parser_part.expression.CondParser;
import parser_part.statement.Stmt;
import parser_part.statement.StmtParser;
import symbol_part.SymbolList;

public class StmtWhileParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public StmtWhileParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public StmtWhile parseStmtWhile() {
        Token whileToken = tokenList.getNextToken();
        Token leftParent = tokenList.getNextToken();
        CondParser condParser = new CondParser(tokenList, symbolList);
        Cond cond = condParser.parseCond();
        Token rightParent = tokenList.getNextToken();
        //check j
        if (rightParent.getType() != Token.TokenType.RPARENT) {
            tokenList.moveBack(2);
            ErrorList.addError(new Error(tokenList.getNextToken().getLineIndex(),
                    Error.ErrorType.LACK_RIGHT_PARENT));
        }
        SymbolList symbolList1 = new SymbolList(symbolList);
        symbolList1.setCycleDepth(symbolList.getCycleDepth() + 1);
        StmtParser stmtParser = new StmtParser(tokenList, symbolList1);
        Stmt stmt = stmtParser.parseStmt();
        return new StmtWhile(whileToken, leftParent, cond, rightParent, stmt);
    }
}
