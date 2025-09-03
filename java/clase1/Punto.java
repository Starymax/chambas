package clase1;

public class Punto{
    private int x;
    private int y;

    public Punto(){
        x = y = 0;
    }
    public Punto(int x_, int y_){
        x = x_;
        y = y_;
    }
    public int leerX(){
        return x;
    }
    public int leerY(){
        return y;
    }
    public void fijarX(int valorX){
        x = valorX;
    }
    public void fijarY(int valorY){
        y = valorY;
    }
}
