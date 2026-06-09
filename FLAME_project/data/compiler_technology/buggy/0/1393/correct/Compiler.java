import frontend.Lexer;
import frontend.ParseLexer;

import java.io.IOException;
import java.io.PrintStream;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) throws IOException {
        ParseLexer parseLexer = new ParseLexer();
        ArrayList<Lexer> res = new ArrayList<>();
        ArrayList<Lexer> errors = new ArrayList<>();
        for(;;){
            Lexer tem = parseLexer.getNextLexer();
            if(tem!=null){
               if(tem.isError()){
                   errors.add(tem);
               }else{
                   res.add(tem);
               }
            }else{
                break;
            }
        }
        if(errors.isEmpty()){
            PrintStream fileOut = new PrintStream(Files.newOutputStream(Paths.get("lexer.txt")));
            System.setOut(fileOut);
            for(Lexer lexer:res){
                System.out.println(lexer);
            }
        }else{
            PrintStream fileOut = new PrintStream(Files.newOutputStream(Paths.get("error.txt")));
            System.setOut(fileOut);
            for(Lexer lexer:errors){
                System.out.println(lexer);
            }
        }
    }
}
