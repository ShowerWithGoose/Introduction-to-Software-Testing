package frontend.parser.statement.blockitem;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.declaration.Decl;
import frontend.parser.declaration.DeclParser;
import frontend.parser.statement.stmt.Stmt;
import frontend.parser.statement.stmt.StmtParser;

import java.util.ArrayList;

// BlockItem - > Decl | Stmt
public class BlockItemParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public BlockItemParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public BlockItem parseBlockItem() {
        Token token = tokenList.getNextToken();
        // BlockItem -> Decl
        if (token.getType() == TokenType.CONSTTK || token.getType() == TokenType.INTTK || token.getType() == TokenType.CHARTK) {
            tokenList.fallbackToken(1);
            DeclParser declParser = new DeclParser(tokenList);
            Decl decl = declParser.parseDecl();
            this.nodes.add(decl);
        }
        // BlockItem -> Stmt
        else {
            tokenList.fallbackToken(1);
            StmtParser stmtParser = new StmtParser(tokenList);
            Stmt stmt = stmtParser.parseStmt();
            this.nodes.add(stmt);
        }
        int startLine = this.nodes.get(0).getStarttLine();
        int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
        BlockItem blockItem = new BlockItem(startLine, endLine, "<BlockItem>", this.nodes);
        return blockItem;
    }
}
