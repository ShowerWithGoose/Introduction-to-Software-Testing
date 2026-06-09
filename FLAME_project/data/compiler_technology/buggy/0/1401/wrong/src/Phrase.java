
package src;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Phrase {
    private ArrayList<Class> classes=new ArrayList<>();

    public void addclass(Class cl){
        classes.add(cl);
    }

    public void word() throws IOException {
        File writename = new File("lexer.txt");
        writename.createNewFile();
        BufferedWriter out = new BufferedWriter(new FileWriter(writename));
        int i=0;
        for (i = 0; i < classes.size() - 1; i++) {
            classes.get(i).word(out);
            out.write("\n");
        }
        classes.get(i).word(out);
        out.flush();
        out.close();
    }
}
