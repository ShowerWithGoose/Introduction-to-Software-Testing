package frontend.AST.Val;

import frontend.AST.Exp.ConstExp;
import frontend.AST.Exp.Exp;
import frontend.LexType;
import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;

public class InitVal {
    private int type;

    //type = 1
    private Exp exp;
    //type = 2
    private Token lBrace;
    private Token rBrace;
    private ArrayList<Exp> expressions;

    //type = 3
    private Token stringConst;

    public InitVal(Token stringConst) {
        type = 3;
        this.stringConst = stringConst;
    }

    public InitVal(Token l, ArrayList<Exp> cExpList, Token r) {
        type = 2;
        lBrace = l;
        rBrace = r;
        expressions = cExpList;
    }
    public InitVal(Exp exp1) {
        type = 1;
        exp = exp1;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            if (type == 1){
                exp.postorder();
            } else if (type == 2) {
                Files.write(path, lBrace.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                if (!expressions.isEmpty()) {
                    expressions.get(0).postorder();
                    //int lineNum = BType.getLineNum();
                    for (int i = 1; i < expressions.size(); i++) {
                        Token t = new Token(LexType.COMMA, 1, ",");
                        Files.write(path, t.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                        expressions.get(i).postorder();
                    }
                }
                Files.write(path, rBrace.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);

            } else if (type == 3) {
                Files.write(path, stringConst.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            }
            Files.write(path, "<InitVal>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }
    //InitVal â†’ Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
}

