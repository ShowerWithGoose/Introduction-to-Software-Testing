package src;

public class Words {
    public String string;
    public Integer i;

    public Words(String string) {
        this.string=string;
        i=0;
    }
    public Character get(){
        if (i<string.length()) {
            Character a = string.charAt(i);
            i++;
            return a;
        }
        i++;
        return '\n';
    }
    public void back(){
        i--;
    }
    public void fresh(){
        i=0;
    }
    public boolean max(){
        return i >= string.length();
    }
}
