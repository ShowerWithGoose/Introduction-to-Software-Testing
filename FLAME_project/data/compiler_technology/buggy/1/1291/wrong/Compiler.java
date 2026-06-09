import common.Error;
import common.ParseTree;
import exceptions.FatalErrorException;
import frontend.Lexer;
import frontend.Parser;
import frontend.Token;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Compiler {
    private static ArrayList<Token> tokens;
    private static ParseTree parseTree;
    private static final ArrayList<Error> errors = new ArrayList<>();
    public static void main(String[] args) {
        String rawFile = readFile();

        try {
            tokens = Lexer.lex(rawFile, errors);
        } catch (FatalErrorException e) {
            handleException(e);
        }

        parseTree = Parser.parse(tokens, errors);

        //for lexer
        dumpLexResult();

        //for parser
            //debugging
        parseTree.debugPrint("", true);
        dumpParseResult();

        //the end of compiling process
        dumpError();
    }

    public static void handleException(FatalErrorException e) {
        System.out.println(e.toString());
        System.exit(0);
    }

    public static String readFile() {
        try {
            return Files.readString(Paths.get("testfile.txt"))/*.replace("\r\n", "\n")*/;
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public static void dumpLexResult() {
        String lexFilePath = "lexer.txt";
        List<String> tokenLines = new ArrayList<>();
        for (Token token: tokens) {
            tokenLines.add(token.toString());
        }
        try {
            Files.write(Paths.get(lexFilePath), tokenLines);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void dumpParseResult() {
        String parseFilePath = "parser.txt";
        List<String> nodeLines = Parser.traversalParseTree(parseTree);
        try {
            Files.write(Paths.get(parseFilePath), nodeLines);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void dumpError() {
        String errFilePath = "error.txt";
        List<String> errorLines = new ArrayList<>();

        for (Error error: errors) {
            errorLines.add(error.toString());
        }
        Collections.sort(errorLines);
        try {
            Files.write(Paths.get(errFilePath), errorLines);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
