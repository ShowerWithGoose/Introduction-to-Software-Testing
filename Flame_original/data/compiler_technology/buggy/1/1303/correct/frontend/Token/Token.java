package frontend.Token;

import frontend.Parser.Component;
import frontend.Parser.ComponentType;
import frontend.Token.TokenType;

import java.util.ArrayList;

public class Token extends Component{
    public TokenType type;
    public String content;
    public int lineno;


    // 无参构造方法
    public Token() {}

    // 全参构造方法
    public Token(TokenType type, String content, int lineno) {
        super(ComponentType.Leaf);
        this.type = type;
        this.content = content;
        this.lineno = lineno;
    }


}
