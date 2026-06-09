package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;

import error.ErrorType;

public class ConstDecl {
    public ConstDecl parse(Parser parser, BufferedWriter writer) throws IOException{
        writer.write("CONSTTK const\n");
        parser.match(LexType.CONSTTK);
        new BType().parse(parser,writer); // 解析基本类型
        new ConstDef().parse(parser,writer); // 解析常量定义
        writer.write("<ConstDef>\n");
        while (parser.getCurrentToken().type == LexType.COMMA) {
            writer.write("COMMA ,\n");
            parser.match(LexType.COMMA);
            new ConstDef().parse(parser,writer); // 解析多个常量定义
            writer.write("<ConstDef>\n");
        }
        if(!parser.match(LexType.SEMICN)){
            parser.reportError(parser.tokens.get(parser.currentTokenIndex-1), ErrorType.i);
        }else{
            writer.write("SEMICN ;\n");
        }
        writer.flush();
        return this;
    }
}
