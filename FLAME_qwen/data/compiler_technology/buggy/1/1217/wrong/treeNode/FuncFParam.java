package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;

import error.ErrorType;

public class FuncFParam {
    public FuncFParam parse(Parser parser,BufferedWriter writer) throws IOException {

        // 解析基本类型 BType
        new BType().parse(parser,writer);
        writer.write("IDENFR "+parser.getCurrentToken().word+"\n");
        parser.match(LexType.IDENFR);

        // 匹配可能的数组符号 '[' ']'
        if (parser.match(LexType.LBRACK)) {
            writer.write("LBRACK [\n");
            if (!parser.match(LexType.RBRACK)) {
                parser.reportError(parser.tokens.get(parser.currentTokenIndex-1), ErrorType.k);
            }else{
                writer.write("RBRACK ]\n");
            }
        }
        writer.flush();
        return this;
    }
}
