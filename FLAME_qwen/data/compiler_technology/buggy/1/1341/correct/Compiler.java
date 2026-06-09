import frontend.ast.Parser;
import frontend.lexer.Lexer;
import frontend.lexer.TokenStream;
import frontend.symbols.GetSymTable;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) throws IOException {
        Lexer lexer = new Lexer("testfile.txt");
        lexer.scan();
        TokenStream tokenStream = new TokenStream(new ArrayList<>(lexer.getTokens()));
        Parser parser = new Parser(tokenStream);
        parser.parse();
//        GetSymTable getSymTable=new GetSymTable(parser.getCompUnit(),parser.getErrors());
//        getSymTable.parse();
        if (!parser.isError()) {
            FileWriter writer = new FileWriter("parser.txt");
            writer.write(parser.toString());
            //writer.write(GetSymTable.root.toString());
            writer.close();
        } else {
            FileWriter writer = new FileWriter("error.txt");
            writer.write(parser.toString());
            //writer.write(getSymTable.outError());
            writer.close();
        }
    }
}

/*
语义分析：
先建语法树，Parser.parse
再建立符号表，遍历语法树。边遍历，边建立/查错
将生成的符号表给到相应的block,func
符号表：parent,son
符号：名字，类型，初值（可选），是否全局
5 8 9正确但判错了
17-23 26只有语法分析错误

22 26有且仅有i,j类错误
evaluate可能RE？
语义错误把语法错误顶掉？
正确但判错
*/