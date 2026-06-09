package frontend;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.HashMap;

public class GiveTokener {
    private static GiveTokener instance;
    private static Deque<Token> deque = new ArrayDeque<>();
    private Lexer lexer;

    private int maxlineno = 0;

    private GiveTokener() {
    }

    public static synchronized GiveTokener getInstance() {
        if (instance == null) {
            instance = new GiveTokener();
        }
        return instance;
    }

    public void giveLexer(Lexer lexer){
        this.lexer = lexer;
    }

    public Token getAToken(){
        if(deque.isEmpty()){
            Token newtoken = lexer.lexer();
            if(newtoken == null){
                return null;
            }
            if(newtoken.getLineno()>maxlineno){
                this.maxlineno = newtoken.getLineno();
            }
            deque.addFirst(newtoken);
        }
        Token toreturn = deque.getFirst();
        deque.removeFirst();
        return toreturn;
    }

    public Token preReadAToken(){
        if(deque.isEmpty()){
            Token newtoken = lexer.lexer();
            if(newtoken == null){
                return null;
            }
            if(newtoken.getLineno()>maxlineno){
                this.maxlineno = newtoken.getLineno();
            }
            deque.addFirst(newtoken);
        }
        Token toreturn = deque.getFirst();
        deque.removeFirst();
        return toreturn;
    }

    public static void putBackAToken(Token token){
        deque.addFirst(token);
    }

    public int getMaxlineno() {
        return maxlineno;
    }
}
