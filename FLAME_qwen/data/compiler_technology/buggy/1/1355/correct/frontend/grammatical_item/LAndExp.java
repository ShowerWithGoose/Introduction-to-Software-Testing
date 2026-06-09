package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class LAndExp {
    public ArrayList<EqExp> eqExps = new ArrayList<>();
    public ArrayList<String> LAndOps = new ArrayList<>();

    public void print(FileWriter lw) throws IOException {
        eqExps.get(0).print(lw);
        lw.write("<LAndExp>\n");
        for(int i = 1;i < eqExps.size();i++) {
            if(LAndOps.get(i - 1).equals("&&"))
                lw.write("AND &&\n");
            eqExps.get(i).print(lw);
            lw.write("<LAndExp>\n");
        }
    }
}
