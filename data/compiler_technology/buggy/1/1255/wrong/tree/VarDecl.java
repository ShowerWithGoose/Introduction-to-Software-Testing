package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class VarDecl {
    private BType bType;
    private ArrayList<VarDef> varDefs = new ArrayList<>();
    private Token semicn;

    public void setBType(BType bType) {
        this.bType = bType;
    }

    public void setSemicn(Token semicn) {
        this.semicn = semicn;
    }

    public void addVarDef(VarDef varDef) {
        varDefs.add(varDef);
    }

    public void output(FileWriter fileWriter) throws IOException {
        bType.output(fileWriter);
        for (int i = 0;i < varDefs.size() - 1;i++) {
            varDefs.get(i).output(fileWriter);
            fileWriter.write("COMMA ,\n");
        }
        varDefs.get(varDefs.size() - 1).output(fileWriter);
        fileWriter.write(semicn.toString() + "\n");
        fileWriter.write("<VarDecl>\n");
    }

}
