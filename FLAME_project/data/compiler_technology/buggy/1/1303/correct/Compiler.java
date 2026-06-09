import frontend.Lexer.*;
import frontend.Parser.Parser;
import frontend.Wrong;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;


public class Compiler {
    public static void main(String[] args) throws FileNotFoundException {
        String rightOutputPath = "lexer.txt";
        String wrongOuputPath = "error.txt";
        ArrayList<Wrong> wrongs=new ArrayList<Wrong>();//错误

        InputStream in = new BufferedInputStream(new FileInputStream("testfile.txt"));
        Lexer lexer = new Lexer(in,wrongs);
        lexer.printTokens(rightOutputPath,wrongOuputPath);
        Parser parser = new Parser(lexer.tokens,wrongs);

        OutputStream out = new BufferedOutputStream(new FileOutputStream("error.txt"));
        PrintWriter writer = new PrintWriter(out);
        Collections.sort(wrongs, new Comparator<Wrong>() {
            @Override
            public int compare(Wrong w1, Wrong p2) {
                return Integer.compare(w1.errorLine, p2.errorLine);
            }
        });
        for(Wrong wrong : wrongs){
            writer.println(wrong.errorLine+" "+wrong.errorType);
        }
        writer.flush();
        writer.close();
    }
}
