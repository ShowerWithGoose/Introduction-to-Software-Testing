package frontend.lexer;

import java.util.ArrayList;
// 将识别到的所有Token封装成TokenStream类
// 就是装有所有Token的容器
// 便于后续语法分析使用

public class TokenStream {
    private ArrayList<Token> tokenList;
    private int pos;
    private int watchPoint;

    public TokenStream(ArrayList<Token> tokenList) {
        this.tokenList = tokenList;
        this.pos = 0;
        this.watchPoint = 0;
    }

}
