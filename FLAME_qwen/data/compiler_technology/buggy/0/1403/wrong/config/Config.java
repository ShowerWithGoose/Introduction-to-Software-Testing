package config;

public class Config {
    public static String inputFile = "testfile.txt";
    public static String lexerOutputFile = "lexer.txt";
    public static String errorFile = "error.txt";

    public static boolean isPrintTokens = true;

    public static void local() {
        inputFile = "files/" + inputFile;
        lexerOutputFile = "files/" + lexerOutputFile;
        errorFile = "files/" + errorFile;
    }
}
