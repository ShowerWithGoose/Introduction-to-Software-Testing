import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Compiler {
    public static void main(String[] args) throws IOException {
        String path1 = "testfile.txt";
        String path2 = "lexer.txt";
        String path3 = "parser.txt";
        String path4 = "error.txt";
        String string = null;
        try {
            string = new String(Files.readAllBytes(Paths.get(path1)));
        } catch (IOException e) {
            e.printStackTrace();
        }
        ArrayList<Token> tokens = new ArrayList<>();
        ArrayList<Error> errors = new ArrayList<>();
        Token token = null;
        MyLexer myLexer = new MyLexer(string, errors);
        while (myLexer.getPos() < string.length()) {
            token = myLexer.move();
            if (token != null) {
                tokens.add(token);
            }
        }
        MyParser myParser = new MyParser(tokens, errors);
        Node root = myParser.CompUnit();
        root.postrav(root);
        ArrayList<Node> nodes = root.getNodePost();
        Collections.sort(errors, new Comparator<Error>() {
            @Override
            public int compare(Error o1, Error o2) {
                return Integer.compare(o1.getLinenum(), o2.getLinenum());
            }
        });
        if (!errors.isEmpty()) {
            StringBuilder s = new StringBuilder();
            for (Error error : errors) {
                s.append(error + "\n");
            }
            try (FileOutputStream fos = new FileOutputStream(path4, false)) {
                byte[] bytesToWrite = s.toString().getBytes();
                fos.write(bytesToWrite);
            }
        }
        else {
            StringBuilder s = new StringBuilder();
            for (Node node : nodes) {
                s.append(node + "\n");
            }
            try (FileOutputStream fos = new FileOutputStream(path3, false)) {
                byte[] bytesToWrite = s.toString().getBytes();
                fos.write(bytesToWrite);
            }
        }
    }
}