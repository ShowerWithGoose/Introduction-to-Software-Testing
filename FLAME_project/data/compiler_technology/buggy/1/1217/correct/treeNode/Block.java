package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;

public class Block {
    public Block parse(Parser parser,BufferedWriter writer) throws IOException{

        // 匹配 '{'
        parser.match(LexType.LBRACE);
        writer.write("LBRACE {\n");

        // 解析 BlockItem
        while (parser.getCurrentToken().type != LexType.RBRACE) {
            new BlockItem().parse(parser,writer);
        }

        // 匹配 '}'
        writer.write("RBRACE }\n");
        parser.match(LexType.RBRACE);
        writer.flush();
        return this;
    }
}
