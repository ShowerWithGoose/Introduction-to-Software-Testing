package frontend.AST.Def;

import frontend.AST.Block;
import frontend.AST.FuncFParams;
import frontend.AST.FuncType;
import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;

public class FuncDef {
    private int type ;
    private FuncType funcType;
    private Token iDent;
    private Token lParent;
    private Token rParent = null;
    private FuncFParams funcFParams = null;
    private Block block ;
    public FuncDef(FuncType funcType,Token iDent,Token l,Token r,Block block) {
        type = 1;
        this.funcType = funcType;
        this.iDent = iDent;
        this.lParent = l;
        this.rParent = r;
        this.block = block;
    }
    public FuncDef(FuncType funcType,Token iDent,Token l,Token r,Block block,FuncFParams funcFParams) {
        type = 2;
        this.funcType = funcType;
        this.iDent = iDent;
        this.lParent = l;
        this.rParent = r;
        this.block = block;
        this.funcFParams = funcFParams;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            funcType.postorder();
            Files.write(path, iDent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            Files.write(path, lParent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            if (type == 2) {
                funcFParams.postorder();
            }
            if (rParent != null) {
                Files.write(path, rParent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            }
            block.postorder();
            Files.write(path, "<FuncDef>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    // FuncDef â†’ FuncType Ident '(' [FuncFParams] ')' Block // j
}
