package frontend.Def;

public class Def{
    private DefType type;
    private String name;

    public Def(String name, DefType type) {
        this.name = name;
        this.type = type;
    }


    public String getName() {
        return this.name;
    }

    public DefType getType() {
        return this.type;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Def) {
            return this.name.equals(((Def) obj).name);
        }
        return false;
    }

    @Override
    public String toString() {
        return this.name + "<" + this.type + ">";
    }

}
