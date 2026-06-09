package tree;

import java.io.FileWriter;
import java.io.IOException;

public class Cond {
    private LOrExp lOrExp;

    public void setlOrExp(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    public void output(FileWriter fileWriter) throws IOException {
        lOrExp.output(fileWriter);
        fileWriter.write("<Cond>\n");
    }
}
