package clase8;

public class Cuenta{
    private String userId;
    private String plan;
    private Perfil[] perfiles;

    public Cuenta(String id, String plan, String name){
        this.userId = id;
        this.plan = plan;
        this.perfiles = new Perfil[4];
        perfiles[0] = new Perfil(name);
    }

    public void agregarPerfil(Perfil p){
        for(int i = 1; i < 3; i++)
            if(perfiles[i] == null){
                perfiles[i] = p;
                break;
            }
    }
    public void buscarPelicula(String nombre){
        System.out.println("la pelicula " + nombre + " está en los perfiles de: \n");
        for(Perfil p: perfiles){
            for(Pelicula pp: p.pelis){
                if(pp.getName().equals(nombre))
                    System.out.println(p.name + "\n");
                    break;
            }
        }
    }
}
