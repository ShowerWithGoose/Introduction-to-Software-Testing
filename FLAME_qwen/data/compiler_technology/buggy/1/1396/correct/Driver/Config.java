package Driver;

public class Config {
    public static final String TEST_FILE = "testfile.txt";
    public static final String LEXER_OUTPUT_FILE = "lexer.txt";
    public static final String PARSER_OUTPUT_FILE = "parser.txt";
    public static final String SYMBOL_OUTPUT_FILE = "symbol.txt";
    public static final String ERROR_OUTPUT_FILE = "error.txt";

    public static boolean PRINT_TOKENS = false;
    public static boolean PRINT_AST = true;
    public static boolean PRINT_SYMBOL = true;
    public static boolean PRINT_IR = false;
    public static boolean PRINT_ASM = false;

    public static Step STOP_AT = Step.SYNTAX;

    public static final String CHARSET_NAME = "UTF-8";

    public static enum Step { LEXICAL, SYNTAX, SEMANTIC, IR, ASM }
}
