package utils;

import frontend.lexer.Lexer;
import frontend.lexer.Token;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Printer {
    private static PrintWriter writer;
    private static String args = "lex";

    private static String lex_corr_path = "lexer.txt";
    private static String lex_err_path = "error.txt";

    public static void printLexerTokenList(ArrayList<Token> tokens) {
        for (Token token : tokens) {
            writer.println(token.toString());
        }
        writer.flush();
    }

    public static void close() {
        if (writer != null) {
            writer.close();
        }
    }

    public static void solve(boolean isProCorr) throws IOException {
        switch (args) {
            case "lex" -> {
                writer = isProCorr ? new PrintWriter(new FileWriter(lex_corr_path)) :
                        new PrintWriter(new FileWriter((lex_err_path)));
                printLexerTokenList(Lexer.getTokenToPrint());
            }
        }
        close();
    }
}
