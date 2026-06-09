import frontend.Errors;
import frontend.Lexer;
import frontend.MyError;
import frontend.Token;
import frontend.parseApart.Parse;

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
        ArrayList<String> parseOut = new ArrayList<>();
        getInput();
        Lexer lexer  = new Lexer(errors, sourceCode);
        Parse parse = new Parse(lexer, errors);
        parse.parseBegin();
        parseOut = parse.getParseOut();
        rightProcedure(parseOut);
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
            for (MyError error : errors1) {
                String s = error.getMessage();
                writer.write(s + "\n");
            }
            writer.flush();
            writer.close();
        }
    }

    private static void rightProcedure(ArrayList<String> parseOut) throws IOException {
        String path = "parser.txt";
        File file = new File(path);
        try{
            if (!file.exists()) {
                file.createNewFile();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        FileWriter writer = new FileWriter(file);
        if (!parseOut.isEmpty()) {
            for (String s : parseOut) {
                //System.out.println(s);
                writer.write(s + "\n");
            }
            writer.flush();
            writer.close();
        }
    }

}