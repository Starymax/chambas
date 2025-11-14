package clase7;

public class TrabajoPintura extends Servicio{
    private double sup;
    private double precio;
    
    /**
     * 
     * @param trabajador
     * @param cliente
     * @param sup
     * @param precio
     */
    public TrabajoPintura(String trabajador, String cliente, double sup, double precio){
        super(trabajador, cliente);
        this.sup = sup;
        this.precio = precio;
    }

    @Override
    /**
     * calcula el coste del material
     */
    public double costeMaterial(){
        return ((sup / 3) * precio);
    }
/** 
 * calcula el coste de la mano de obra
 */
    @Override
    public double costeManoObra(){
        return sup * 0.466;
    }
/**
 * calcula el coste total
 */
    @Override
    public double costeTotal(){
        double coste = costeManoObra() + costeMaterial();
        if(sup < 50)
            coste = coste + coste * 0.15;
        return coste;
    }
    /**
     * regresa el nombre del cliente
     */
    @Override
    public String getname(){
        return this.cliente;
    }
}
