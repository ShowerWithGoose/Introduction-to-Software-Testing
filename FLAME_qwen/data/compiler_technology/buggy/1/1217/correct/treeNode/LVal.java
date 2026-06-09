package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;
import error.ErrorType;

public class LVal {
    public LVal parse(Parser parser,BufferedWriter writer) throws IOException{

        // 期望匹配 Ident 标识符
        writer.write("IDENFR "+parser.getCurrentToken().word+"\n");
        parser.match(LexType.IDENFR);
        // 如果下一个 token 是 '['，说明这是数组访问
        if (parser.match(LexType.LBRACK)) {
            // 解析数组索引的表达式 Exp
            writer.write("LBRACK [\n");
            new Exp().parse(parser,writer);
            writer.write("<Exp>\n");

            // 匹配 ']'
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
