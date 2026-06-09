import frontend.Lexer;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Compiler {

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
                        System.out.println(item.type.toString() + ' ' + item.word);
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                });
                writeOut.close();
            } else {
                System.out.println("errors");
                lexer.errors.forEach(item->{
                    try {
                        writeErr.write(item.line + ' ' + item.errorType);
                        writeErr.newLine();
                        writeErr.flush();
                        System.out.println(item.line + ' ' + item.errorType);
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

    public static void main(String[] args) {
        String inFile = "testfile.txt";
        Lexer lexer = new Lexer(new File(inFile));
        lexer.wordAna();
        output_1(lexer);
    }
}
