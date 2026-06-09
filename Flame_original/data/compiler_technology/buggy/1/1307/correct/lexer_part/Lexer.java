package lexer_part;

public class Lexer {

    private LineSplitter lineSplitter;

    private TokenList tokenList;

    public Lexer(LineSplitter lineSplitter) {
        tokenList = new TokenList();
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
                tokenList.addToken(token);
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

    public TokenList getTokenList() {
        return tokenList;
    }
}
