package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;
import error.ErrorType;

public class VarDecl {
    public VarDecl parse(Parser parser,BufferedWriter writer) throws IOException{

        new BType().parse(parser,writer);

        new VarDef().parse(parser,writer);
        writer.write("<VarDef>\n");
        // 解析多个变量定义
        while (parser.match(LexType.COMMA)) {
            writer.write("COMMA ,\n");
            new VarDef().parse(parser,writer);
            writer.write("<VarDef>\n");
        }

        // 匹配 ';'
        if (!parser.match(LexType.SEMICN)) {
            parser.reportError(parser.tokens.get(parser.currentTokenIndex-1),ErrorType.i);
        }else{
            writer.write("SEMICN ;\n");
        }
        writer.flush();
        return this;
    }
}
