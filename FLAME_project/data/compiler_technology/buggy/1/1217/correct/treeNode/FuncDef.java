package treeNode;

import error.ErrorType;
import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;
public class FuncDef {
    public FuncDef parse(Parser parser,BufferedWriter writer) throws IOException{

        // 解析函数类型
        new FuncType().parse(parser,writer);
        writer.write("<FuncType>\n");
        // 匹配标识符 Ident
        writer.write("IDENFR "+parser.getCurrentToken().word+"\n");
        parser.match(LexType.IDENFR);
        
        // 匹配 '('
        writer.write("LPARENT (\n");
        parser.match(LexType.LPARENT);

        // 解析可能的函数参数列表
        if (parser.getCurrentToken().type != LexType.RPARENT) {
            new FuncFParams().parse(parser,writer);
            writer.write("<FuncFParams>\n");
        }

        // 匹配 ')'
        if (!parser.match(LexType.RPARENT)) {
            parser.reportError(parser.tokens.get(parser.currentTokenIndex-1), ErrorType.j);
        }else{
            writer.write("RPARENT )\n");
        }

        // 解析函数体 Block
        new Block().parse(parser,writer);
        writer.write("<Block>\n");
        writer.flush();
        return this;
    }
}
