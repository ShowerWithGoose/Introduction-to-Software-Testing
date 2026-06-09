/********************************************************************************
 * @FileName     : Config.java
 * @Author       :
 * @Description  : 配置信息，可以控制程序的运行方式
 * @Notice       : None
 * @Time         : 2024-10-14 11:29
 * @Version      : 0.0
 ********************************************************************************/

package config;

public class Config {
    // 本地测试或提交
    public static boolean is_local = false;

    // 输出方式
    public static boolean is_print_to_console = false;

    // 一键初始化（不运行编辑器）
    public static boolean is_only_init = false;

    // 任务阶段
    public static boolean is_lexer = false;
    public static boolean is_parser = true;
    public static boolean is_error = true;

    // 文件路径部分
    public static final String INPUT_FILE_PATH = "testfile.txt"; // 输入文件
    public static final String LOCAL_INPUT_FILE_PATH = "resources/parserTest/C/testcase10/testfile.txt"; // 本地测试输入文件
    public static final String OUTPUT_LEXER_FILE_PATH = "lexer.txt"; // 词法分析结果
    public static final String OUTPUT_PARSER_FILE_PATH = "parser.txt"; // 词法分析结果
    public static final String OUTPUT_ERROR_FILE_PATH = "error.txt"; // 错误处理结果

    // debug部分
    public static final boolean is_debugging = true; // 是否为debug模式
    public static final boolean use_panic = false; // 是否在遇到错误时直接退出程序
    public static final boolean use_parser_info_print = false; // 语法分析时，是否打印符号
    public static final boolean is_printStackTrace = true; // 是否打印错误堆栈
    public static final boolean is_throws_exception = false; // 是否抛出异常

}
