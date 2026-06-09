package Lexer;

import java.util.ArrayList;
import java.util.ListIterator;

/**
 * @Description:
 * @date 2024/10/10
 */
public class TokenListIterator {
    private ArrayList<Token> tokens;
    private ListIterator<Token> iterator;
    private Token current;
    public TokenListIterator(ArrayList<Token> tokens)
    {
        this.tokens=tokens;
        this.iterator= tokens.listIterator();
    }
    public ListIterator<Token> getIterator() {
        return iterator;
    }

    public Token readNextToken() {
        if(iterator.hasNext())
        return current = this.iterator.next();
        else {
            System.out.println("越界啦");
            return current;
        }
    }
    public boolean hasNext() {
        return this.iterator.hasNext();
    }
    public void unReadToken(int k) {
        int cnt=k;
        while(cnt>0)
        {
            cnt--;
            if(this.iterator.hasPrevious())
            {
                current=this.iterator.previous();
            }else {
                break;
            }
        }
    }


}
