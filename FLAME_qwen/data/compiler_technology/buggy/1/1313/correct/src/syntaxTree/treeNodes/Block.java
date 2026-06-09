package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

import java.util.ArrayList;

/**
 * 语句块 Block → '{' { BlockItem } '}'
 */
public class Block extends STNode {
    public Token lBrace;
    public ArrayList<BlockItem> blockItems;
    public Token rBrace;

    public Block() {
        this.blockItems = new ArrayList<BlockItem>();
    }
}
