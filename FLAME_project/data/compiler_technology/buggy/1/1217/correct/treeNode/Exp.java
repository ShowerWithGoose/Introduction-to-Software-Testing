package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;

public class Exp {
    public Exp parse(Parser parser,BufferedWriter writer) throws IOException{

        new AddExp().parse(parser,writer);
        writer.write("<AddExp>\n");
        writer.flush();
        return this;
    }
}
