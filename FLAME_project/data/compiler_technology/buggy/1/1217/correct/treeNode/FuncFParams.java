package treeNode;

import frontend.*;
import java.io.BufferedWriter;
import java.io.IOException;

public class FuncFParams {
    public FuncFParams parse(Parser parser,BufferedWriter writer) throws IOException{

        new FuncFParam().parse(parser,writer);
        writer.write("<FuncFParam>\n");
        // 匹配逗号并继续解析其他形参
        while (parser.match(LexType.COMMA)) {
            writer.write("COMMA ,\n");
            new FuncFParam().parse(parser,writer);
            writer.write("<FuncFParam>\n");
        }
        writer.flush();
        return this;
    }
}
