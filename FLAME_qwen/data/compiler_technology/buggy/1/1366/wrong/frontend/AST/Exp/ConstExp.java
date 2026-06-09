package frontend.AST.Exp;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;

public class ConstExp {
    private AddExp addExp;
    public ConstExp(AddExp exp) {
        addExp = exp;
    }

    public void postorder() {
        addExp.postorder();
        Path path = Paths.get("parser.txt");
        try {
            Files.write(path, "<ConstExp>\n".getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
