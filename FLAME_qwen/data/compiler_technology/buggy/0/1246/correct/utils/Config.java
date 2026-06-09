package utils;

/**
 * @Description 输入输出流控制
 * @Author
 * @Date 2024/9/17
 */

public class Config {
    // 项目根路径
    private static final String workingDir = System.getProperty("user.dir");

    // ============== 输出配置开关 ================、
    // 是否进行本地测试（false提交时用，true本地测试用）
    public static boolean atLocal = false;
    // 是否输出词法分析结果
    public static boolean outputLexer = true;
    // 是否输出错误处理结果
    public static boolean outputErrors = true;

    // ============== 本地测试路径 ================
    // 输入文件路径
    public static String localInputFilePath = workingDir + "/testcases/testfile5.txt";
    // 词法分析输出文件路径
    public static String localOutputLexerFilePath = workingDir + "/testcases/lexer.txt";
    // 错误处理输出文件路径
    public static String localOutputErrorFilePath = workingDir + "/testcases/error.txt";

    // ============== 在线评测路径 ================
    // 输入文件路径
    public static String inputFilePath = "testfile.txt";
    // 词法分析输出文件路径————lexer now
    public static String outputLexerFilePath = "lexer.txt";
    // 错误处理输出文件路径
    public static String outputErrorFilePath = "error.txt";

    // =============== 控制台相关输出开关 ==================
    // 是否在控制台输出词法分析的tokens
    public static boolean debuggingTokens = false;
}
