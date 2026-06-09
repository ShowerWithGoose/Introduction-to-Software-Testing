package utils;

public class GlobalVars {

    public static boolean debug = false;

    public enum CurLab {
        LEXER,
        PARSER,
    };

    public static CurLab curLab = CurLab.PARSER;
}
