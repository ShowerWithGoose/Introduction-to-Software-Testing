package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;
public class Cond {
    public Cond parse(Parser parser,BufferedWriter writer) throws IOException{

        // 解析逻辑或表达式 LOrExp
        new LOrExp().parse(parser,writer);
        writer.write("<LOrExp>\n");
        writer.flush();
        return this;
    }
}
