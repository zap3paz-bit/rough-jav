public class Invoice_details{
    public static void main(String[] args){
    
        InvoiceTest i1=new InvoiceTest();
        i1.test();        
    }

}

class Invoice{
       private String partno;
       private String desc;
       private int quantity;
       private double price;

    public Invoice(){
        partno="A201";
        desc="september invoice..";
        quantity=0;
        price=0.0;
    }

    public Invoice(String p,String d,int q,double price){
       partno=p;
       desc=d;
       quantity=q;
       this.price=price;
    }

    public void setPartNo(String partno){
        this.partno=partno;
    }

    public void setDesc(String desc){
        this.desc=desc;
    }

    public void setQuantity(int quantity){
        if(quantity<0)
            this.quantity=0;
        else
            this.quantity=quantity;
    }

    public void setPrice(double price){
        if(price<0)
            this.price=0;
        else
            this.price=price;
    }

    public String getPartNo(){return partno;}
    
    public String getDesc(){return desc;}

    public int getQuantity(){return quantity;}

    public double getPrice(){return price;}

    double getInvoiceAmount(){
        double a=quantity*price;
        return a;
    }

}

class InvoiceTest{
    Invoice i1=new Invoice();
   

    void test(){
        i1.setPartNo("A234");
        i1.setDesc("New item,good");
        i1.setQuantity(-5);
        i1.setPrice(-4);
        double p=i1.getPrice();
        int q =i1.getQuantity();
        System.out.println("price:"+p);
        System.out.println("partNo:"+i1.getPartNo());
        System.out.println("desc:"+i1.getDesc());
        System.out.println("quantity:"+i1.getQuantity());
        double amt=i1.getInvoiceAmount();
        System.out.println("amount:"+amt);
    }
}

