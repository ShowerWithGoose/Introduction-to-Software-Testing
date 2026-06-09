import lexer.Token;
import parser.CompUnit;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.TreeSet;

public class InOut {
    private static final String inputPath = "testfile.txt";
    private static final String lexerPath = "lexer.txt";
    private static final String parsePath = "parser.txt";
    private static final String errorPath = "error.txt";

    public static String input() {
        try {
            return Files.readString(Paths.get(inputPath));
        } catch (IOException e) {
            System.out.println("Input Error");
            return null;
        }
    }

    public static void outputLexerAnswer(ArrayList<Token> tokens) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(lexerPath))) {
            for (Token token : tokens) {
                bw.write(token.toString());
                bw.newLine();
            }
        } catch (IOException e) {
            System.out.println("Output Error");
        }
    }

    public static void outputParseAnswer(CompUnit compUnit) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(parsePath))) {
            bw.write(compUnit.toString());
        } catch (IOException e) {
            System.out.println("Output Error");
        }
    }

    public static void outputError(TreeSet<Error> set) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(errorPath))) {
            for (Error error : set) {
                bw.write(error.toString());
                bw.newLine();
            }
        } catch (IOException e) {
            System.out.println("ErrorPut Error");
        }
    }
}
