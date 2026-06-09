
import src.State1;

import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Compiler {
    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner(new FileReader("testfile.txt"));
        String string=scanner.useDelimiter("\\A").next();
        /*Scanner s = new Scanner(System.in).useDelimiter("\\A");
        String string = s.hasNext() ? s.next() : "";*/
        State1 state1=new State1(string);
        state1.work();
    }
}