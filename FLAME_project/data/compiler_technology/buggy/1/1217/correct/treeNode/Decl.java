package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;

public class Decl{
    public Decl parse(Parser parser,BufferedWriter writer) throws IOException{

        if (parser.getCurrentToken().type == LexType.CONSTTK) {
            // 解析 ConstDecl (常量声明)
            new ConstDecl().parse(parser,writer);
            writer.write("<ConstDecl>\n");
        } else if (parser.getCurrentToken().type == LexType.INTTK || parser.getCurrentToken().type == LexType.CHARTK) {
            // 解析 VarDecl (变量声明)
            new VarDecl().parse(parser,writer);
            writer.write("<VarDecl>\n");
        }
        writer.flush();
        return this;
    }
}
