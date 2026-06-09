package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;
import java.security.PublicKey;
import java.util.ArrayList;

public class AddExp {
    public ArrayList<MulExp> mulExps = new ArrayList<>();
    public ArrayList<String> AddOps = new ArrayList<>();

    public void print(FileWriter lw) throws IOException {
        mulExps.get(0).print(lw);
        lw.write("<AddExp>\n");
        for(int i = 1;i < mulExps.size();i++) {
            if(AddOps.get(i - 1).equals("+"))
                lw.write("PLUS +\n");
            else if(AddOps.get(i - 1).equals("-"))
                lw.write("MINU -\n");
            mulExps.get(i).print(lw);
            lw.write("<AddExp>\n");
        }
    }
}
