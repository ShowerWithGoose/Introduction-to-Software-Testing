package frontend.AST.Exp;

import frontend.AST.FuncFParams;
import frontend.AST.FuncRParams;
import frontend.AST.UnaryOp;
import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;

public class UnaryExp {
    private int type;

    //type = 1
    private PrimaryExp primaryExp = null;

    //type = 2
    private Token iDent = null;
    private Token lParent = null;
    private Token rParent = null;
    private FuncRParams fParams  = null;

    //type = 3
    private UnaryOp unaryOp = null;
    private UnaryExp unaryExp = null;

    public UnaryExp(UnaryOp op,UnaryExp exp) {
        type = 3;
        unaryExp = exp;
        unaryOp = op;
    }
    public UnaryExp(PrimaryExp exp) {
        type = 1;
        primaryExp = exp;
    }

    public UnaryExp(Token i,Token l,FuncRParams fParams,Token r) {
        type = 2;
        iDent = i;
        lParent = l;
        rParent = r;
        this.fParams = fParams;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            if (type == 1){
                primaryExp.postorder();
            } else if (type == 2) {
                Files.write(path, iDent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                Files.write(path, lParent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                if (fParams != null) {
                    fParams.postorder();
                }
                if (rParent != null) {
                    Files.write(path, rParent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                }
            } else if (type == 3) {
                unaryOp.postorder();
                unaryExp.postorder();
            }
            Files.write(path, "<UnaryExp>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
