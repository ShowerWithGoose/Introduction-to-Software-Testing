package parse;

public class WrongType {
    private int linenumber;
    private String type ;
    public WrongType(int num,String type){
        this.linenumber = num;
        this.type = type;
    }

    public int getLinenumber() {
        return linenumber;
    }

    public void setLinenumber(int linenumber) {
        this.linenumber = linenumber;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }
}

