import frontend.Errors;
import frontend.Lexer;
import frontend.MyError;
import frontend.Token;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Compiler {
    private static ArrayList<String> sourceCode = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        Errors errors = new Errors();
        ArrayList<Token> tokens = new ArrayList<>();
        getInput();
        Lexer lexer  = new Lexer(errors, sourceCode);

        while (true) {
            lexer.next();

            if (lexer.isEnd() || lexer.getArriveEnd()) {
                break;
            } else {
                tokens.add(lexer.getNewToken());
            }
        }
        rightProcedure(tokens);
        errorProcedure(errors);
    }

    private static void getInput() {
        String fileName = "./testfile.txt";
        try {
            FileReader fileReader = new FileReader(fileName);
            Scanner scanner = new Scanner(fileReader);
            while (scanner.hasNextLine()) {
                sourceCode.add(scanner.nextLine());
            }
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    private static void errorProcedure(Errors errors) throws IOException {
        ArrayList<MyError> errors1 = errors.getErrors();
        String path = "error.txt";
        File file = new File(path);
        try{
            if (!file.exists()) {
                file.createNewFile();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        FileWriter writer = new FileWriter(file);
        if (!errors1.isEmpty()) {
            String s = errors1.get(0).getMessage();
            writer.write(s + "\n");
            writer.flush();
            writer.close();
        }
    }

    private static void rightProcedure(ArrayList<Token> tokens) throws IOException {
        String path = "lexer.txt";
        File file = new File(path);
        try{
            if (!file.exists()) {
                file.createNewFile();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        FileWriter writer = new FileWriter(file);
        if (!tokens.isEmpty()) {
            for (Token token: tokens) {
                System.out.println(token.getLexType() + " " + token.getName());
                writer.write(token.getLexType() + " " + token.getName() + "\n");
            }
            writer.flush();
            writer.close();
        }
    }

}