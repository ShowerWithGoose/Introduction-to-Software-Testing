package frontend.AST.Exp;

import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;

public class LAndExp {
    private int type;
    //1
    private EqExp eqExp;
    //2
    private LAndExp lAndExp = null;
    private Token And;

    public LAndExp(EqExp exp) {
        type = 1;
        eqExp = exp;
    }

    public LAndExp(EqExp exp,LAndExp lAndExp1,Token t) {
        type = 2;
        eqExp = exp;
        lAndExp = lAndExp1;
        And = t;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            if (lAndExp != null){
                lAndExp.postorder();
                Files.write(path,And.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            }
            eqExp.postorder();
            Files.write(path, "<LAndExp>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
