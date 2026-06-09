package frontend.AST.Exp;

import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;

public class RelExp {
    private int type;
    //1
    private AddExp addExp;
    //2
    private RelExp relExp;
    private Token compare_sign;

    public RelExp(AddExp addExp1) {
        type = 1;
        addExp = addExp1;
    }
    public RelExp(AddExp addExp1,RelExp relExp1,Token t) {
        type = 2;
        addExp = addExp1;
        relExp = relExp1;
        compare_sign = t;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            if (type == 2){
                relExp.postorder();
                Files.write(path, compare_sign.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            }
            addExp.postorder();
            Files.write(path, "<RelExp>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
