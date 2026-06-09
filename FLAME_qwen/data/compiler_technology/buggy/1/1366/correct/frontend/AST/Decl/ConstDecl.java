package frontend.AST.Decl;

import frontend.AST.Def.ConstDef;
import frontend.LexType;
import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;

public class ConstDecl {
    private Token Const;
    private Token BType;
    private ArrayList<ConstDef> constDefArrayList = new ArrayList<>();
    private Token semicolon;

    public ConstDecl(Token aConst,Token bType,ArrayList<ConstDef> list,Token s) {
        Const = aConst;
        BType = bType;
        constDefArrayList = list;
        semicolon = s;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            Files.write(path, Const.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            Files.write(path, BType.toString().getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
            constDefArrayList.get(0).postorder();
            //int lineNum = BType.getLineNum();
            for (int i = 1 ; i < constDefArrayList.size() ; i++){
                Token t = new Token(LexType.COMMA,1 ,",");
                Files.write(path, t.toString().getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
                constDefArrayList.get(i).postorder();
            }
            if (semicolon!=null){
                Files.write(path, semicolon.toString().getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
            }
            Files.write(path, "<ConstDecl>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    //ConstDecl â†’ 'const' BType ConstDef { ',' ConstDef } ';' // i
}
