import frontend.lexicAnalysis.Lexer;

import java.io.*;
import java.util.ArrayList;

/**
 * 主程序
 * author:
 */
public class Compiler {

    public static void main(String[] args) throws IOException {
        String INPUT_FILE = "testfile.txt";
        String OUTPUT_LEXIC_FILE = "lexer.txt";
        String OUTPUT_ERROR_FILE = "error.txt";

        boolean OUTPUT_LEXIC_ANALYSIS = true; // 是否输出词法分析内容
        boolean OUTPUT_ERROR_INFO = true; // 是否输出错误内容

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
        String tokenStr = lexer.getTokenList().toString();
        String errorStr = lexer.getErrorList().toString();
        if (OUTPUT_LEXIC_ANALYSIS) {
            try (FileWriter fileWriter = new FileWriter(OUTPUT_LEXIC_FILE)) {
                fileWriter.write(tokenStr);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        if (OUTPUT_ERROR_INFO) {
            try (FileWriter fileWriter = new FileWriter(OUTPUT_ERROR_FILE)) {
                fileWriter.write(errorStr);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }


    }
}
