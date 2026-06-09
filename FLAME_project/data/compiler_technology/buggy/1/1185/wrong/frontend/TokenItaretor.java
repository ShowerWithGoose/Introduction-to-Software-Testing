package frontend;

import java.util.ArrayList;
import java.util.ListIterator;

public class TokenItaretor {
    public ArrayList<Token> words;
    private ListIterator<Token> Itaretor;
    private Token temp;

    public TokenItaretor(ArrayList<Token> words) {
        this.words = words;
        this.Itaretor = words.listIterator();
    }

    public Token getNext() {
        temp = Itaretor.next();
        return temp;
    }

    public void getPrevious(int n) {
        int cnt = n;
        while(cnt > 0) {
            if(Itaretor.hasPrevious()) {
                temp = Itaretor.previous();
                cnt--;
            } else {
                break;
            }
        }
    }

    public boolean hasNext() {
        return Itaretor.hasNext();
    }


}
