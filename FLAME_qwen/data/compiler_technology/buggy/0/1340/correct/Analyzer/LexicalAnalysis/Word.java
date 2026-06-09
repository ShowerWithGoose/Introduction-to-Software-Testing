package Analyzer.LexicalAnalysis;

public class Word {
    private String wordName;
    private WordType wordType;
    private int col;
    private int row;
    public Word(String wordName,WordType wordType,int col,int row){
        this.wordName = wordName;
        this.wordType = wordType;
        this.col = col;
        this.row = row;
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

    public int getCol() {
        return col;
    }

    public void setCol(int col) {
        this.col = col;
    }

    public int getRow() {
        return row;
    }

    public void setRow(int row) {
        this.row = row;
    }

}
