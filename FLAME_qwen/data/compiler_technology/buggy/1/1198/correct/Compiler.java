import frontend.Lexer;
import frontend.Lexer_out;
import frontend.Parser;
import frontend.WrongExample;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class Compiler {
    public static void main(String[] arg) {

        Lexer.run();
        Parser.run();
        ArrayList<WrongExample> w = Lexer.getWs();
        w.addAll(Parser.getW());
        w.sort(Comparator.comparingInt(WrongExample::getLine_num));
        FileReader f = null;
        try {
            FileWriter error = new FileWriter("error.txt");
            for (WrongExample x : w) {
                error.write(x.getLine_num() + " " + x.getType() + "\n");
                error.flush();
            }
        } catch (IOException e) {
            //System.out.println("wrong!!!");
            e.printStackTrace();
        }
    }
}