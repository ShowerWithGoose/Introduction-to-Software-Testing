package Token;
import frontend.*;
/**
 * @Description:
 * @author
 * @date 2024/9/23 16:19
 */

/**
 * @author:
 * TODO  
 * 2024/9/23 16:19
 */
public class Token {
    private int lineNumber;
    private LexType lexType;
    private String token;

    public Token(LexType lexType,String token,int lineNumber){
        this.lexType=lexType;
        this.token=token;
        this.lineNumber=lineNumber;
    }

    public LexType getLexType() {
        return lexType;
    }

    public int getLineNumber() {
        return lineNumber;
    }

    @Override
    public String toString() {
        return lexType.toString()+" "+token+"\n";
    }
}
