package frontend;

public class Number {
    // IntConst
    private Word word;

    public Number(Word word) {
        this.word = word;
    }

    public void setWordWrong(int type) {
        word.setRight(type);
    }

    public String toString() {
        return word.getLeiBie() + " " + word.getStr() + "\n" + "<Number>" + "\n";
    }
}
