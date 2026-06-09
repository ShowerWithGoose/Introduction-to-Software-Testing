import frontend.Lexer;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Compiler {
    public static void main(String[] args) {
        List<String> inputLines = new ArrayList<>();

        try {
            BufferedReader in = new BufferedReader(new FileReader("testfile.txt"));
            String line;
            while ((line = in.readLine()) != null) {
                inputLines.add(line);
            }
            Lexer lexer = new Lexer(inputLines);
            lexer.analyze();
            in.close();
        } catch (Exception ignored) {
        }
    }
}
