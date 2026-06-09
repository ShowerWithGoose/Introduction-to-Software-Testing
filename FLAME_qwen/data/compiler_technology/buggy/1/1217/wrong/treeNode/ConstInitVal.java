package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;

public class ConstInitVal {
    public ConstInitVal parse(Parser parser,BufferedWriter writer) throws IOException{
        if (parser.getCurrentToken().type == LexType.STRCON) { 
            writer.write("STRCON "+parser.getCurrentToken().word+"\n");
            parser.nextToken();
        } else if (parser.getCurrentToken().type == LexType.LBRACE) {
            writer.write("LBRACE {\n");
            parser.match(LexType.LBRACE);
            if (parser.getCurrentToken().type != LexType.RBRACE) {
                new ConstExp().parse(parser,writer);
                writer.write("<ConstExp>\n");
                while (parser.getCurrentToken().type == LexType.COMMA) {
                    writer.write("COMMA ,\n");
                    parser.match(LexType.COMMA);
                    new ConstExp().parse(parser,writer);
                    writer.write("<ConstExp>\n");
                }
            }
            writer.write("RBRACE }\n");
            parser.match(LexType.RBRACE);
        } else {
            new ConstExp().parse(parser,writer);
            writer.write("<ConstExp>\n");
        }
        writer.flush();
        return this;
    }
}
