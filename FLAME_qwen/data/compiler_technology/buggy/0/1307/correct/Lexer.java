import java.util.ArrayList;
import java.util.regex.Pattern;

public class Lexer {

    private LineSplitter lineSplitter;

    private ArrayList<Token> tokenList;

    public Lexer(LineSplitter lineSplitter) {
        tokenList = new ArrayList<>();
        this.lineSplitter = lineSplitter;
        extractToken();
    }

    public void extractToken() {
        while (!lineSplitter.endFile()) {
            if (lineSplitter.getLine().isEmpty()) {
                lineSplitter.moveNextLine();
                continue;
            }
            lineSplitter.skipSpace();
            //System.out.println("loop " + lineSplitter.getLine() + "#####");
            if (skipComment()) {
                continue;
            }
            Token token = lineSplitter.getToken();
            if (token.getType() != null) {
                tokenList.add(token);
            }
        }
    }

    public boolean skipComment() {
        if (lineSplitter.getLineSubString(2).equals("//")) {
            lineSplitter.moveNextLine();
            return true;
        }
        if (lineSplitter.getLineSubString(2).equals("/*")) {
            lineSplitter.moveForward(2);
            while (!lineSplitter.endFile() && !lineSplitter.getLineSubString(2).equals("*/")) {
                lineSplitter.moveForward(1);
            }
            if (lineSplitter.getLineSubString(2).equals("*/")) {
                lineSplitter.moveForward(2);
                return true;
            }
        }
        return false;
    }

    public void addToken() {
        tokenList.add(lineSplitter.getToken());
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < tokenList.size(); i++) {
            Token token = tokenList.get(i);
            sb.append(token.getType()).append(" ").append(token.getContent());
            if (i != tokenList.size() - 1) {
                sb.append("\n");
            }
        }
        return sb.toString();
    }
}
