package frontend.AST.Def;

import frontend.AST.Val.ConstInitVal;
import frontend.AST.Exp.ConstExp;
import frontend.LexType;
import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;

public class ConstDef {
    private int type;
    private Token iDent;
    //1
    private Token lBracken = null;
    private ConstExp constExp = null;
    private Token rBracken = null;
    //2
    private Token equal_sign;
    private ConstInitVal constInitVal;

    public ConstDef(Token IDent,Token l,ConstExp cExp,Token r,Token eq,ConstInitVal cInitVal) {
        if (cExp == null) type = 1;
        else type = 2;
        iDent = IDent;
        lBracken = l;
        rBracken = r;
        constExp = cExp;
        equal_sign = eq;
        constInitVal = cInitVal;
    }
    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            Files.write(path, iDent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            if (type == 2) {
                Files.write(path, lBracken.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                constExp.postorder();
                Files.write(path, rBracken.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            }
            Files.write(path, equal_sign.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            constInitVal.postorder();
            Files.write(path, "<ConstDef>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }
    //ConstDef â†’ Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
}
