import err.ErrOutput;
import frontend.lexer.Lexer;
import frontend.lexer.TokenList;

import java.io.*;

// 按两次 Shift 打开“随处搜索”对话框并输入 `show whitespaces`，
// 然后按 Enter 键。现在，您可以在代码中看到空格字符。
public class Compiler {
    private static final String input = "testfile.txt";
    private static final String output = "lexer.txt";
    private static final String err = "error.txt";
    public static void main(String[] args) throws IOException {
        BufferedInputStream fileIn = new BufferedInputStream(new FileInputStream(input));
        BufferedWriter fileOut = new BufferedWriter(new FileWriter(output));
        ErrOutput.open(err);

        TokenList tokenList = Lexer.getInstance().execute(fileIn);

        tokenList.print(fileOut);

        fileOut.close();
        ErrOutput.close();
    }
}