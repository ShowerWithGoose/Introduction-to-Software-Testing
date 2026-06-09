package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;

public class BType {
    public BType parse(Parser parser,BufferedWriter writer) throws IOException{
        if (parser.getCurrentToken().type == LexType.CHARTK || parser.getCurrentToken().type == LexType.INTTK) {
            writer.write(parser.getCurrentToken().type+" "+parser.getCurrentToken().word+"\n");
            parser.nextToken();
        }
        writer.flush();
        return this;
    }
}
