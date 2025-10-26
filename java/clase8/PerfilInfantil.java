package clase8;

public class PerfilInfantil extends Perfil{
    private int edad;

    public PerfilInfantil(String name, int edad){
        super(name);
        this.edad = edad;
    }

    @Override
    public void agregarPelicula(Pelicula p){
        if(p.getClas() != 'C')
            if(edad < 12)
                if(p.getClas() != 'B')
                    super.agregarPelicula(p);
            else super.agregarPelicula(p);
    }
}
