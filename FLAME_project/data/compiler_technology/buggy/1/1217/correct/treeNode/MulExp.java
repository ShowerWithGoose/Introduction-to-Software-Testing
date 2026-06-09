package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;
public class MulExp {
    public MulExp parse(Parser parser,BufferedWriter writer) throws IOException{

        new UnaryExp().parse(parser,writer);
        writer.write("<UnaryExp>\n");
        while (parser.match(LexType.MULT) || parser.match(LexType.DIV) || parser.match(LexType.MOD)) {
            writer.write("<MulExp>\n");
            writer.write(parser.tokens.get(parser.currentTokenIndex-1).type+" "+parser.tokens.get(parser.currentTokenIndex-1).word+"\n");
            new MulExp().parse(parser,writer);
            
        }
        writer.flush();
        return this;
    }
}
