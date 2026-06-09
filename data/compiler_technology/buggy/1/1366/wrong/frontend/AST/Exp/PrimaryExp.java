package frontend.AST.Exp;

import frontend.AST.Character;
import frontend.AST.Number;
import frontend.AST.UnaryOp;
import frontend.AST.Val.LVal;
import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;

public class PrimaryExp {
    private int type;

    //type = 1
    private Exp exp = null;
    private Token lParent = null;
    private Token rParent = null;

    //type = 2
    private LVal lVal = null;

    //type = 3
    private Number number = null;

    //type = 4
    private Character character = null;

    public PrimaryExp(Token l,Exp e,Token r){
        type = 1;
        lParent = l;
        rParent = r;
        exp = e;
    }

    public PrimaryExp(LVal lVal1) {
        type = 2;
        lVal = lVal1;
    }

    public PrimaryExp(Number num) {
        type = 3;
        number = num;
    }

    public PrimaryExp(Character c) {
        type = 4;
        character = c;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            if (type == 1){
                Files.write(path, lParent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                exp.postorder();
                if (rParent != null) {
                    Files.write(path, rParent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                }
            } else if (type == 2) {
                lVal.postorder();
            } else if (type == 3) {
                number.postorder();
            } else {
                character.postorder();
            }
            Files.write(path, "<PrimaryExp>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
