package lexical;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;

public class TokenList {
    private ArrayList<Token> tokens = new ArrayList<>();
    private int current = 0;
    private BufferedWriter parserWriter;
    private ArrayList<String> parsers;

    public void setParserWriter(BufferedWriter parserWriter) {
        this.parserWriter = parserWriter;
    }

    public void setParsers(ArrayList<String> parsers) {
        this.parsers = parsers;
    }

    public void add(Token token){
        tokens.add(token);
    }

    public ArrayList<Token> getList() {
        return tokens;
    }

    public boolean hasNext() {
        return current < tokens.size();
    }

    public Token get() {
        return ahead(0);
    }

    public Token ahead(int count) {
        return tokens.get(current + count);
    }

    public Token consume(){
        printParser(tokens.get(current).getType() + " " + tokens.get(current).getRawString());
        return tokens.get(current++);
    }

    public Token consume(TokenType... types){
        Token token = tokens.get(current);
        for (TokenType type : types) {
            if (token.getType().equals(type)) {
                current++;
                printParser(token.getType() + " " + token.getRawString());
                return token;
            }
        }
        return null;
    }

    public void printParser(String s) {
//        try {
//            parserWriter.write(s);
//            parserWriter.newLine();
//        } catch (IOException e) {
//            throw new RuntimeException(e);
//        }
        parsers.add(s);
    }
}
