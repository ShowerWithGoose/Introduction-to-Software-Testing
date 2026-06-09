import config.Config;
import frontend.Lexer;
import error.ErrorHandler;
import frontend.Parser;
import utils.IOTools;

import java.io.*;

public class Compiler {

    private static final String INPUT_FILE_PATH = Config.is_local ? Config.LOCAL_INPUT_FILE_PATH : Config.INPUT_FILE_PATH; // 输入文件
    private static final String OUTPUT_LEXER_FILE_PATH = Config.OUTPUT_LEXER_FILE_PATH; // 词法分析结果
    private static final String OUTPUT_PARSER_FILE_PATH = Config.OUTPUT_PARSER_FILE_PATH; // 语法分析结果
    private static final String OUTPUT_ERROR_FILE_PATH = Config.OUTPUT_ERROR_FILE_PATH; // 错误处理结果

    public static void main(String[] args) throws IOException {
        initOutputFile(true);
        String fileContent = IOTools.readFile(INPUT_FILE_PATH); // 读取文件内容
        Lexer lexer = new Lexer(); // 构建词法分析器
        lexer.analyze(fileContent); // 开始词法分析
        if (Config.is_lexer) {
            if (ErrorHandler.withoutError())// 没有错误
                IOTools.writeFile(lexer.lexerResult(), OUTPUT_LEXER_FILE_PATH, true);
            else // 有错误
                IOTools.writeFile(ErrorHandler.getErrorsAllOrder(), OUTPUT_ERROR_FILE_PATH, true);
        }

        Parser parser = new Parser(lexer.getTokenList());
        parser.analyze();
        if (Config.is_parser) {
            if (ErrorHandler.withoutError())
                parser.printParseAns();
            else
                IOTools.writeFile(ErrorHandler.getErrorsAllOrder(), OUTPUT_ERROR_FILE_PATH, true);
        }


    }

    /**
     * 初始化输出文件
     *
     * @param is_delete 是否删除文件
     */
    private static void initOutputFile(boolean is_delete) {
        if (is_delete) {
            IOTools.deleteFile(OUTPUT_LEXER_FILE_PATH);
            IOTools.deleteFile(OUTPUT_PARSER_FILE_PATH);
            IOTools.deleteFile(OUTPUT_ERROR_FILE_PATH);
        }
        else {
            IOTools.clearFile(OUTPUT_LEXER_FILE_PATH);
            IOTools.clearFile(OUTPUT_PARSER_FILE_PATH);
            IOTools.clearFile(OUTPUT_ERROR_FILE_PATH);
        }
        if (Config.is_only_init) {
            System.out.println("Initialization is complete and exited.");
            System.exit(0);
        }
    }
}