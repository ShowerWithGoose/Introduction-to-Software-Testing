import frontend.Grammar;
import frontend.Lexer;
import frontend.Error;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Compiler {
    public ArrayList<Error> errors;

    static void output_1(Lexer lexer) {
        try{
            File errFile = new File("error.txt");
            File outFile = new File("lexer.txt");
            if (!errFile.exists()) errFile.createNewFile();
            if (!outFile.exists()) outFile.createNewFile();
            BufferedWriter writeOut = new BufferedWriter(new FileWriter("lexer.txt"));
            BufferedWriter writeErr = new BufferedWriter(new FileWriter("error.txt"));
            if (lexer.errors.isEmpty()){
                System.out.println("tokens");
                lexer.tokens.forEach(item->{
                    try {
                        writeOut.write(item.type.toString() + ' ' + item.word);
                        writeOut.newLine();
                        writeOut.flush();
                        System.out.println(item.type.toString() + ' ' + item.word + " at line " + item.line);
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                });
                writeOut.close();
            } else {
                System.out.println("errors");
                lexer.errors.forEach(item->{
                    try {
                        writeErr.write(item.line + " " + item.errorType);
                        writeErr.newLine();
                        writeErr.flush();
                        System.out.println(item.line + " " + item.errorType);
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                });
                writeErr.close();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    static void output_2(Lexer lexer, Grammar grammar) throws IOException {
        File errFile = new File("error.txt");
        File outFile = new File("parser.txt");
        if (!errFile.exists()) errFile.createNewFile();
        if (!outFile.exists()) outFile.createNewFile();
        BufferedWriter writeOut = new BufferedWriter(new FileWriter("parser.txt"));
        BufferedWriter writeErr = new BufferedWriter(new FileWriter("error.txt"));
        ArrayList<Error> e = new ArrayList<>();
        if(!lexer.errors.isEmpty()){
            e.addAll(lexer.errors);
        }
        if(!grammar.errors.isEmpty()){
            e.addAll(grammar.errors);
        }
        if (e.isEmpty()) {
            if(grammar.root != null){
                System.out.println("tokens and grammar tree are correct!");
                grammar.root.p();
                grammar.root.w(writeOut);
            }
        } else {
            System.out.println("errors");
            e.forEach(item->{
                try {
                    writeErr.write(item.line + " " + item.errorType);
                    writeErr.newLine();
                    writeErr.flush();
                    System.out.println(item.line + " " + item.errorType);
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }
            });
        }
    }

    public static void main(String[] args) throws IOException {
        String inFile = "testfile.txt";
        Lexer lexer = new Lexer(new File(inFile));
        lexer.wordAna();
        //output_1(lexer);
        Grammar grammar = new Grammar(lexer.tokens);
        System.out.println("-----finish-----");
        output_2(lexer, grammar);
    }

}
