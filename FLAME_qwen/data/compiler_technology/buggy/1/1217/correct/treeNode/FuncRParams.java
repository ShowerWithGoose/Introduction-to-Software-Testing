package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;

public class FuncRParams {
    public FuncRParams parse(Parser parser,BufferedWriter writer) throws IOException{

        new Exp().parse(parser,writer);
        writer.write("<Exp>\n");
        while (parser.match(LexType.COMMA)) {
            writer.write("COMMA ,\n");
            new Exp().parse(parser,writer);
            writer.write("<Exp>\n");
        }
        writer.flush();
        return this;
    }
}
