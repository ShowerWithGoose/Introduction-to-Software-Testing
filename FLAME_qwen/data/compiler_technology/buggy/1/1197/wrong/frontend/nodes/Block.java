package frontend.nodes;

import frontend.LexType;
import frontend.Lexer;
import frontend.NodeRegistry;
import frontend.NodeType;

public class Block extends Node {
    public Block() {
        super(NodeType.BLOCK);
    }

    public static Node parse() {
        Block block = new Block();
        block.terminalCheck(LexType.LBRACE);
        while (Lexer.INSTANCE.getLexType() != LexType.RBRACE) {
            block.parseAndAdd(NodeRegistry.BLOCK_ITEM);
        }
        block.terminalCheck(LexType.RBRACE);
        return block;
    }
}
