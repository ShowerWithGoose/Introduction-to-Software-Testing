package frontend.lexer;

import config.Config;
import utils.IOUtil;

import java.util.ArrayList;

public class LexerError {
    private static final LexerError instance = new LexerError();
    public static LexerError getInstance() {
        return instance;
    }
    private ArrayList<Token> tokens = new ArrayList<>();
    public boolean addToken(Token token){
        return tokens.add(token);
    }
    public boolean tokenIsEmpty(){
        return tokens.isEmpty();
    }
    public void error() {
        ArrayList<String> result = new ArrayList<>();
        for (Token t : tokens) {
            result.add(t.getLineNum() + " a");
        }
        IOUtil.writeToFile(Config.getErrorFilePath(), result);
    }
}
