import frontend.SourceFileLexer;
import frontend.lexer.TokenLexer;

import java.io.*;

/**
 * @author
 */
public class Compiler {
    public static void main(String[] args) {
        String inputFileName = "testfile.txt";
        InputStream inputFileStream = null;
        try {
            inputFileStream = new FileInputStream(inputFileName);
        } catch (FileNotFoundException e) {
            System.err.println("Can not open " + inputFileName);
        }
        SourceFileLexer sourceFileLexer = new SourceFileLexer(inputFileStream);
        TokenLexer tokenLexer = new TokenLexer(sourceFileLexer);
        String outputFileName = "";
        if (tokenLexer.ifErrorListEmpty()) {
            outputFileName = "lexer.txt";
            writeToFile(outputFileName, tokenLexer.getTokenList().toString());
        } else {
            outputFileName = "error.txt";
            writeToFile(outputFileName, tokenLexer.getErrorList().toString());
        }
        //System.out.println(tokenLexer.getTokenList());
    }

    /**
     * 工具类，用于输出词法分析信息或者错误信息
     * @param outputFileName 输出文件名
     * @param content 输出内容
     */
    private static void writeToFile(String outputFileName, String content) {
        try (OutputStream outputStream = new FileOutputStream(outputFileName)) {
            outputStream.write(content.getBytes());
        } catch (FileNotFoundException e) {
            System.err.println("Cannot open " + outputFileName);
        } catch (IOException e) {
            System.err.println("Cannot write " + outputFileName);
        }
    }
}
