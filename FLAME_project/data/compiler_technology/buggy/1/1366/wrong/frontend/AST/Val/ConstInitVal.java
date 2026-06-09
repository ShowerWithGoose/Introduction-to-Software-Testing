package frontend.AST.Val;

import frontend.AST.Exp.ConstExp;
import frontend.LexType;
import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;

public class ConstInitVal { //ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    private int type;
    //1
    private ConstExp singleConstExp = null;
    //2
    private ArrayList<ConstExp> constExpArrayList = new ArrayList<>();
    private Token lBrace = null;
    private Token rBrace = null;
    //3
    private Token stringConst = null;
    public ConstInitVal(Token stringConst) {
        type = 3;
        this.stringConst = stringConst;
    }

    public ConstInitVal(Token l,ArrayList<ConstExp> cExpList,Token r) {
        type = 2;
        lBrace = l;
        rBrace = r;
        constExpArrayList = cExpList;
    }
    public ConstInitVal(ConstExp cExp) {
        type = 1;
        singleConstExp = cExp;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            if (type == 1){
                singleConstExp.postorder();
            } else if (type == 2) {
                Files.write(path, lBrace.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                if (!constExpArrayList.isEmpty()) {
                    constExpArrayList.get(0).postorder();
                    //int lineNum = BType.getLineNum();
                    for (int i = 1; i < constExpArrayList.size(); i++) {
                        Token t = new Token(LexType.COMMA, 1, ",");
                        Files.write(path, t.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                        constExpArrayList.get(i).postorder();
                    }
                }
                Files.write(path, rBrace.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);

            } else if (type == 3) {
                Files.write(path, stringConst.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            }
            Files.write(path, "<ConstInitVal>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    //ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
}
