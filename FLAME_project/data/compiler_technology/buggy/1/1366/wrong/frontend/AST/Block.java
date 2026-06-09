package frontend.AST;

import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;

public class Block {
    private Token lBrace;
    private Token rBrace;
    private ArrayList<BlockItem> blockItems;

    public Block(Token l,Token r,ArrayList<BlockItem> b) {
        lBrace = l;
        rBrace = r;
        blockItems = b;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
                Files.write(path, lBrace.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                for (BlockItem b : blockItems) {
                    b.postorder();
                }
            Files.write(path, rBrace.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
            Files.write(path, "<Block>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
