package treeNode;

import error.ErrorType;
import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;

public class PrimaryExp {
    public PrimaryExp parse(Parser parser,BufferedWriter writer) throws IOException{
        if (parser.match(LexType.LPARENT)) {
            writer.write("LPARENT (\n");
            new Exp().parse(parser,writer);
            writer.write("<Exp>\n");
            if (!parser.match(LexType.RPARENT)) {
                parser.reportError(parser.tokens.get(parser.currentTokenIndex-1), ErrorType.j);
            }else{
                writer.write("RPARENT )\n");
            }
        } else if (parser.getCurrentToken().type == LexType.IDENFR) {
            new LVal().parse(parser,writer);
            writer.write("<LVal>\n");
        } else if (parser.getCurrentToken().type == LexType.INTCON) {
            writer.write("INTCON "+parser.getCurrentToken().word+"\n");
            new Number().parse(parser);
            writer.write("<Number>\n");
        } else if (parser.getCurrentToken().type == LexType.CHRCON) {
            writer.write("CHRCON "+parser.getCurrentToken().word+"\n");
            new Character().parse(parser);
            writer.write("<Character>\n");
        } 
        writer.flush();
        return this;
    }
}
