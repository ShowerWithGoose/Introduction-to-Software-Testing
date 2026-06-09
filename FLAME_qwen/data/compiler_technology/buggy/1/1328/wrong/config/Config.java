package config;
public class Config {
    /*
     * 各输入输出文件路径
     */
    public static String inputFilePath = "testfile.txt";
//    public static String outputLexerFilePath = "lexer.txt";
    public static String outputLexerFilePath = "parser.txt";
    public static String outputParserFilePath = "parser.txt";
    public static String errorFilePath = "error.txt";
    /*
     * 阶段标识
     */
    public static boolean lexer = false;
    public static boolean parser = true;
}
