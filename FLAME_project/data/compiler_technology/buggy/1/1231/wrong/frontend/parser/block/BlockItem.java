package frontend.parser.block;

import frontend.TokenIterator;
import frontend.parser.decl.Decl;
import frontend.parser.stmt.Stmt;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

/*
 * 语句块项		BlockItem      ==> Decl | Stmt
 */
public class BlockItem implements SyntaxNode {
    private String name = "<BlockItem>";
    private TokenIterator tokens;

    private BlockItemNode blockItemNode;

    public BlockItem(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        // NOTE: BlockItem no need to output
        return blockItemNode.syntaxPrinter();
    }

    @Override
    public boolean parse() {
        Token token = tokens.next();
        if (token.getType().equals(TokenType.CONSTTK) ||
                token.getType().equals(TokenType.INTTK) ||
                token.getType().equals(TokenType.CHARTK)) {
            tokens.stepBack(1);
            blockItemNode = new Decl(tokens);
        } else {
            tokens.stepBack(1);
            blockItemNode = new Stmt(tokens);
        }
        return blockItemNode.parse();
    }

}
