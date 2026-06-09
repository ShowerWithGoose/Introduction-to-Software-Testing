import src.errorHandle.ErrorList;
import src.lexicAnalysis.Lexer;
import src.lexicAnalysis.TokenList;
import src.syntaxAnalysis.Parser;
import src.syntaxAnalysis.SyntaxList;

import java.io.*;
import java.util.ArrayList;

/**
 * 主程序
 * author:
 */
public class Compiler {

    public static void main(String[] args) throws IOException {
        // 文件名
        final String INPUT_FILE = "testfile.txt";
        final String OUTPUT_LEXIC_FILE = "lexer.txt";
        final String OUTPUT_SYNTAX_FILE = "parser.txt";
        final String OUTPUT_ERROR_FILE = "error.txt";

        boolean OUTPUT_LEXIC_ANALYSIS = true; // 是否输出词法分析内容
        boolean OUTPUT_SYNTAX_ANALYSIS = true; // 是否输出语法分析内容
        boolean OUTPUT_ERROR_INFO = true; // 是否输出错误内容

        TokenList tokenList; // 全局Token表
        ErrorList errorList; // 全局错误表
        SyntaxList syntaxList; // 语法信息列表

        /*----------------源文件读入部分--------------------*/
        File inputFile = new File(INPUT_FILE);
        BufferedReader bufferedReader = new BufferedReader(new FileReader(inputFile));
        ArrayList<String> inputList = new ArrayList<>();
        String str;
        while ((str = bufferedReader.readLine()) != null) {
            inputList.add(str);
        }

        /*----------------词法分析部分--------------------*/
        Lexer lexer = new Lexer(inputList);
        lexer.analyze();
        tokenList = lexer.getTokenList();
        errorList = lexer.getErrorList();

        if (OUTPUT_LEXIC_ANALYSIS) {
            try (FileWriter fileWriter = new FileWriter(OUTPUT_LEXIC_FILE)) {
                fileWriter.write(tokenList.toString());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
//        if (OUTPUT_ERROR_INFO) {
//            try (FileWriter fileWriter = new FileWriter(OUTPUT_ERROR_FILE)) {
//                fileWriter.write(errorList.toString());
//            } catch (IOException e) {
//                e.printStackTrace();
//            }
//        }

        /*----------------语法分析部分--------------------*/
        Parser parser = new Parser(tokenList);
        parser.analyze();
        syntaxList = parser.getSyntaxList();
        errorList.addAll(parser.getErrorList().getErrors());

        if (OUTPUT_SYNTAX_ANALYSIS) {
            try (FileWriter fileWriter = new FileWriter(OUTPUT_SYNTAX_FILE)) {
                fileWriter.write(syntaxList.toString());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        if (OUTPUT_ERROR_INFO) {
            try (FileWriter fileWriter = new FileWriter(OUTPUT_ERROR_FILE)) {
                fileWriter.write(errorList.toString());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }
}
