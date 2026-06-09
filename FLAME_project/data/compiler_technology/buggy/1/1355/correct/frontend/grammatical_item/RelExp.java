package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class RelExp {
    public ArrayList<AddExp> addExps = new ArrayList<>();
    public ArrayList<String> RelOps = new ArrayList<>();

    public void print(FileWriter lw) throws IOException {
        addExps.get(0).print(lw);
        lw.write("<RelExp>\n");
        for(int i = 1;i < addExps.size();i++) {
            if(RelOps.get(i - 1).equals("<"))
                lw.write("LSS <\n");
            else if(RelOps.get(i - 1).equals(">"))
                lw.write("GRE >\n");
            else if(RelOps.get(i - 1).equals("<="))
                lw.write("LEQ <=\n");
            else if(RelOps.get(i - 1).equals(">="))
                lw.write("GEQ >=\n");
            addExps.get(i).print(lw);
            lw.write("<RelExp>\n");
        }
    }
}
