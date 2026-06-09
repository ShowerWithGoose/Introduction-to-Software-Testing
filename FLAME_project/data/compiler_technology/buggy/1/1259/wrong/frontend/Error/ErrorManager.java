package frontend.Error;

import frontend.IOManager;
import frontend.Lexer.Token;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class ErrorManager
{
    private static final ErrorManager instance = new ErrorManager();
    private boolean isError = false;
    private ErrorManager(){}
    public static ErrorManager GetInstance(){return instance;}
    private List<ErrorToken> errors = new ArrayList<>();

    public boolean isError() {
        return isError;
    }

    public void addError(ErrorToken error){
        errors.add(error);
    }

    public void setError(boolean error) {
        isError = error;
    }

    public void PrintError() throws IOException {
        errors.sort(Comparator.comparingInt(Token::getLineNo));
        BufferedWriter bw = IOManager.writer;
        for(ErrorToken errorToken : errors) {
            bw.write(errorToken.getLineNo() + " " + errorToken.getErrorType().toString());
            bw.newLine();
        }

    }
}
