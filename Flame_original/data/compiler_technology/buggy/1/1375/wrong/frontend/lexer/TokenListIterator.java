package frontend.lexer;

import java.util.ArrayList;
import java.util.ListIterator;

public class TokenListIterator {
    public ArrayList<Token> tokens;
    public ListIterator<Token> iterator;
    public Token last;
    public TokenListIterator(ArrayList<Token> tokens) {
        this.tokens = tokens;
        this.iterator = this.tokens.listIterator();
    }
    public Token readNextToken() {
        return last = this.iterator.next();
    }
    public boolean hasNext() {
        return iterator.hasNext();
    }
    public void unReadToken(int k){
        int cnt=k;
        while(cnt>0){
            cnt--;
            if(this.iterator.hasPrevious()){
                last = this.iterator.previous();
            }else{
                break;
            }
        }
    }

}
