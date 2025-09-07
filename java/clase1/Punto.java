package clase1;

public class Punto{
    private int x;
    private int y;

    public Punto(){
        x = y = 0;
    }
    public Punto(int x, int y){
        this.x = x;
        this.y = y;
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
    public void mueveDcha(int x){
        this.x = this.x + x;
    }
    public void mueveArr(int y){
        this.y = this.y + y;
    }
    public double distancia(int coordX, int coordY){
        int x = coordX - this.x;
        int y = coordY - this.y;
        int d = (x * x) + (y * y);
        return Math.sqrt(d);
    }
    @Override
    public String toString(){
        return "las coordenadas del pinto son (" + this.x + ", " + this.y + ")";
    }
}
