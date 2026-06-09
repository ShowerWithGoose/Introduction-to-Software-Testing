package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;
public class EqExp {
    public EqExp parse(Parser parser,BufferedWriter writer) throws IOException{

        new RelExp().parse(parser,writer);
        writer.write("<RelExp>\n");
        while (parser.match(LexType.EQL) || parser.match(LexType.NEQ)) {
            writer.write("<EqExp>\n");
            writer.write(parser.tokens.get(parser.currentTokenIndex-1).type+" "+parser.tokens.get(parser.currentTokenIndex-1).word+"\n");
            new EqExp().parse(parser,writer);
            
        }
        writer.flush();
        return this;
    }
}
