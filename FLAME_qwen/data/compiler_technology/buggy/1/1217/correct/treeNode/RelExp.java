package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;
public class RelExp {
    public RelExp parse(Parser parser,BufferedWriter writer) throws IOException{

        new AddExp().parse(parser,writer);
        writer.write("<AddExp>\n");
        while (parser.match(LexType.LSS) || parser.match(LexType.GRE) || parser.match(LexType.LEQ) || parser.match(LexType.GEQ)) {
            writer.write("<RelExp>\n");
            writer.write(parser.tokens.get(parser.currentTokenIndex-1).type+" "+parser.tokens.get(parser.currentTokenIndex-1).word+"\n");
            new RelExp().parse(parser,writer);
            
        }
        writer.flush();
        return this;
    }
}
