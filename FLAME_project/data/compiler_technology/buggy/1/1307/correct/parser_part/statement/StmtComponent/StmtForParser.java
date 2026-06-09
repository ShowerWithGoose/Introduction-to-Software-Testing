package parser_part.statement.StmtComponent;

import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.block.Block;
import parser_part.expression.Cond;
import parser_part.expression.CondParser;
import parser_part.statement.Stmt;
import parser_part.statement.StmtParser;
import symbol_part.SymbolList;

public class StmtForParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public StmtForParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public StmtFor parseStmtFor() {
        Token forToken = tokenList.getNextToken();
        Token leftParent = tokenList.getNextToken();
        Token token = tokenList.getNextToken();
        ForStmt forStmt1 = null;
        Token semicn1;
        Cond cond = null;
        Token semicn2;
        ForStmt forStmt2 = null;
        Token rightParent;
        Stmt stmt;
        ForStmtParser forStmtParser = new ForStmtParser(tokenList, symbolList);
        if (token.getType() == Token.TokenType.SEMICN) {
            semicn1 = token;
        } else {
            tokenList.moveBack(1);
            forStmt1 = forStmtParser.parseForStmt();
            semicn1 = tokenList.getNextToken();
        }
        token = tokenList.getNextToken();
        if (token.getType() == Token.TokenType.SEMICN) {
            semicn2 = token;
        } else {
            tokenList.moveBack(1);
            CondParser condParser = new CondParser(tokenList, symbolList);
            cond = condParser.parseCond();
            semicn2 = tokenList.getNextToken();
        }
        token = tokenList.getNextToken();
        if (token.getType() == Token.TokenType.RPARENT) {
            rightParent = token;
        } else {
            tokenList.moveBack(1);
            forStmt2 = forStmtParser.parseForStmt();
            rightParent = tokenList.getNextToken();
        }
        SymbolList symbolList1 = new SymbolList(symbolList);
        symbolList1.setCycleDepth(symbolList.getCycleDepth() + 1);
        StmtParser stmtParser = new StmtParser(tokenList, symbolList1);
        stmtParser.setNewSymbolList(true);
        stmt = stmtParser.parseStmt();
        if (!(stmt.getStmtComponent() instanceof Block)) {
            SymbolList.fieldCounter--;
        }
        return new StmtFor(forToken, leftParent, forStmt1, semicn1, cond,
                semicn2, forStmt2, rightParent, stmt);
    }
}
