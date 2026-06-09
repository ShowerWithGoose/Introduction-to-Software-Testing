import frontend.lexer.Lexer;
import frontend.parser.CompUnit;
import frontend.parser.Parser;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;

public class Compiler {
    public static void main(String[] args) throws IOException {
        File input = new File("testfile.txt");
        String content = Files.readString(input.toPath());
        Lexer lexer = new Lexer(content);
        Parser parser = new Parser(lexer);
        CompUnit compUnit = parser.parseCompUnit();
        File output = new File("parser.txt");
        if (!output.exists()) {
            output.createNewFile();
        }
        File error = new File("error.txt");
        if (!error.exists()) {
            error.createNewFile();
        }
        FileWriter fw1 = new FileWriter(output, false);
        FileWriter fw2 = new FileWriter(error, false);
        fw1.write(compUnit.getOutPut());
        fw2.write(compUnit.getError());
        fw1.close();
        fw2.close();
    }
}
