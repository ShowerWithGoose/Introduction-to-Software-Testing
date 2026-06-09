package frontend.AST;

import frontend.LexType;
import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;

public class FuncType {
    private int type;
    private Token funcType;// int|void|char

    public FuncType(Token token) {
        funcType = token;
        if (token.getLexType() == LexType.VOIDTK) {
            type = 2;
        } else {
            type = 1;
        }
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            Files.write(path, funcType.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            Files.write(path, "<FuncType>\n".getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
