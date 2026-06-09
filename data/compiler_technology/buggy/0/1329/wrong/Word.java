public class Word {
    private int num;

    private String str;

    private int right;

    private String leiBie;

    public Word(int num, String str, String leiBie, int right) {
        this.num = num;
        this.str = str;
        this.leiBie = leiBie;
        this.right = right;
    }

    public String getLeiBie() {
        return leiBie;
    }

    public int getRight() {
        return right;
    }

    public int getNum() {
        return num;
    }

    public String getStr() {
        return str;
    }
}
