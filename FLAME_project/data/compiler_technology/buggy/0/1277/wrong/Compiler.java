import fronted.Lexer;
import fronted.Token;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

public class Compiler {
    public static void main(String[] args) {
        String inFlie = "testfile.txt";
        String outFlie = "lexer.txt";
        String errFlie = "error.txt";
        Lexer lexer = new Lexer(inFlie);
        if (lexer.isError()) {
            writeError(lexer, errFlie);
        } else {
            writeLexer(lexer, outFlie);
        }
    }

    private static void writeError(Lexer lexer, String errFlie) {
        try {
            File file = new File(errFlie);
            if (!file.exists()) {
                file.createNewFile();
            }
            FileOutputStream fos = new FileOutputStream(file);
            String out = lexer.getCurLine() + " a";
            fos.write(out.getBytes());
            fos.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void writeLexer(Lexer lexer, String outFile) {
        try {
            File file = new File(outFile);
            if (!file.exists()) {
                file.createNewFile();
            }
            FileOutputStream fos = new FileOutputStream(file);
            Token token;
            while ((token = lexer.nextToken()) != null) {
                String out = token.getType() + " " + token.getValue() + '\n';
                fos.write(out.getBytes());
            }
            fos.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
