package frontend.AST;

import frontend.AST.Decl.Decl;
import frontend.AST.Def.FuncDef;
import frontend.AST.Def.MainFuncDef;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;

public class CompUnit {
    private String value = "<CompUnit>";
    private ArrayList<Decl> decls = new ArrayList<>();
    private ArrayList<FuncDef> funcDefs = new ArrayList<>();
    private MainFuncDef mainFuncDef;

    public CompUnit(ArrayList<Decl> decls, ArrayList<FuncDef> funcDefs, MainFuncDef mainFuncDef) {
        this.decls = decls;
        this.funcDefs = funcDefs;
        this.mainFuncDef = mainFuncDef;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        for (Decl d : decls) {
            d.postorder();
        }

        for (FuncDef f : funcDefs) {
            f.postorder();
        }
        mainFuncDef.postorder();
        try {
            Files.write(path, "<CompUnit>".getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
