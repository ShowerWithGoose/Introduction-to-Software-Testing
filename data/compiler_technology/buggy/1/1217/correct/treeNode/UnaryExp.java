package treeNode;

import error.ErrorType;
import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;

public class UnaryExp {
    public UnaryExp parse(Parser parser,BufferedWriter writer) throws IOException{
        if (parser.getCurrentToken().type == LexType.IDENFR && parser.tokens.get(parser.currentTokenIndex+1).type == LexType.LPARENT) {
            parser.match(LexType.IDENFR);
            parser.match(LexType.LPARENT);
            writer.write(parser.tokens.get(parser.currentTokenIndex-2).type+" "+parser.tokens.get(parser.currentTokenIndex-2).word+"\n");
            writer.write("LPARENT (\n");
            if (parser.getCurrentToken().type != LexType.RPARENT) {
                new FuncRParams().parse(parser,writer);
                writer.write("<FuncRParams>\n");
            }
            if (!parser.match(LexType.RPARENT)) {
                parser.reportError(parser.tokens.get(parser.currentTokenIndex-1), ErrorType.j);
            }else{
                writer.write("RPARENT )\n");
            }
        } else if (parser.getCurrentToken().type == LexType.PLUS || parser.getCurrentToken().type == LexType.MINU || parser.getCurrentToken().type == LexType.NOT) {
            new UnaryOp().parse(parser,writer);
            writer.write("<UnaryOp>\n");
            new UnaryExp().parse(parser,writer);
            writer.write("<UnaryExp>\n");
        } else {
            new PrimaryExp().parse(parser,writer);
            writer.write("<PrimaryExp>\n");
        }
        writer.flush();
        return this;
    }
}
