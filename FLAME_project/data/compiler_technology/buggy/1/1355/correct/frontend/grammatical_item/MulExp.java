package frontend.grammatical_item;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class MulExp {
    public ArrayList<UnaryExp> unaryExps = new ArrayList<>();
    public ArrayList<String> MulOps = new ArrayList<>();

    public void print(FileWriter lw) throws IOException {
        unaryExps.get(0).print(lw);
        lw.write("<MulExp>\n");
        for(int i = 1;i < unaryExps.size();i++) {
            if(MulOps.get(i - 1).equals("*"))
                lw.write("MULT *\n");
            else if(MulOps.get(i - 1).equals("/"))
                lw.write("DIV /\n");
            else if(MulOps.get(i - 1).equals("%"))
                lw.write("MOD %\n");
            unaryExps.get(i).print(lw);
            lw.write("<MulExp>\n");
        }
    }
}
