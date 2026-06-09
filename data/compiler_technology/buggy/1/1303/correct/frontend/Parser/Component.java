package frontend.Parser;

import java.util.ArrayList;

public class Component {
    ComponentType componentType;
    ArrayList<Component> components;
    public Component(){}
    public Component(ComponentType componentType){
        this.componentType=componentType;
    }
    public Component(ComponentType componentType,ArrayList<Component> components){
        this.componentType=componentType;
        this.components=components;
    }
}
