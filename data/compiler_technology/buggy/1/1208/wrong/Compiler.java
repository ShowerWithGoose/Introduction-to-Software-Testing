import frontend.Error;
import frontend.Lexer;
import frontend.Parser;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Map;
import java.util.TreeMap;

public class Compiler {

    public static void main(String[] args) {
        String path = "testfile.txt";
        try {
            String source = Files.readString(Paths.get(path));
            TreeMap<Integer, Character> errors = new TreeMap<>(); // 每一行最多只有一个错误
            Lexer lexer = new Lexer(source, errors);
            while (lexer.next());
            // lexer.output();
            Parser parser = new Parser(lexer.getTokenList(), errors);
            parser.output();
            File file = new File("error.txt");
            try {
                if (!file.exists()) {
                    Files.createFile(file.toPath());
                }
                try (FileOutputStream fos = new FileOutputStream(file, true)) {
                    for (Map.Entry<Integer, Character> entry : errors.entrySet()) {
                        String str = entry.getKey().toString() + " " + entry.getValue().toString() + '\n';
                        fos.write(str.getBytes());
                    }
                }
            } catch (IOException e) {
                e.printStackTrace();
                throw new RuntimeException("Error while writing to the file", e);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }
}
