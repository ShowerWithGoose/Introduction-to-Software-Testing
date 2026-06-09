package frontend.AST;

import frontend.AST.Decl.Decl;
import frontend.AST.Def.FuncDef;
import frontend.AST.Exp.Exp;
import frontend.AST.Val.LVal;
import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;

public class ForStmt {
    private LVal lVal;
    private Token equal_sign;
    private Exp exp;

    public ForStmt(LVal lVal1,Token t,Exp exp1) {
        lVal = lVal1;
        equal_sign = t;
        exp = exp1;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            lVal.postorder();;
            Files.write(path, equal_sign.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            exp.postorder();
            Files.write(path, "<ForStmt>\n".getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
