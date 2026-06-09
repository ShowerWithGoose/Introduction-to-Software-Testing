package frontend.nodes;

import frontend.Lexer;
import frontend.NodeRegistry;
import frontend.NodeType;

public class BlockItem extends Node {
    public BlockItem() {
        super(NodeType.BLOCK_ITEM);
    }

    public static Node parse() {
        BlockItem blockItem = new BlockItem();
        switch (Lexer.INSTANCE.getLexType()) {
            case INTTK, CHARTK, CONSTTK -> blockItem.parseAndAdd(NodeRegistry.DECL);
            default -> blockItem.parseAndAdd(NodeRegistry.STMT);
        }
        return blockItem;
    }
}
