package frontend.AST;

import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;

public class FuncFParam {
    private int type;
    // 1
    private Token BType;
    private Token iDent;
    // type = 2
    private Token lBracket = null;
    private Token rBracket = null;

    public FuncFParam(Token bType,Token i,Token l,Token r) {
        type = 1;
        BType = bType;
        iDent = i;
        lBracket = l;
        rBracket = r;
    }
    public FuncFParam(Token bType,Token i) {
        type = 2;
        BType = bType;
        iDent = i;
    }
    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            Files.write(path, BType.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            Files.write(path, iDent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            if (type == 1) {
                Files.write(path, lBracket.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                if (rBracket != null){
                    Files.write(path, rBracket.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                }
            }
            Files.write(path, "<FuncFParam>\n".getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    // FuncFParam â†’ BType Ident ['[' ']'] // k
}
