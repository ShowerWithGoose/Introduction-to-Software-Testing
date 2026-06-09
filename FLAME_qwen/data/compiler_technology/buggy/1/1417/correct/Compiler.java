import frontend.lexer.Token;
import frontend.lexer.TokenLexer;
import frontend.lexer.TokenList;
import frontend.parser.CompUnit;
import frontend.parser.CompUnitParser;
import frontend.error.Error;
import frontend.parser.Node;

import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Objects;
import java.util.Stack;
import java.util.regex.Pattern;

public class Compiler {
    public static void main(String[] args) throws IOException {
        InputStream inputFileStream = new FileInputStream("testfile.txt");
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputFileStream));
        String lineNow = null;
        ArrayList<String> lines = new ArrayList<>();
        // 把testfile.txt文件中的所有内容都读取出来，之后传给Lexer一个字符串的ArrayList
        while (true) {
            lineNow = bufferedReader.readLine();
            if (lineNow == null) {
                break;
            }
            lines.add(lineNow);
        }
        // 错误处理部分
        Error error = new Error();
        // lines就是将testfile.txt文件的内容一行一行的ArrayList
        TokenLexer lexer = new TokenLexer(lines);
        TokenList tokenList = new TokenList(lexer.getTokens());
        // 将词法分析部分得到的tokens作为参数参与到语法分析部分
        CompUnitParser compUnitParser = new CompUnitParser(tokenList);
        CompUnit compUnit = compUnitParser.parseCompUnit();

//        lexer.outputInfo();

        // 先判断词法分析部分和语法分析部分有没有出错
        if (error.getIsError()) {
            OutputStream outputStream = new FileOutputStream("error.txt");
            // 因为是队列，所以遍历完之后所有的元素会被弹出去
            outputStream.write(error.toString().getBytes());
//            error.outputErrorInfo();
        }

        // 将词法分析的结果输出到lexer.txt
        OutputStream outputStream = new FileOutputStream("lexer.txt");
        outputStream.write(lexer.lexerOutput().getBytes());

        // 将语法分析的结果输出到parser.txt
        outputStream = new FileOutputStream("parser.txt");
        outputStream.write(compUnit.syntaxOutput().getBytes());

    }
}
