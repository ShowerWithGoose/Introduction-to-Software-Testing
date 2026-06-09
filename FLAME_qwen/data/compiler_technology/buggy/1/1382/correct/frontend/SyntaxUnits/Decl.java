package frontend.SyntaxUnits;

public class Decl implements BlockItemUnit{
    private DeclUnit declUnit;

    public Decl(DeclUnit declUnit) {
        this.declUnit = declUnit;
    }

    @Override
    public String toPrint() {
        return declUnit.toPrint();
    }
}
