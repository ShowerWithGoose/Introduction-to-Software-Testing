public class Word {
    private String type;
    private RetrainWord retrainWord;
    private String value;
    private int rowNumber;
    private String error;
    
    public Word(String value,String type,int rowNumber){
        this.error = null;
        this.value = value;
        this.type = type;
        this.rowNumber = rowNumber;
        if (type.equals("IDENFR")){
            retrainWord = RetrainWord.queryRetrainWord(value);
            if (retrainWord!=null){
                this.type = retrainWord.toString();
            }
        }
    }
    
    public String getValue() {
        return value;
    }
    
    public String getType() {
        return type;
    }
    
    public void setError(String s){
        error = s;
    }
    
}
