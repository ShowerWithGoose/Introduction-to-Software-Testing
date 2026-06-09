package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;

public class CompUnit {

    public CompUnit parse(Parser parser, BufferedWriter writer) throws IOException {
        // 解析编译单元，包含多个 Decl 和 FuncDef
        while(parser.tokens.size() > parser.currentTokenIndex + 2 && parser.tokens.get(parser.currentTokenIndex + 2).type != LexType.LPARENT){
            new Decl().parse(parser,writer);
            // writer.write("<Decl>\n");
        }
        while(parser.tokens.get(parser.currentTokenIndex + 1).type != LexType.MAINTK){
            new FuncDef().parse(parser,writer);
            writer.write("<FuncDef>\n");
        }
        // 解析 MainFuncDef (主函数定义)
        new MainFuncDef().parse(parser,writer);
        writer.write("<MainFuncDef>\n");
        writer.write("<CompUnit>\n");
        writer.flush();
        return this;
    }
}
