import frontend.parser.Ast;
import frontend.parser.Parser;
import frontend.lexer.Lexer;
import frontend.lexer.TokenList;
import output.MyStream;

import java.io.*;

// 按两次 Shift 打开“随处搜索”对话框并输入 `show whitespaces`，
// 然后按 Enter 键。现在，您可以在代码中看到空格字符。
public class Compiler {
    public static void main(String[] args) throws IOException {
        BufferedInputStream fileIn = MyStream.getInput();
        TokenList tokenList = Lexer.getInstance().execute(fileIn);
        Ast ast = new Parser(tokenList).parse();


        MyStream.close();

    }
}