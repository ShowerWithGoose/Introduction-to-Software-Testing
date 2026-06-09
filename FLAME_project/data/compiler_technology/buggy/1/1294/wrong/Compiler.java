import frontend.Error;
import frontend.ErrorList;
import frontend.FileLexer;
import frontend.Lexer.TokenLexer;
import frontend.Parser.CompUnit;
import frontend.Parser.ParserOfCompUnit;

import java.io.*;
import java.util.ArrayList;

public class Compiler {
    public static void main(String[] args) throws IOException {
        String inputFile = "testfile.txt";
        InputStream inputStream = null;
        try {
            inputStream = new FileInputStream(inputFile);
        } catch (FileNotFoundException e) {
            System.out.println("Can not open file " + inputFile);
        }
        FileLexer fileLexer = new FileLexer(inputStream);
        TokenLexer tokenLexer = new TokenLexer(fileLexer);
        ParserOfCompUnit parserOfCompUnit = new ParserOfCompUnit(tokenLexer.getTokenResolved());
        CompUnit compUnit = parserOfCompUnit.parseCompUnit();

        String outputFile1 = "parser.txt";
        String outputFile2 = "error.txt";
        if(tokenLexer.getIsError() || parserOfCompUnit.hasError()){
            try{
                OutputStream outputStream = new FileOutputStream(outputFile2);
                ArrayList<Error> errors = parserOfCompUnit.getErrors();
                errors.addAll(tokenLexer.getErrors());
                ErrorList errorList = new ErrorList(errors);
                try {
                    outputStream.write(errorList.errorsToString().getBytes());
                } catch (IOException e) {
                    System.out.println("Can not write to file " + outputFile2);
                }
            } catch (FileNotFoundException e) {
                System.out.println("Can not open file " + outputFile2);
            }
        } else{
            //System.out.println(tokenLexer.getTokenResolved().toString());
            try{
                OutputStream outputStream = new FileOutputStream(outputFile1);
                try{
                    outputStream.write(compUnit.grammarOutput().getBytes());
                } catch (IOException e) {
                    System.out.println("Can not write to file " + outputFile1);
                }
            } catch (FileNotFoundException e) {
                System.out.println("Can not open file " + outputFile1);
            }
        }
    }
}
