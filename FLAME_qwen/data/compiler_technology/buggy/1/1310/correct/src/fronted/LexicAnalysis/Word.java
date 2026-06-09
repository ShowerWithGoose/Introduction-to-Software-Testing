package src.fronted.LexicAnalysis;

public class Word {
    private String wordName;
    private WordType wordType;
    private int row;
    private int col;
    private Object value;

    public Word(String wordName, WordType wordType, int row, int col) {
        this.wordName = wordName;
        this.wordType = wordType;
        this.row = row;
        this.col = col;
//        if (wordType == WordType.CHRCON) {
//            value = wordName.charAt(1);
//        } else if (wordType == WordType.INTCON) {
//            value = Integer.valueOf(wordName);
//        }
    }

//    public Object getValue() {
//        if (wordType == WordType.CHRCON) {
//            value = wordName.charAt(1);
//        } else if (wordType == WordType.INTCON) {
//            value = Integer.valueOf(wordName);
//        } else {
//            value = String.valueOf(wordName);
//        }
//        return value;
//    }

    public WordType getWordType() {
        return wordType;
    }

    public String getWordName() {
        return wordName;
    }

    public int getRow() {
        return row;
    }
    //其余方法有需要再补充
}
