package frontend.AST;

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

public class FuncRParams {
    private ArrayList<Exp> expArrayList = new ArrayList<>();

    public FuncRParams(ArrayList<Exp> expList) {
        expArrayList = expList;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            expArrayList.get(0).postorder();
            //int lineNum = BType.getLineNum();
            for (int i = 1 ; i < expArrayList.size() ; i++){
                Token t = new Token(LexType.COMMA,1 ,",");
                Files.write(path, t.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                expArrayList.get(i).postorder();
            }
            Files.write(path, "<FuncRParams>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    //FuncRParams â†’ Exp { ',' Exp }
}
