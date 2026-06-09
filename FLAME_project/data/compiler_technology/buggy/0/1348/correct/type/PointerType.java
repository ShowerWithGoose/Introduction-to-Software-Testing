package type;

public class PointerType extends BasicType{
    public String name = "pointer";
    public BasicType eleType;
    public PointerType(BasicType EleType){
        this.eleType = EleType;
    }
}
