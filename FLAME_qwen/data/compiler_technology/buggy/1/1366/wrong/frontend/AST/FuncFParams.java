package frontend.AST;

import frontend.LexType;
import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;

public class FuncFParams {
    private ArrayList<FuncFParam> fParams = new ArrayList<>();

    public FuncFParams(ArrayList<FuncFParam> fs) {
        fParams = fs;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            fParams.get(0).postorder();
            //int lineNum = BType.getLineNum();
            for (int i = 1 ; i < fParams.size() ; i++){
                Token t = new Token(LexType.COMMA,1 ,",");
                Files.write(path, t.toString().getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
                fParams.get(i).postorder();
            }
            Files.write(path, "<FuncFParams>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    //FuncFParams â†’ FuncFParam { ',' FuncFParam }
}
