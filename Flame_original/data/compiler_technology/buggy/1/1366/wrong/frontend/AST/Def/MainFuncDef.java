package frontend.AST.Def;

import frontend.AST.Block;
import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;

public class MainFuncDef {
    private Token token_int;
    private Token token_main;
    private Token lParent;
    private Token rParent;
    private Block block;
    private String value = "MainFuncDef";

    public MainFuncDef(Token t_int,Token t_main,Token l,Token r,Block b) {
        token_int = t_int;
        token_main = t_main;
        lParent = l;
        rParent = r;
        block = b;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            Files.write(path, token_int.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            Files.write(path, token_main.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            Files.write(path, lParent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            if (rParent != null)
            {Files.write(path, rParent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);}
            block.postorder();
            Files.write(path, "<MainFuncDef>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    //MainFuncDef â†’ 'int' 'main' '(' ')' Block // j
}
