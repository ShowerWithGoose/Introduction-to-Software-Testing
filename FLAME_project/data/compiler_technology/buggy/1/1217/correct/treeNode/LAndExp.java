package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;

public class LAndExp {
    public LAndExp parse(Parser parser,BufferedWriter writer) throws IOException{
        new EqExp().parse(parser,writer);
        writer.write("<EqExp>\n");
        while (parser.match(LexType.AND)) {
            writer.write("<LAndExp>\n");
            writer.write("AND &&\n");
            new LAndExp().parse(parser,writer);
            
        }
        writer.flush();
        return this;
    }
}
