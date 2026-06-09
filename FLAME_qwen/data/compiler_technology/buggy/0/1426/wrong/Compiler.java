import frontend.Lexer;
import frontend.TokenType;
import frontend.Token;
import java.util.ArrayList;
import java.io.*;



public class Compiler {
    private Lexer lexer;
    private ArrayList<String> errorMessages;
    private int error = 0;

    public Compiler(String inputFilePath) throws IOException {
        try (Reader reader = new FileReader(inputFilePath)) {
            lexer = new Lexer(reader);
//            System.out.println(lexer.getFileValue());
        }
        errorMessages = new ArrayList<>();
    }

    public void analyze() {
        for (Token token : lexer.getTokens()) {
            if (isError(token)) {
                String errorMessage = token.getLine() + " " + "a";
                errorMessages.add(errorMessage);
                error = 1;
            }
        }
    }

    private boolean isError(Token token) {
        return token.getType() == TokenType.ERROR;
    }

    public void outputResults(String lexerOutputPath, String errorOutputPath) throws IOException {
        if(error == 0) {
            try (BufferedWriter lexerWriter = new BufferedWriter(new FileWriter(lexerOutputPath))) {
                for (Token token : lexer.getTokens()) {
                    lexerWriter.write(token.toString() + "\n");
                }
            }
        }
        else {
            try (BufferedWriter errorWriter = new BufferedWriter(new FileWriter(errorOutputPath))) {
                for (String errorMessage : errorMessages) {
                    errorWriter.write(errorMessage);
                    errorWriter.newLine();
                }
            }
        }
    }

    public static void main(String[] args){
        String inputFilePath = "testfile.txt";
        String lexerOutputPath = "lexer.txt";
        String errorOutputPath = "error.txt";
        try {
            Compiler compiler = new Compiler(inputFilePath);
            compiler.analyze();
            compiler.outputResults(lexerOutputPath, errorOutputPath);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
