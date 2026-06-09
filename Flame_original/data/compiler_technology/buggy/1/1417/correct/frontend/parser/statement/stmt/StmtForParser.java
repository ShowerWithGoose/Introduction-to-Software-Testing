package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.expression.Cond;
import frontend.parser.expression.CondParser;

import java.util.ArrayList;

public class StmtForParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public StmtForParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public StmtFor parseStmtFor() {
        Token forTk = tokenList.getNextToken();
        this.nodes.add(forTk);
        Token lParent = tokenList.getNextToken();
        this.nodes.add(lParent);
        Token token = tokenList.getNextToken();
        // forStmt1不存在
        if (token.getType() == TokenType.SEMICN) {
            Token semicn1 = token;
            this.nodes.add(semicn1);
        } else {
            tokenList.fallbackToken(1);
            ForStmtParser forStmtParser = new ForStmtParser(tokenList);
            ForStmt forStmt1 = forStmtParser.parseForStmt();
            this.nodes.add(forStmt1);
            Token semicn1 = tokenList.getNextToken();
            this.nodes.add(semicn1);
        }
        token = tokenList.getNextToken();
        // cond不存在
        if (token.getType() == TokenType.SEMICN) {
            Token semicn2 = token;
            this.nodes.add(semicn2);
        } else {
            tokenList.fallbackToken(1);
            CondParser condParser = new CondParser(tokenList);
            Cond cond = condParser.parseCond();
            this.nodes.add(cond);
            Token semicn2 = tokenList.getNextToken();
            this.nodes.add(semicn2);
        }
        token = tokenList.getNextToken();
        // forStmt2不存在
        if (token.getType() == TokenType.RPARENT) {
            Token rParent = token;
            this.nodes.add(rParent);
        } else {
            tokenList.fallbackToken(1);
            ForStmtParser forStmtParser = new ForStmtParser(tokenList);
            ForStmt forStmt2 = forStmtParser.parseForStmt();
            this.nodes.add(forStmt2);
            Token rParent = tokenList.getNextToken();
            this.nodes.add(rParent);
        }
        StmtParser stmtParser = new StmtParser(tokenList);
        Stmt stmt = stmtParser.parseStmt();
        this.nodes.add(stmt);
        int startLine = this.nodes.get(0).getStarttLine();
        int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
        StmtFor stmtFor = new StmtFor(startLine, endLine, "", this.nodes);
        return stmtFor;
    }
}
