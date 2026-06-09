package frontend.AST.Exp;

import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;

public class EqExp {
    private int type;
    private RelExp relExp;
    private Token equal_NotEqual;
    private EqExp eqExp = null;

    public EqExp(RelExp exp) {
        type = 1;
        relExp = exp;
    }
    public EqExp(RelExp exp,EqExp eqExp1,Token t) {
        type = 2;
        relExp = exp;
        equal_NotEqual = t;
        eqExp = eqExp1;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            if (eqExp != null){
                eqExp.postorder();
                Files.write(path, equal_NotEqual.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            }
            relExp.postorder();
            Files.write(path, "<EqExp>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    //EqExp â†’ RelExp | EqExp ('==' | '!=') RelExp
}
