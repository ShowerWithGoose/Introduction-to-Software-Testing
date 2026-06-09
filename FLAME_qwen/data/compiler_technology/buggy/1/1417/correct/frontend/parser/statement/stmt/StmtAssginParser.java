package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.error.TokenError;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.error.Error;
import frontend.parser.Node;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;
import frontend.parser.expression.primaryexp.LVal;
import frontend.parser.expression.primaryexp.LValParser;

import java.util.ArrayList;

// Stmt -> LVal '=' Exp ';'
public class StmtAssginParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public StmtAssginParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public StmtAssign parseStmtAssgin() {
        LValParser lValParser = new LValParser(tokenList);
        LVal lVal = lValParser.parseLVal();
        this.nodes.add(lVal);
        Token assign = tokenList.getNextToken();
        this.nodes.add(assign);
        ExpParser expParser = new ExpParser(tokenList);
        Exp exp = expParser.parseExp();
        this.nodes.add(exp);
        Token semicn = tokenList.getNextToken();
        if (semicn.getType() != TokenType.SEMICN) {
            Error error = new Error();
            // 回退一个token来获取行号
            tokenList.fallbackToken(2);
            Token token = tokenList.getNextToken();
            TokenError tokenError = new TokenError(token.getLineNumber(), 'i');
            error.addTokenError(tokenError);
            // 补全 ';' 以便语法分析继续下去
            semicn = new Token(TokenType.SEMICN, ";", token.getLineNumber());
        }
        this.nodes.add(semicn);
        int startLine = this.nodes.get(0).getStarttLine();
        int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
        StmtAssign stmtAssign = new StmtAssign(startLine, endLine, "", this.nodes);
        return stmtAssign;
    }
}
