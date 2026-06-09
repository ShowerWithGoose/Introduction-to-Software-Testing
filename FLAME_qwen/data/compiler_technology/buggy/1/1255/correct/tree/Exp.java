package tree;

import java.io.FileWriter;
import java.io.IOException;

public class Exp {
    private AddExp addExp;

    public void setAddExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public void output(FileWriter fileWriter) throws IOException {
        addExp.output(fileWriter);
        fileWriter.write("<Exp>\n");
    }
}
