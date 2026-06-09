package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Node;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;
import frontend.parser.expression.primaryexp.LVal;
import frontend.parser.expression.primaryexp.LValParser;

import java.util.ArrayList;

public class ForStmtParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public ForStmtParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public ForStmt parseForStmt() {
        LValParser lValParser = new LValParser(tokenList);
        LVal lVal = lValParser.parseLVal();
        this.nodes.add(lVal);
        Token token = tokenList.getNextToken();
        this.nodes.add(token);
        ExpParser expParser = new ExpParser(tokenList);
        Exp exp = expParser.parseExp();
        this.nodes.add(exp);
        int startLine = this.nodes.get(0).getStarttLine();
        int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
        ForStmt forStmt = new ForStmt(startLine, endLine, "<ForStmt>", this.nodes);
        return forStmt;
    }
}
