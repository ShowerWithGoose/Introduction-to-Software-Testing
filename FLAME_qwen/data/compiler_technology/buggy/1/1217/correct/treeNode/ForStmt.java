package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;

public class ForStmt {
    public ForStmt parse(Parser parser,BufferedWriter writer) throws IOException{

        // 解析左值 LVal
        new LVal().parse(parser,writer);
        writer.write("<LVal>\n");
        parser.match(LexType.ASSIGN);
        writer.write("ASSIGN =\n");
        // 解析表达式 Exp
        new Exp().parse(parser,writer);
        writer.write("<Exp>\n");
        writer.flush();
        return this;
    } 
}
