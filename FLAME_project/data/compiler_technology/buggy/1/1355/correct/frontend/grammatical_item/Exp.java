package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;

public class Exp {
    public AddExp addExp;

    public void print(FileWriter lw) throws IOException {
        if(addExp != null)
            addExp.print(lw);
        lw.write("<Exp>\n");
    }
}
