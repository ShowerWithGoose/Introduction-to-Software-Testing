import java.io.BufferedWriter;
import java.io.FileOutputStream;

import java.io.IOException;

public class Compiler {
    public static void main(String[] args) throws IOException {
        Lexer lexer = new Lexer("testfile.txt");

        //BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
        int errflag = 0;
        String corinfo = "";
        while (lexer.getType() != Type.EOF) {
            lexer.next();
            if (lexer.getType() != Type.ERR && lexer.getType() != Type.EOF) {
                //out.write(lexer.getType().toString() + " " + lexer.getToken() + "\n");
                corinfo = corinfo + lexer.getType().toString() + " " + lexer.getToken() + "\n";
            }
            if (lexer.getType() == Type.ERR) {
                errflag = 1;
            }
        }
        if (errflag == 1) {
            FileOutputStream out = new FileOutputStream("error.txt");
            out.write(lexer.geterrinfo().getBytes());
            out.close();
        } else {
            FileOutputStream out = new FileOutputStream("lexer.txt");
            out.write(corinfo.getBytes());
            out.close();
        }
    }
}