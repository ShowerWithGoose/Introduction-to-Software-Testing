import java.io.*;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) throws IOException {
        Compiler.read("testfile.txt");
    }

    public static ArrayList <Token> token = new ArrayList<>();

    public static void read(String filename) throws IOException {
        File file = new File(filename);
        BufferedReader reader = null;
        int line = 1;
        int error_flag = 0;
        int sign_1 = 0;
        try{
            reader = new BufferedReader(new FileReader(file));
            String nextline ;
            while ((nextline = reader.readLine())!=null) {
                lexer analyze = new lexer (nextline,line,token,sign_1);
                if (analyze.getFlag() == 1){
                    error_flag = 1;
                }
                if(analyze.getSign1() == 1) {
                    sign_1 = 1;
                } else if (analyze.getSign1() ==  -1) {
                    sign_1 = 0;

                }

                line++;
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if(reader !=null) {
                try{
                    reader.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        output out1 = new output(token,error_flag);
    }
}