package frontend.parser.block;

import java.util.ArrayList;

import frontend.TokenIterator;
import frontend.parser.stmt.StmtNode;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

/*
 * 语句块Block          ==> '{' { BlockItem } '}'
 */
public class Block implements StmtNode {
    private final String name = "<Block>";
    private TokenIterator tokens;
    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private ArrayList<BlockItem> blockItems = new ArrayList<>();

    public Block(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        StringBuilder sb = new StringBuilder();
        children.forEach(child -> sb.append(child.syntaxPrinter()));
        sb.append(name + "\n");
        return sb.toString();
    }

    @Override
    public boolean parse() {
        Token lBrace = tokens.next();
        children.add(lBrace);

        Token token = tokens.next();
        // until we reach the right brace
        while (!token.getType().equals(TokenType.RBRACE)) {
            tokens.stepBack(1);
            BlockItem blockItem = new BlockItem(tokens);
            blockItem.parse();
            blockItems.add(blockItem);
            children.add(blockItem);
            token = tokens.next();
        }
        // rbrace is iterated in the while loop
        children.add(token);
        return true;
    }

}
