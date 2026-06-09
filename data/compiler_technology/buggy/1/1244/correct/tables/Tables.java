package tables;

import error.CompileError;
import token.Token;

import java.util.ArrayList;

public class Tables {
    private static final ArrayList<Token> tokens = new ArrayList<>();
    private static final ArrayList<CompileError> COMPILE_ERRORS = new ArrayList<>();

    public static ArrayList<Token> getTokens() {
        return tokens;
    }

    public static ArrayList<CompileError> getCompilerErrors() {
        return COMPILE_ERRORS;
    }
}
