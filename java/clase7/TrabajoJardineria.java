package clase7;

public class TrabajoJardineria extends Servicio{
    private int macetas;
    private double sup;

    public TrabajoJardineria(String trabajador, String cliente, double sup, int macetas){
        super(trabajador, cliente);
        this.macetas = macetas;
        this.sup = sup;
    }

    @Override
    public double costeMaterial(){
        double coste = macetas * 10;
        if (sup < 50)
            coste += 100;
        else coste += 200;
        return coste;
    }

    @Override
    public double costeManoObra(){
        return (macetas * 10 + sup * 15);
    }

    @Override
    public double costeTotal(){
        return costeManoObra() + costeMaterial();
    }
    @Override
    public String getname(){
        return this.cliente;
    }
}
