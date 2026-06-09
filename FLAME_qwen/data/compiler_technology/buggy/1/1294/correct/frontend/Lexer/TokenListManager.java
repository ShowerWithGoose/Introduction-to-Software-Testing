package frontend.Lexer;

public class TokenListManager {
    private TokenResolved resolvedList;
    private int pos;
    private Token nowToken;

    public TokenListManager(TokenResolved resolvedList) {
        this.resolvedList = resolvedList;
        pos = 0;
    }

    public Token getTokenAndMove() {
        if(pos >= resolvedList.getTokenList().size()){
            return null;
        }
        return resolvedList.getTokenList().get(pos++);
    }

    public boolean hasNextToken() {
        return pos < resolvedList.getTokenList().size() - 1;
    }

    public void lookBackToken(int num) {
        int cnt = num;
        while (cnt > 0) {
            cnt--;
            if(pos > 0){
                pos--;
                nowToken = resolvedList.getTokenList().get(pos);
            } else {
                break;
            }
        }
    }

    public String toString(){
        return nowToken.getValue();
    }
}
