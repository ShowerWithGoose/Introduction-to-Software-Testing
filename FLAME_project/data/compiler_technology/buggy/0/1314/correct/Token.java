import java.util.HashMap;

public class Token {
    private Word word;
    private String context;
    public Token(Word word,String context){
        this.word=word;
        this.context=context;
    }

    @Override
    public String toString(){
        return word.toString()+" "+context;
    }

}
