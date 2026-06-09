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

import java.util.RandomAccess;

public class StmtIfParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public StmtIfParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public StmtIf parseStmtIf() {
        boolean haveReturn = false;
        Token ifToken = tokenList.getNextToken();
        Token leftParent = tokenList.getNextToken();
        CondParser condParser = new CondParser(tokenList, symbolList);
        Cond cond = condParser.parseCond();
        Token rightParent = tokenList.getNextToken();
        //check j error
        if (rightParent.getType() != Token.TokenType.RPARENT) {
            tokenList.moveBack(2);
            ErrorList.addError(new Error(tokenList.getNextToken().getLineIndex(), Error.ErrorType.LACK_RIGHT_PARENT));
        }
        StmtParser stmtParser = new StmtParser(tokenList, symbolList);
        Stmt stmt = stmtParser.parseStmt();
        Token elseToken = tokenList.getNextToken();
        if (elseToken != null && elseToken.getType() == Token.TokenType.ELSETK) {
            Stmt elseStmt = stmtParser.parseStmt();
            return new StmtIf(ifToken, leftParent, cond, rightParent, stmt, elseToken, elseStmt);
        } else {
            tokenList.moveBack(1);
            return new StmtIf(ifToken, leftParent, cond, rightParent, stmt, null, null);
        }
    }
}
