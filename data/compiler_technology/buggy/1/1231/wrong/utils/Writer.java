package utils;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;

import error.ErrorList;
import frontend.parser.CompUnit;
import nodes.Token;
import nodes.TokenType;

public class Writer {
    public static void writeTokens(ArrayList<Token> tokens, boolean hasError) {
        //write to output.txt
        File lexerFile = new File("lexer.txt");
        File errorFile = new File("error.txt");
        try {
            if (!hasError) {
                PrintWriter writer = new PrintWriter(lexerFile);
                for (Token token : tokens) {
                    writer.println(token);
                    writer.flush();
                }
                writer.close();
            } else {
                PrintWriter writer = new PrintWriter(errorFile);
                for (Token token : tokens) {
                    if (token.getType() == TokenType.UNDEFINE) {
                        writer.println(token);
                        writer.flush();
                    }
                }
                writer.close();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void writeSyntaxTree(CompUnit compUnit) {
        File parserFile = new File("parser.txt");
        File ErrorFile = new File("error.txt");
        if (ErrorList.hasError()) {
            try {
                PrintWriter writer = new PrintWriter(ErrorFile);
                writer.println(ErrorList.getInstance().toString());
                writer.flush();
                writer.close();
            } catch (Exception e) {
                e.printStackTrace();
            }

        } else {
            try {
                PrintWriter writer = new PrintWriter(parserFile);
                writer.println(compUnit.syntaxPrinter());
                writer.flush();
                writer.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
