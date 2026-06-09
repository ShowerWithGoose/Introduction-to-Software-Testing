import frontend.Token;
import frontend.TokenLexer;
import frontend.readfile;


import java.awt.*;
import java.io.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Compiler {
    public static void main(String[] args) {
//        String regex = "^('([ !#$%&()*+,\\-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ\\]\\[^_abcdefghijklmnopqrstuvwxyz{|}~])'|'(\\\\[\\\\abtn\"vf'0])')";
//        String test = "'\\0';";
//        Pattern pattern = Pattern.compile(regex);
//        Matcher matcher = pattern.matcher(test);
//        System.out.println(matcher.find());
//        System.out.println(matcher.start());

        InputStream in = null;
        try {
            in = new FileInputStream("testfile.txt");
        } catch (FileNotFoundException e) {
            System.err.println("File not found");
        }
        readfile rf = new readfile(in);
        //System.out.println(rf.contents);
        TokenLexer lexer = new TokenLexer(rf);
        try {
            OutputStream out = new FileOutputStream("lexer.txt");
            try {
                for (Token t : lexer.tokens) {
                    out.write((t.type + " " + t.content + "\n").getBytes());
                }
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        try {
            OutputStream out = new FileOutputStream("error.txt");
            try {
                for (Token t : lexer.error_tokens) {
                    out.write(((t.linenum + 1) + " " + "a" + "\n").getBytes());
                }
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
