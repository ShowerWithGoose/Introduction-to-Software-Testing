package frontend.treenode;

import frontend.token.Token;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import static frontend.executor.Parser.writeParser;

// 语句块 Block → '{' { BlockItem } '}'
public class Block {
    public String nodeName;
    public Token lbraceToken, rbraceToken;
    public List<BlockItem> blockItemList = new ArrayList<>();

    public Block(String nodeName, Token lbraceToken, Token rbraceToken, List<BlockItem> blockItemList) {
        this.nodeName = nodeName;
        this.lbraceToken = lbraceToken;
        this.rbraceToken = rbraceToken;
        this.blockItemList = blockItemList;
    }

    // 语句块 Block → '{' { BlockItem } '}'
    public void print() throws IOException {
        writeParser(lbraceToken.getTypeAndContent());
        if (!blockItemList.isEmpty()) {
            for (BlockItem blockItem : blockItemList)
                blockItem.print();
        }
        writeParser(rbraceToken.getTypeAndContent());
        writeParser(nodeName);
    }
}
