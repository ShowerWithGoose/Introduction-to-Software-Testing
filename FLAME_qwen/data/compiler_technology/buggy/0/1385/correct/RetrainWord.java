public enum RetrainWord {
    MAINTK("main"),CONSTTK("const"),INTTK("int"), CHARTK("char"), BREAKTK("break"),
    CONTINUETK("continue"), IFTK("if"),ELSETK("else"),VOIDTK("void"), FORTK("for"),
    GETINTTK("getint"),GETCHARTK("getchar"), PRINTFTK("printf"),RETURNTK("return");
    
    private String word;
    RetrainWord(String word){
        this.word = word;
    }
    
    public String getWord(){
        return word;
    }
    
    public static RetrainWord queryRetrainWord(String word) {
        for (RetrainWord type : RetrainWord.values()) {
            if (type.getWord().equals(word)) {
                return type;
            }
        }
        return null;
    }
}
