package clase7;

public class TrabajoPintura extends Servicio{
    private double sup;
    private double precio;

    public TrabajoPintura(String trabajador, String cliente, double sup, double precio){
        super(trabajador, cliente);
        this.sup = sup;
        this.precio = precio;
    }

    @Override
    public double costeMaterial(){
        return ((sup / 3) * precio);
    }

    @Override
    public double costeManoObra(){
        return sup * 0.466;
    }

    @Override
    public double costeTotal(){
        double coste = costeManoObra() + costeMaterial();
        if(sup < 50)
            coste = coste + coste * 0.15;
        return coste;
    }
    @Override
    public String getname(){
        return this.cliente;
    }
}
