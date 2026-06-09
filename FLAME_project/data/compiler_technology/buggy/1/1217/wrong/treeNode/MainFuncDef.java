package treeNode;

import error.ErrorType;
import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;
public class MainFuncDef {
    public MainFuncDef parse(Parser parser,BufferedWriter writer) throws IOException{

        // 匹配 'int main()'
        if (parser.match(LexType.INTTK) && parser.match(LexType.MAINTK) && parser.match(LexType.LPARENT) && parser.match(LexType.RPARENT)) {
            writer.write("INTTK int\nMAINTK main\nLPARENT (\nRPARENT )\n");
        } else {
            parser.reportError(parser.tokens.get(parser.currentTokenIndex-1), ErrorType.j);
            writer.write("INTTK int\nMAINTK main\nLPARENT (\n");
        }

        new Block().parse(parser,writer);
        writer.write("<Block>\n");
        writer.flush();
        return this;
    }
}
