package frontend;

public class Wrong {
    public String string;
    public int posLine;
    public String type;

    public Wrong(String s, int pos, String type) {
        this.posLine = pos + 1;
        this.string = s;
        this.type = type;
    }

    public int getPosLine() {
        return posLine;
    }

    public String getString() {
        return posLine + " " + type;
    }



}
