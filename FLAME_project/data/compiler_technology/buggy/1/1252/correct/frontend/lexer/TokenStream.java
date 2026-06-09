package frontend.lexer;

import java.util.ArrayList;

public class TokenStream {
    private ArrayList<Token> tokenArrayList;
    private int pos;
    private int backPoint;//回退点，用于回退到特定的 Token 位置

    public TokenStream(ArrayList<Token> tokenArrayList) {
        this.tokenArrayList = tokenArrayList;
        this.pos = 0;
        this.backPoint = 0;
    }

    public Token getToken(){
        if (pos >= tokenArrayList.size()) {
            pos++;//TODO:为什么pos超过size时仍需++
            return null;
        }
        return tokenArrayList.get(pos++);
    }

    public void putBack() {
        if (pos > 0) {
            pos--;
        }
    }

    public Token detect(int step) {
        int newPos = pos + step - 1;
        if(newPos < tokenArrayList.size()) return tokenArrayList.get(newPos);
        return null;
    }

    public void setBackPoint() { //设置回退点 watchPoint
        //将当前 pos 的值保存到 watchPoint 中
        backPoint = pos;
    }

    //回退到回退点
    public Token backToBackPoint() {
        pos = backPoint - 1;
        return getToken();
    }
}
