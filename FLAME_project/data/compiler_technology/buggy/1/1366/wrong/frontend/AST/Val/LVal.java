package frontend.AST.Val;

import frontend.AST.Exp.Exp;
import frontend.LexType;
import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;

public class LVal {
    private int type;
    //1
    private Token iDent;
    //2
    private Token lBracket;
    private Token rBracket;
    private Exp exp;
    public LVal(Token i) {
        type = 1;
        iDent = i;
    }

    public LVal(Token i,Token l,Exp e,Token r) {
        type = 2;
        iDent = i;
        lBracket = l;
        rBracket = r;
        exp = e;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            if (type == 1){
                Files.write(path, iDent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            } else if (type == 2) {
                Files.write(path, iDent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                Files.write(path, lBracket.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                exp.postorder();
                if (rBracket != null) {
                    Files.write(path, rBracket.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                }
            }
            Files.write(path, "<LVal>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    //LVal â†’ Ident ['[' Exp ']'] // k
}
