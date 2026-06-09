package frontend.lexer;

import output.MyStream;

import java.io.IOException;
import java.util.ArrayList;

public class TokenList {
    public final ArrayList<Token> tokenList;
    private int curIndex = 0;

    public TokenList() {
        tokenList = new ArrayList<>();
    }

    public void addToken(Token token) {
        tokenList.add(token);
    }

    public boolean hasNext() {
        return curIndex < tokenList.size();
    }

    public void print() throws IOException {
        for (Token token : tokenList) {
            String str = token.toString();
            MyStream.printLexer(str);
//            System.out.print(str);
//            fileOut.append(token.toString()).append(String.valueOf('\n'));
        }
    }

    public Token look(int cnt) throws IOException {
        if (cnt + curIndex >= tokenList.size()) {
            MyStream.close();
        }
        return tokenList.get(cnt + curIndex);
    }

    public Token getAndAdd() throws IOException {
        MyStream.printParser(tokenList.get(curIndex).toString());
        return tokenList.get(curIndex++);
    }

    public void skip() throws IOException {
        MyStream.printParser(tokenList.get(curIndex).toString());
        curIndex++;
    }
}
