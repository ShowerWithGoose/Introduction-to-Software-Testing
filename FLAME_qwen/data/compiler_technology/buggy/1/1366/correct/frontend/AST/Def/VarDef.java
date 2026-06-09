package frontend.AST.Def;

import frontend.AST.Exp.ConstExp;
import frontend.AST.Val.ConstInitVal;
import frontend.AST.Val.InitVal;
import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;

public class VarDef {
    private int type;
    //1
    private Token iDent;
    private Token lBracken;
    private Token rBracken;
    private ConstExp exp;
    //2
    private Token equal_sign;
    private InitVal initVal;

    // VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k
    //1 Ident
    //2 Ident '[' ConstExp ']'
    //3 Ident '=' InitVal
    //4 Ident '[' ConstExp ']' '=' InitVal
    public VarDef(Token IDent, Token l, ConstExp cExp, Token r, Token eq, InitVal InitVal) {
        iDent = IDent;
        lBracken = l;
        rBracken = r;
        exp = cExp;
        equal_sign = eq;
        initVal = InitVal;
        if (l == null && eq == null) {
            type = 1;
        } else if (l != null && eq == null) {
            type = 2;
        } else if (l == null && eq != null) {
            type = 3;
        } else {
            type = 4;
        }

    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            Files.write(path, iDent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            if (lBracken != null){
                Files.write(path, lBracken.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                exp.postorder();
                Files.write(path, rBracken.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            }
            if (equal_sign != null) {
                Files.write(path, equal_sign.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                initVal.postorder();
            }
            Files.write(path, "<VarDef>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    //VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k
}
