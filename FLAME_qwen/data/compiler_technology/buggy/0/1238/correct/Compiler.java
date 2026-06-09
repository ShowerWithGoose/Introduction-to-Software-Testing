import frontend.Lexer;

import java.io.IOException;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class Compiler {
    public static void main(String[] args) throws IOException {
        try {
            Lexer lexer = new Lexer("testfile.txt", "lexer.txt", "error.txt");
            lexer.parse();
        } catch (IOException e) {
            System.err.println("Error reading or writing files: " + e.getMessage());
        }

        checkAndDeleteFiles(Paths.get("error.txt"), Paths.get("lexer.txt"));
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
}