package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;

public class UnaryOp {
    public UnaryOp parse(Parser parser,BufferedWriter writer)throws IOException{
        writer.write(parser.getCurrentToken().type+" "+parser.getCurrentToken().word+"\n");
        parser.nextToken();
        writer.flush();
        return this;
    }
}
