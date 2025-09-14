package clase3;

import java.util.ArrayList;

public class SistemaSolar{
    private ArrayList<Planeta> p;

    public SistemaSolar(){
        p.add(null);
    }
    public SistemaSolar(Planeta ff){
        p.add(ff);
    }
}