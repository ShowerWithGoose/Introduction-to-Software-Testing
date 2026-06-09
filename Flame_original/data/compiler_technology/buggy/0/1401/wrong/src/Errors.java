package src;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Errors {
    private ArrayList<Error> errors=new ArrayList<>();

    public void add(Error error){
        errors.add(error);
    }
    public boolean error(){
        return errors.isEmpty();
    }
    public void word() throws IOException {
        File writename = new File("error.txt");
        writename.createNewFile();
        BufferedWriter out = new BufferedWriter(new FileWriter(writename));
        int i;
        for (i = 0; i < errors.size() - 1; i++) {
            errors.get(i).word(out);
            System.out.println();
        }
        errors.get(i).word(out);
        out.flush();
        out.close();
    }
}
