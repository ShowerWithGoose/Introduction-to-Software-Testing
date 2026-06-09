package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class EqExp {
    public ArrayList<RelExp> relExps = new ArrayList<>();
    public ArrayList<String> EqOps = new ArrayList<>();

    public void print(FileWriter lw) throws IOException {
        relExps.get(0).print(lw);
        lw.write("<EqExp>\n");
        for(int i = 1;i < relExps.size();i++) {
            if(EqOps.get(i - 1).equals("=="))
                lw.write("EQL ==\n");
            else if(EqOps.get(i - 1).equals("!="))
                lw.write("NEQ !=\n");
            relExps.get(i).print(lw);
            lw.write("<EqExp>\n");
        }
    }
}
