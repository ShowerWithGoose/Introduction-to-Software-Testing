package frontend;

import java.io.File;

public class Config {
    public static String source = "testfile.txt";
    public static String output;

    public static boolean emitLexer = true;
    public static String LexerOutput = "lexer.txt";

    public static boolean emitError = true;
    public static String errorOutput = "error.txt";

    public static boolean emitSyntaxTree = true;
    public static String syntaxTreeOutput = "parser.txt";
    public static java.io.FileWriter syntaxTreeWriter = null;
}
