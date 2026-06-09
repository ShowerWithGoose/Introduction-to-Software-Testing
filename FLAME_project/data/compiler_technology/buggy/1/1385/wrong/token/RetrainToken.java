package token;

public enum RetrainToken {
    MAINTK("main"),CONSTTK("const"),INTTK("int"), CHARTK("char"), BREAKTK("break"),
    CONTINUETK("continue"), IFTK("if"),ELSETK("else"),VOIDTK("void"), FORTK("for"),
    GETINTTK("getint"),GETCHARTK("getchar"), PRINTFTK("printf"),RETURNTK("return");
    
    private String token;
    RetrainToken(String token){
        this.token = token;
    }
    
    public String getToken(){
        return token;
    }
    
    public static RetrainToken queryRetrainToken(String token) {
        for (RetrainToken type : RetrainToken.values()) {
            if (type.getToken().equals(token)) {
                return type;
            }
        }
        return null;
    }
}
