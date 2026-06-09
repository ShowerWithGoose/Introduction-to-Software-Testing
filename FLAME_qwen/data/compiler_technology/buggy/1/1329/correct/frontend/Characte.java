package frontend;

public class Characte {
    //  CharConst
    private Word word;

    public Characte(Word word) {
        this.word = word;
    }

    public void setWordWrong(int type) {
        word.setRight(type);
    }

    public String toString() {
        return word.getLeiBie() + " " + word.getStr() + "\n" + "<Character>" + "\n";
    }
}
