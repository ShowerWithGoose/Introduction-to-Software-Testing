package frontend.AST;

import frontend.AST.Decl.Decl;
import frontend.AST.Def.FuncDef;
import frontend.AST.Exp.LOrExp;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;

public class Cond {
    private LOrExp lOrExp;

    public Cond(LOrExp exp) {
        lOrExp = exp;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        lOrExp.postorder();
        try {
            Files.write(path, "<Cond>\n".getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
