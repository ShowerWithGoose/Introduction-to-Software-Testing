package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;

import error.ErrorType;

public class VarDef {
    public VarDef parse(Parser parser,BufferedWriter writer) throws IOException{

        // 匹配标识符 Ident
        writer.write("IDENFR "+parser.getCurrentToken().word+"\n");
        parser.match(LexType.IDENFR);

        // 解析可能的数组
        if (parser.match(LexType.LBRACK)) {
            writer.write("LBRACK [\n");
            new ConstExp().parse(parser,writer);
            writer.write("<ConstExp>\n");
            if(!parser.match(LexType.RBRACK)){
                parser.reportError(parser.tokens.get(parser.currentTokenIndex-1), ErrorType.k);
            }else{
                writer.write("RBRACK ]\n");
            }
        }

        // 匹配可能的 '=' 及初始值
        if (parser.match(LexType.ASSIGN)) {
            writer.write("ASSIGN =\n");
            new InitVal().parse(parser,writer);
            writer.write("<InitVal>\n");
        }
        writer.flush();
        return this;
    }
}
