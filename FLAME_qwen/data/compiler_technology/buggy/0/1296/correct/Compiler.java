import frontend.Error;
import frontend.Input;
import frontend.Lexer;
import frontend.Token;

import java.io.*;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) {
        ArrayList<String> inputArray = new ArrayList<>();
        int input_line = 0;

        String filePath = "testfile.txt";
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                inputArray.add(line + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        /*for (String s : inputArray) {
            System.out.println(s);
        }*/


        Input input = new Input(inputArray);//输入处理
        ArrayList<Token> tokens = new ArrayList<>();
        ArrayList<Error> errors = new ArrayList<>();
        Lexer lexer = new Lexer(input, tokens, errors);

        boolean flag_lexer = lexer.lexer();

        if (flag_lexer) {
            String lexerPath = "lexer.txt";
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(lexerPath))) {
                for (Token token: tokens) {
                    writer.write(token.getTypeStr() + " " + token.getStr());
                    writer.newLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            String lexerPath = "error.txt";
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(lexerPath))) {
                for (Error error: errors) {
                    writer.write(error.getLine() + " " + error.getType());
                    //System.out.println(error.getLine() + " " + error.getType());
                    writer.newLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}