package clase8;

public class Pelicula{
    private String name;
    private char clas = 'u';
    
    public Pelicula(String name){
        this.name = name;
    }
    public void setClas(char letra){
        this.clas = letra;
    }
    public String getName() {
        return name;
    }
    public char getClas(){
        return this.clas;
    }
}
