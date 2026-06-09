package frontend.DataStructure;

import frontend.Lexer;

import java.util.ArrayList;
import java.util.List;

public class Lex {
    public String token;
    public Lexer.LexType lexType;
    public int lineNum;
    public boolean correct;

    public Lex(String token, Lexer.LexType lexType, int lineNum, boolean correct){
        this.token = token;
        this.lexType = lexType;
        this.lineNum = lineNum;
        this.correct = correct;
    }

    public static List<Lex> LexList = new ArrayList<>();

}

