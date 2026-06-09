package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;

public class BlockItem {
    public BlockItem parse(Parser parser,BufferedWriter writer) throws IOException{

        // 解析 Decl 或 Stmt
        if (parser.getCurrentToken().type == LexType.CONSTTK || parser.getCurrentToken().type == LexType.INTTK || parser.getCurrentToken().type == LexType.CHARTK) {
            new Decl().parse(parser,writer);
        } else {
            new Stmt().parse(parser,writer);
            writer.write("<Stmt>\n");
        }
        writer.flush();
        return this;
    }
}
