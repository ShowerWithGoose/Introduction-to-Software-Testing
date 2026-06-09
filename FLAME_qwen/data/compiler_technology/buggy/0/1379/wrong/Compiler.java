import error.Error_A;
import frontend.FileOutput;
import frontend.Lexer;
import frontend.Token;

import java.io.*;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) throws FileNotFoundException {
 //       ArrayList<String> input = new ArrayList<>();
        ArrayList<String> name = new ArrayList<>();
        ArrayList<String> content = new ArrayList<>();
        PushbackInputStream input = new PushbackInputStream(new FileInputStream("testfile.txt"),16);
        FileOutput fileOutput1 = new FileOutput("lexer.txt");
        FileOutput fileOutput2 = new FileOutput("error.txt");
        boolean existError = false;
        Lexer lexer = new Lexer(input,fileOutput2);
        while(!lexer.isEnd()) {
            try {
                lexer.next();
            } catch (Error_A e) {
                e.printError();
                existError = true;
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            Token token = lexer.peek();
            if (token.getType() != null) {
                name.add(token.getType().toString());
                content.add(token.getContent());
            }
        }
        if (!existError) {
            for (int i = 0; i < name.size(); i++) {
                fileOutput1.write(name.get(i) + " " + content.get(i));
            }
        }
    }
}