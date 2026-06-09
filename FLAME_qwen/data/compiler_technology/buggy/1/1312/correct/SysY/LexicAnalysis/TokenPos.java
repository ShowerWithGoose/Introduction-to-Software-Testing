package SysY.LexicAnalysis;

public class TokenPos {
    public int row;
    public int col;

    public TokenPos(int row, int col){
        this.row = row;
        this.col = col;
    }

    public int getRow() {
        return row;
    }
}
