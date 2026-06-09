import error.ErrorChecker;
import frontend.preprocess.Extractor;
import frontend.lexer.Lexer;

import java.io.IOException;

/**
 * @Description Compiler </br>
 * 前端：词法分析（源程序提取器、语法分析器、保留字检查器）</br>
 * 错误处理：（错误检查器）</br>
 */

public class Compiler {
    public static void main(String[] args) throws IOException {
        // 读取源程序文本文件
        String content = Extractor.extractSourceCode();

        // 词法分析
        Lexer.lexicalAnalysis(content);
        // Lexer.printResult();
        Lexer.printResultToFile("lexer.txt");
        Lexer.clearResult();
        // ErrorChecker.printError();
        ErrorChecker.printErrorToFile("error.txt");
        ErrorChecker.clearError();

    }
}
