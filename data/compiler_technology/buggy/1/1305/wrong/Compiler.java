import Frontend.Lexer;
import Frontend.Parser;
import Token.*;
import Error.Error;
import Node.*;

import java.nio.file.StandardOpenOption;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.IOException;
import java.util.Collections;

public class Compiler {
    public static String inputPath = "testfile.txt";
    public static String outputPath = "lexer.txt";
    public static String errorPath = "error.txt";

    public static void main(String[] args) throws IOException {
        String source = Files.readString(Paths.get(inputPath));
        System.out.println(source);
        Lexer lexer = new Lexer();
        lexer.scan(source);
        if(!Files.exists(Paths.get(outputPath))){
            Files.createFile(Paths.get(outputPath));
        }
        if(!Files.exists(Paths.get(errorPath))) {
            Files.createFile(Paths.get(errorPath));
        }
        Parser parser = new Parser(lexer.tokens);
        CompUnitNode compUnitNode = parser.compUnitAnalyze();
        if(!Error.errors.isEmpty()){
            Collections.sort(Error.errors);
            for(Error error : Error.errors){
                Files.write(Paths.get(errorPath), error.toString().getBytes(), StandardOpenOption.CREATE, StandardOpenOption.APPEND);
            }
        }
        else{
            for(Token token : lexer.tokens){
                Files.write(Paths.get(outputPath), token.toString().getBytes(), StandardOpenOption.CREATE, StandardOpenOption.APPEND);
            }
            compUnitNode.print();
        }
    }
}
