package src;
import java.util.ArrayList;
public class Word {
    private ArrayList<Character> word;

    public Word(){
        this.word=new ArrayList<>();

    }
    public void add(Character word){
        this.word.add(word);
    }
    public ArrayList<Character> getWord(){
        return word;
    }

    public int size() {
        return word.size();
    }

    public Character get(int i) {
        return word.get(i);
    }
}
