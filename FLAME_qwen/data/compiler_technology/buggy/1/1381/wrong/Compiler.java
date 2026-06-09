import frontend.Lexer;
import frontend.Parser;
import frontend.Token;
import error.Error;
import node.CompUnit;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class Compiler {
    public static final boolean DEBUG_MODE = true;
    public static final int HW_VERSION = 2;
    public static final String inputFilePath = "testfile.txt";
    private static Lexer lexer;
    private static Parser parser;

    public static void main(String[] args) {
        Scanner scanner;
        try {
            scanner = new Scanner(new File(inputFilePath));
        } catch (FileNotFoundException e) {
            if (DEBUG_MODE) { System.out.println("File not found"); }
            throw new RuntimeException(e);
        }
        lexer = new Lexer(scanner);
        parser = new Parser(lexer.getTokens());
        if (DEBUG_MODE) { lexer.printTokens(); }
        CompUnit compUnit = parser.parseCompUnit();
        if (DEBUG_MODE) { System.out.println(compUnit); }
        processHomeWork();
    }

    public static void processHomeWork() {
        switch (HW_VERSION) {
            case 1 -> {
                printLexerTokens();
                printLexerErrorList();
            }
            case 2 -> {
                printParserSyntax();
                printErrorList();
            }
            default -> System.out.println("Invalid homework version");
        }
    }

    public static void printLexerTokens() {
        HashMap<Integer, ArrayList<Token>> lexerTokens = lexer.getTokens();
        try (FileWriter writer = new FileWriter("lexer.txt")) {
            // System.out.println("line count: " + lexer.getLineCount());
            for (int i = 1; i <= lexer.getLineCount(); i++) {
                if (lexerTokens.containsKey(i)) {
                    ArrayList<Token> tokens = lexerTokens.get(i);
                    for (Token token : tokens) {
                        if (token.getType() != Token.TokenType.COMMENT
                                && token.getType() != Token.TokenType.ERROR
                                && token.getType() != Token.TokenType.EOF) {
                            try {
                                writer.write(token.toString());
                            } catch (IOException e) {
                                throw new RuntimeException(e);
                            }
                        }
                    }
                }
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void printLexerErrorList() {
        ArrayList<Error> errorList = lexer.getErrorList();
        try (FileWriter writer = new FileWriter("error.txt")) {
            for (Error error : errorList) {
                try {
                    writer.write(error.toString());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void printParserSyntax() {
        ArrayList<Object> syntaxList = parser.getSyntaxList();
        try (FileWriter writer = new FileWriter("parser.txt")) {
            for (Object obj : syntaxList) {
                String content = "";
                if (obj instanceof Token token) {
                    content = token.toString();
                } else if (obj instanceof Parser.SyntaxType objType) {
                    if (objType != Parser.SyntaxType.BType
                            && objType != Parser.SyntaxType.BlockItem
                            && objType != Parser.SyntaxType.Decl){
                        content = "<" + obj + ">\n";
                    }
                }
                try {
                    writer.write(content);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void printErrorList() {
        ArrayList<Error> errorList = new ArrayList<>();
        errorList.addAll(lexer.getErrorList());
        errorList.addAll(parser.getErrorList());

        errorList.sort(Comparator.comparingInt((Error e) -> e.getLineNum()));

        try (FileWriter writer = new FileWriter("error.txt")) {
            for (Error error : errorList) {
                try {
                    writer.write(error.toString());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}