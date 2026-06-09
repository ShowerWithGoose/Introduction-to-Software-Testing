package frontend.LexicalAnalysis;

public class Word {
    private String wordName;
    private WordType wordType;
    private int row;
    private int col;
    public Word(String wordName, WordType wordType, int row, int col){
        this.wordName = wordName;
        this.wordType = wordType;
        this.row = row;
        this.col = col;
    }
    public WordType getWordType() {
        return wordType;
    }

    public void setWordType(WordType wordType) {
        this.wordType = wordType;
    }

    public String getWordName() {
        return wordName;
    }

    public void setWordName(String wordName) {
        this.wordName = wordName;
    }

    public int getRow() {
        return row;
    }

    public void setRow(int row) {
        this.row = row;
    }

    public int getCol() {
        return col;
    }

    public void setCol(int col) {
        this.col = col;
    }

}
