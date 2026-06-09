package frontend.parser;

import java.util.ArrayList;

public class ParseUnit {
    private String name;
    private ArrayList<ParseUnit> subUnits;

    public ParseUnit(String name,ArrayList<ParseUnit> subUnits){
        this.name=name;
        this.subUnits=subUnits;
    }

    @Override
    public String toString(){
        StringBuilder sb=new StringBuilder();
        for(ParseUnit unit:subUnits){
            sb.append(unit.toString()).append("\n");
        }
        sb.append("<").append(name).append(">");
        return sb.toString();
    }
    public void replaceUnits(ArrayList<ParseUnit> units){
        subUnits.clear();
        subUnits.addAll(units);
    }
}
