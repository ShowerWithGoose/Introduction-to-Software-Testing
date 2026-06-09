package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;

public class InitVal {
    public InitVal parse(Parser parser,BufferedWriter writer) throws IOException{

        // 解析表达式或复合结构
        if (parser.getCurrentToken().type == LexType.LBRACE) {
            writer.write("LBRACE {\n");
            parser.match(LexType.LBRACE);
            if (parser.getCurrentToken().type != LexType.RBRACE) {
                new Exp().parse(parser,writer);
                writer.write("<Exp>\n");
                while (parser.match(LexType.COMMA)) {
                    writer.write("COMMA ,\n");
                    new Exp().parse(parser,writer);
                    writer.write("<Exp>\n");
                }
            }
            writer.write("RBRACE }\n");
            parser.match(LexType.RBRACE);
        } else if (parser.getCurrentToken().type == LexType.STRCON){
            writer.write("STRCON "+parser.getCurrentToken().word+"\n");
            parser.match(LexType.STRCON);
        } else {
            new Exp().parse(parser,writer);
            writer.write("<Exp>\n");
        }
        writer.flush();
        return this;
    }
}
