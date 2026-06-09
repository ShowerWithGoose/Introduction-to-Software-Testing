package frontend.AST;

import frontend.LexType;
import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;

public class Number {
    private Token intConst;

    public Number(Token t) {
        intConst = t;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            Files.write(path, intConst.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            Files.write(path, "<Number>\n".getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
        }
        catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
