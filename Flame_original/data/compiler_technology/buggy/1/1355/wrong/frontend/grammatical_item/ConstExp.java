package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;

public class ConstExp {
    public AddExp addExp;

    public void print(FileWriter lw) throws IOException {
        addExp.print(lw);
        lw.write("<ConstExp>\n");
    }
}
