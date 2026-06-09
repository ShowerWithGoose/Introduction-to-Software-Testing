package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ConstDecl {
    private Token con;
    private BType bType;
    private ArrayList<ConstDef> constDefs = new ArrayList<>();
    private Token semicn;

    public void setCon(Token con) {
        this.con = con;
    }

    public void setBType(BType bType) {
        this.bType = bType;
    }

    public void setSemicn(Token semicn) {
        this.semicn = semicn;
    }

    public void addConstDef(ConstDef constDef) {
        constDefs.add(constDef);
    }

    public void output(FileWriter fileWriter) throws IOException {
        fileWriter.write(con.toString() + "\n");
        bType.output(fileWriter);
        for (int i = 0;i < constDefs.size() - 1;i++) {
            constDefs.get(i).output(fileWriter);
            fileWriter.write("COMMA ,\n");
        }
        constDefs.get(constDefs.size() - 1).output(fileWriter);
        fileWriter.write(semicn.toString() + "\n");
        fileWriter.write("<ConstDecl>\n");
    }

}
