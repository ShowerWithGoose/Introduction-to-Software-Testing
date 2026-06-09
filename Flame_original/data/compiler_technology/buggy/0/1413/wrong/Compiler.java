import Lexer.Lexer;
import Lexer.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * @Description:
 * @date 2024/9/24
 */
public class Compiler {
    public static void main(String[] args) {
        String sourceFile="testfile.txt";
        String writeFile="lexer.txt";
        String errorFile="error.txt";
        Lexer lexer=new Lexer(sourceFile);
        List<Token> tokens = lexer.tokenize();
        //List<Token> errors =new ArrayList<>();
        int flagError=0;
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(errorFile))) {
            for (Token token : tokens) {
                if (token.getType().equals("ERROR")) {
                    flagError = 1;
                    //errors.add(token);
                    writer.write(token.getLine()+" "+"a");
                }
            }
        }catch (IOException e) {
            e.printStackTrace();
        }
        /*for (Token token : tokens) {
            System.out.println(token.getType()+" "+token.getValue());
        }*/
        if(flagError==0){
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(writeFile))) {
                for (Token token : tokens) {
                    writer.write(token.getType() + " " + token.getValue());
                    writer.newLine();
                    System.out.println(token.getValue()+" "+token.getLine());
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}