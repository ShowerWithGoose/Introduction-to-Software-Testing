package semantic;

public class Info implements Cloneable {

    private final String ident;

    @Override
    public Info clone() {
        try {
            return (Info) super.clone();
        } catch (CloneNotSupportedException e) {
            throw new AssertionError();
        }
    }

    public Info(String ident) {
        this.ident = ident;
    }

    public String getIdent() {
        return ident;
    }

    @Override
    public String toString() {
        return "";
    }
}
