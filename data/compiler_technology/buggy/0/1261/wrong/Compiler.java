import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;
import frontend.Lexer;
import java.io.File;
public class Compiler {
    public static void main(String[] args) throws IOException {
        ArrayList<String> inputs = new ArrayList<>();
        File file = new File("testfile.txt");
        if (!file.exists())
            file.createNewFile();
        FileReader fr = new FileReader(file);
        BufferedReader inrd = new BufferedReader(fr);
        String str = "";
        while ((str = inrd.readLine()) != null) {
            inputs.add(str);
        }
        Lexer lexer = new Lexer(inputs);
        lexer.analyze();
        /* for (int i = 0;i < inputs.size();i++) {
            String line = inputs.get(i);
            int idx = 0;
            while (idx < line.length()) {
                idx++;
            }
            char ch = line.charAt(idx-1);
            System.out.print(ch);
        }*/
    }
}
