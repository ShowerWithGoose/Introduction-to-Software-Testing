package frontend.lexer;

import java.io.BufferedWriter;
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

    public void print(BufferedWriter fileOut) throws IOException {
        fileOut.write("");
        for (Token token : tokenList) {
            String str = token.toString() + '\n';
//            System.out.print(str);
            fileOut.append(token.toString()).append(String.valueOf('\n'));
        }
    }
}
