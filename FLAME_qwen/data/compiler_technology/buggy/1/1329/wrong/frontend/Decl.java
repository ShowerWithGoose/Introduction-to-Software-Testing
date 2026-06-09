package frontend;

public interface Decl extends BlockItem {
    //ConstDecl | VarDecl
    //不输出
    public void addWord(Word word);

    public void setbType(BType bType);

    public String toString();
}
