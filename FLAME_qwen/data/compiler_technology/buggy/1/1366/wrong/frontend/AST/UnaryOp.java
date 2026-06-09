package frontend.AST;

import frontend.AST.Exp.PrimaryExp;
import frontend.AST.Exp.UnaryExp;
import frontend.LexType;
import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;

public class UnaryOp {
    private int type;

    //type = 1
    private Token plus;

    //type = 2
    private Token minus;

    //type = 3
    private Token not;

    private Token t;

    public UnaryOp(Token t1) {
        t = t1;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            Files.write(path, t.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            Files.write(path, "<UnaryOp>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

}
