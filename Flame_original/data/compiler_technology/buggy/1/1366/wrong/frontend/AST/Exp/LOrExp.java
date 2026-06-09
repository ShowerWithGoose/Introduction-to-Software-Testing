package frontend.AST.Exp;

import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;

public class LOrExp {
    private int type;
    //1
    private LAndExp lAndExp;
    //2
    private LOrExp lOrExp;
    private Token or;
    public LOrExp(LAndExp exp) {
        type = 1;
        lAndExp = exp;
        lOrExp = null;
        or = null;
    }
    public LOrExp(LAndExp exp,LOrExp lOrExp1,Token t) {
        type = 2;
        lAndExp = exp;
        lOrExp = lOrExp1;
        or = t;
    }
    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            if (type == 2){
                lOrExp.postorder();
                Files.write(path, or.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            }
            lAndExp.postorder();
            Files.write(path, "<LOrExp>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
