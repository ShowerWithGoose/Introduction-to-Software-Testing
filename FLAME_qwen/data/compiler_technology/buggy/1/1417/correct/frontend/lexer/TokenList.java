package frontend.lexer;

import java.util.ArrayList;

public class TokenList {
    private ArrayList<Token> tokens;
    private int pos;

    public TokenList(ArrayList<Token> tokens){
        this.tokens = tokens;
        this.pos = 0;
    }

    // 只读取当前这个，pos不动
    public Token peekToken(){
        return tokens.get(pos);
    }

    // 读取当前这个，然后pos++
    public Token getNextToken(){
        if (pos >= tokens.size()){
            return null;
        }
        int tmp = pos;
        pos++;
        return tokens.get(tmp);
    }

    // 将pos回退d个位置
    public void fallbackToken(int d){
        pos -= d;
        if (pos < 0){
            pos = 0;
        }
    }

    public boolean hasNext(){
        return pos < tokens.size();
    }
}
