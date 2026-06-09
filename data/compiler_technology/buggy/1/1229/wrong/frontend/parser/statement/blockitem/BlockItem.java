package frontend.parser.statement.blockitem;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.declaration.Decl;
import frontend.parser.statement.stmt.Stmt;

public class BlockItem implements Node {
    private final String name = "<BlockItem>";
    private BlockItemIFace blockItemIFace;

    private TokenList tokenList;

    public BlockItem(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseBlockItem(){
        Token token = tokenList.seeAfterToken(0);
        if (token.getType().equals(TokenType.CONSTTK) ||
            token.getType().equals(TokenType.INTTK)||
            token.getType().equals(TokenType.CHARTK)){
            Decl decl = new Decl(tokenList);
            decl.parseDecl();
            this.blockItemIFace = decl;
        } else {
            Stmt stmt = new Stmt(tokenList);
            stmt.parseStmt();
            this.blockItemIFace = stmt;
        }
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.blockItemIFace.syntaxOutput());
        //sb.append(this.name + "\n");
        return sb.toString();
    }
}
