package frontend.AST.Decl;

import frontend.AST.Block;
import frontend.AST.Def.VarDef;
import frontend.LexType;
import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;

public class VarDecl {
    private Token BType;
    private ArrayList<VarDef> varDefArrayList = new ArrayList<>();
    private Token semicolon;

    public VarDecl(Token b,ArrayList<VarDef> list,Token s) {
        BType = b;
        varDefArrayList = list;
        semicolon = s;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            Files.write(path, BType.toString().getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
            varDefArrayList.get(0).postorder();
            for ( int i = 1;i < varDefArrayList.size();i++) {
                Token t = new Token(LexType.COMMA,1 ,",");
                Files.write(path, t.toString().getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
                varDefArrayList.get(i).postorder();
            }
            if (semicolon != null) {
                Files.write(path, semicolon.toString().getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
            }
            Files.write(path, "<VarDecl>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    //VarDecl â†’ BType VarDef { ',' VarDef } ';' // i
}
