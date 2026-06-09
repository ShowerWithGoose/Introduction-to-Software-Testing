package node;

import token.Token;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static utils.IO.writeParser;

// 语句块 Block → '{' { BlockItem } '}'
public class Block {
    private String nodeName;
    private Token lbraceToken;
    private Token rbraceToken;
    private List<BlockItem> blockItemList = new ArrayList<>();

    public Block(String nodeName, Token lbraceToken, Token rbraceToken, List<BlockItem> blockItemList) {
        this.nodeName = nodeName;
        this.lbraceToken = lbraceToken;
        this.rbraceToken = rbraceToken;
        this.blockItemList = blockItemList;
    }

    // 语句块 Block → '{' { BlockItem } '}'
    public void print() throws IOException {
        writeParser(lbraceToken.toString());
        if (!blockItemList.isEmpty()) {
            for (BlockItem blockItem : blockItemList)
                blockItem.print();
        }
        writeParser(rbraceToken.toString());
        writeParser(nodeName);
    }
}
