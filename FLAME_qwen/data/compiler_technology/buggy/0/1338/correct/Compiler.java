import frontend.Lexer;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class Compiler {
    public static void main(String[] args) throws IOException {
        String filePath = "testfile.txt";
        List<String> input = null;
        try {
            input = Files.readAllLines(Paths.get(filePath));
//            for (String line : lines) {
//                System.out.println(line);
//            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        Lexer lexer = new Lexer((ArrayList)input);
        lexer.readLine();
//        try (BufferedReader reader = new BufferedReader(new FileReader(inputFile))) {
//            String line;
//            while ((line = reader.readLine()) != null) {
//                System.out.println(line);
//            }
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
    }
}
