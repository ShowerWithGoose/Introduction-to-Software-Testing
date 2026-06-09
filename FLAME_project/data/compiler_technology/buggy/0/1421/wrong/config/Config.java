package config;

public class Config {
    public static final boolean DEBUG = true;
    public static final boolean INIT = true;
    public static final int DIY_TESTFILE = 0;
    public static final boolean LEXER_OUTPUT = true;
    public static final boolean ERROR_OUTPUT = true;
    public static final boolean TOKEN_FULL_DESC = false;

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("----------\n");
        sb.append("Config Information\n");
        sb.append("DEBUG: " + DEBUG + "\n");
        sb.append("INIT: " + INIT + "\n");
        sb.append("DIY_TESTFILE: " + DIY_TESTFILE + "\n");
        sb.append("LEXER_OUTPUT: " + LEXER_OUTPUT + "\n");
        sb.append("ERROR_OUTPUT: " + ERROR_OUTPUT + "\n");
        sb.append("TOKEN_FULL_DESC: " + TOKEN_FULL_DESC + "\n");
        sb.append("----------\n");
        return sb.toString();
    }
}
