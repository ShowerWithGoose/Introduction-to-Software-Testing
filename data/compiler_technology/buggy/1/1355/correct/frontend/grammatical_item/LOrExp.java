package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class LOrExp {
    public ArrayList<LAndExp> lAndExps = new ArrayList<>();
    public ArrayList<String> LOrOps = new ArrayList<>();

    public void print(FileWriter lw) throws IOException {
        lAndExps.get(0).print(lw);
        lw.write("<LOrExp>\n");
        for(int i = 1;i < lAndExps.size();i++) {
            if(LOrOps.get(i - 1).equals("||"))
                lw.write("OR ||\n");
            lAndExps.get(i).print(lw);
            lw.write("<LOrExp>\n");
        }
    }
}
