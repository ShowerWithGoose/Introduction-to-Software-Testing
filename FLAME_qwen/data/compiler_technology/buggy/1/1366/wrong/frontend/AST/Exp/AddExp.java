package frontend.AST.Exp;

import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;

public class AddExp {
    private MulExp mulExp;
    private AddExp addExp;
    private Token addOrMinus;
    public AddExp(MulExp exp) {
        mulExp = exp;
        addExp = null;
        addOrMinus = null;
    }
    public AddExp(MulExp mulExp1,AddExp addExp1,Token t) {
        mulExp = mulExp1;
        addExp = addExp1;
        addOrMinus = t;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            if (addExp != null){
                addExp.postorder();
                Files.write(path, addOrMinus.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            }
            mulExp.postorder();
            Files.write(path, "<AddExp>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    //AddExp → MulExp | AddExp ('+' | '−') MulExp
}
