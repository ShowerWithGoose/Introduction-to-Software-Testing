package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;
public class AddExp {
    public AddExp parse(Parser parser,BufferedWriter writer) throws IOException{
        new MulExp().parse(parser,writer);
        writer.write("<MulExp>\n");
        while (parser.match(LexType.PLUS) || parser.match(LexType.MINU)) {
            writer.write("<AddExp>\n");
            writer.write(parser.tokens.get(parser.currentTokenIndex-1).type+" "+parser.tokens.get(parser.currentTokenIndex-1).word+"\n");
            new AddExp().parse(parser,writer);
            
        }
        writer.flush();
        return this;
    }
}
