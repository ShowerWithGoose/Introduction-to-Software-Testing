package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;
public class FuncType {
    public FuncType parse(Parser parser,BufferedWriter writer) throws IOException{
        if (parser.getCurrentToken().type == LexType.VOIDTK || parser.getCurrentToken().type == LexType.INTTK || parser.getCurrentToken().type == LexType.CHARTK) {
            writer.write(parser.getCurrentToken().type+" "+parser.getCurrentToken().word+"\n");
            parser.nextToken();
        }
        writer.flush();
        return this;
    }
}
