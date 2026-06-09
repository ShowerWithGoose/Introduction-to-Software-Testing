package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;
import error.ErrorType;

public class ConstDef {
    public ConstDef parse(Parser parser,BufferedWriter writer) throws IOException{
        writer.write(parser.getCurrentToken().type+" "+parser.getCurrentToken().word+"\n");
        parser.match(LexType.IDENFR); // 假设匹配标识符
        if (parser.getCurrentToken().type == LexType.LBRACK) {
            writer.write("LBRACK [\n");
            parser.match(LexType.LBRACK);
            new ConstExp().parse(parser,writer);
            writer.write("<ConstExp>\n");
            if(!parser.match(LexType.RBRACK)){
                parser.reportError(parser.tokens.get(parser.currentTokenIndex-1), ErrorType.k);
            }else{
                writer.write("RBRACK ]\n");
            }
        }
        writer.write("ASSIGN =\n");
        parser.match(LexType.ASSIGN);
        new ConstInitVal().parse(parser,writer); // 解析常量初值
        writer.write("<ConstInitVal>\n");
        writer.flush();
        return this;
    }
}
