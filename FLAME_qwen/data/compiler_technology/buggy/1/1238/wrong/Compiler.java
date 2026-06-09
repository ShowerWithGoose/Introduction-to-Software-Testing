import frontend.Lexer;

import frontend.Parser;
import node.Node;
import token.Token;
import token.Type;
import error.Error;

import java.io.IOException;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PushbackReader;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) throws IOException {
        try {
            Lexer lexer = new Lexer("testfile.txt", "lexer.txt");
            lexer.parse();
            ArrayList<Token> tokens = lexer.getTokens();
            Parser parser = new Parser(tokens);
            parser.parse();
            Node root = parser.getRoot();
            List<String> nodeList = parser.inorder(root, new ArrayList<>());
            writeToFile("parser.txt", nodeList);
            List<Error> errorsFromParser = parser.getErrors();
            List<Error> errorsFromLexer = lexer.getErrors();
            List<String> errors = mergeErrors(errorsFromParser, errorsFromLexer);
            writeToFile("error.txt", errors);
        } catch (IOException e) {
            System.err.println("Error reading or writing files: " + e.getMessage());
        }

        // checkAndDeleteFiles(Paths.get("error.txt"), Paths.get("lexer.txt"));
        // Files.delete(Paths.get("lexer.txt"));
        // Files.delete(Paths.get("error1.txt"));
    }

    private static void checkAndDeleteFiles(Path errorFile, Path lexerFile) throws IOException {
        if (Files.exists(errorFile)) {
            long fileSize = Files.size(errorFile);
            if (fileSize == 0) {
                Files.delete(errorFile);
                System.out.println("Deleted error.txt because it was empty.");
            } else {
                Files.delete(lexerFile);
                System.out.println("Deleted lexer.txt because error.txt was not empty.");
            }
        } else {
            System.out.println("error.txt does not exist.");
        }
    }

    public static void writeToFile(String filename, List<String> content) throws IOException {
        Path path = Paths.get(filename);
        try (PrintWriter writer = new PrintWriter(path.toFile())) {
            for (Object node : content) {
                if (!Objects.equals(node.toString(), "")) {
                    // System.out.println(node);
                    writer.println(node);
                }
            }
        }
    }

    public static List<String> mergeErrors(List<Error> errors1, List<Error> errors2) {
        List<String> list = new ArrayList<>();
        int i = 0, j = 0;
        while (i < errors1.size() && j < errors2.size()) {
            if (errors1.get(i).getLine() < errors2.get(j).getLine()) {
                list.add(errors1.get(i).toString());
                i++;
            } else if (errors1.get(i).getLine() > errors2.get(j).getLine()) {
                list.add(errors2.get(j).toString());
                j++;
            } else {
                list.add(errors1.get(i).toString());
                i++;
                j++;
            }
        }
        while (i < errors1.size()) {
            list.add(errors1.get(i).toString());
            i++;
        }
        while (j < errors2.size()) {
            list.add(errors2.get(j).toString());
            j++;
        }
        return list;
    }

}