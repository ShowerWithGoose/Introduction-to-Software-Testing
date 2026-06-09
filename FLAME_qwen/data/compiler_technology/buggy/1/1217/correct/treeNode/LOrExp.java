package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;

public class LOrExp {
    public LOrExp parse(Parser parser,BufferedWriter writer) throws IOException{
        new LAndExp().parse(parser,writer);
        writer.write("<LAndExp>\n");
        while (parser.match(LexType.OR)) {
            writer.write("<LOrExp>\n");
            writer.write("OR ||\n");
            new LOrExp().parse(parser,writer);
            
        }
        writer.flush();
        return this;
    }
}
