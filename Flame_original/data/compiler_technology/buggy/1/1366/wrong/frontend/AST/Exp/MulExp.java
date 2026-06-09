package frontend.AST.Exp;

import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;

public class MulExp {
    private UnaryExp unaryExp;
    private MulExp mulExp = null;
    private Token opCode; //'*' | '/' | '%'
    public MulExp(UnaryExp exp) {
        unaryExp = exp;
        mulExp = null;
        opCode = null;
    }
    public MulExp(UnaryExp unaryExp1,MulExp mulExp1,Token t) {
        mulExp = mulExp1;
        unaryExp = unaryExp1;
        opCode = t;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            if (mulExp != null){
                mulExp.postorder();
                Files.write(path, opCode.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            }
            unaryExp.postorder();
            Files.write(path, "<MulExp>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
