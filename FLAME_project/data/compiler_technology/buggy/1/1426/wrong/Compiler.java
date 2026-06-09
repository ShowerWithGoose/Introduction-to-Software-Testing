import frontend.Lexer;
import frontend.Parser.ErrorHandler;
import frontend.TokenType;
import frontend.Token;
import frontend.Parser.CompUnit;
import frontend.Parser.CompUnitParser;

import java.util.ArrayList;
import java.io.*;
import java.util.List;


public class Compiler {
    private Lexer lexer;
    private CompUnit compUnit;
    private ArrayList<String> errorMessages = new ArrayList<>();
    private int iserror = 0;

    public Compiler(String inputFilePath) throws IOException {
        try (Reader reader = new FileReader(inputFilePath)) {
            lexer = new Lexer(reader);
            CompUnitParser compUnitParser = new CompUnitParser(lexer.getTokens());
            this.compUnit = compUnitParser.parseCompUnit();
//            System.out.println(lexer.getFileValue());
        }
        errorMessages = new ArrayList<>();
    }

    public void analyze() {
        for (Token token : lexer.getTokens()) {
            if (isError(token)) {
                String errorMessage = token.getLine() + " " + "a";
                errorMessages.add(errorMessage);
                iserror = 1;
            }
        }
        if(ErrorHandler.getInstance().hasErrorOccurred() == true)
        {
            iserror = 1;
        }
    }

    private boolean isError(Token token) {
        return token.getType() == TokenType.ERROR;
    }

    public void outputResults(String parserOutputPath, String errorOutputPath) throws IOException {
        if(iserror == 0) {
            try (BufferedWriter parserWriter = new BufferedWriter(new FileWriter(parserOutputPath))) {
//                for (Token token : lexer.getTokens()) {
//                    lexerWriter.write(token.toString() + "\n");
//                }
//                for (Token token : lexer.getTokens()) {
//                    System.out.println(token.toString() + "\n");
//                }
                parserWriter.write(compUnit.Parser_Output());
            }
        }
        else {
            try (BufferedWriter errorWriter = new BufferedWriter(new FileWriter(errorOutputPath))) {
//                for (String errorMessage : errorMessages) {
//                    errorWriter.write(errorMessage);
//                    errorWriter.newLine();
//                }
                List<String> errors = ErrorHandler.getInstance().getErrors();
                for (String error : errors) {
                    errorWriter.write(error);
                    errorWriter.newLine();
                }
            }
        }
    }

    public static void main(String[] args){
        //  /Users/xiaobing/Documents/24å†¬/frontend/
        String inputFilePath = "testfile.txt";
        String parserOutputPath = "parser.txt";
        String errorOutputPath = "error.txt";
        try {
            Compiler compiler = new Compiler(inputFilePath);
            compiler.analyze();
            compiler.outputResults(parserOutputPath, errorOutputPath);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
