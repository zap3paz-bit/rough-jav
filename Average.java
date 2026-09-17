public class Average{
    public static void main(String[] args){
        if(args.length == 0){
            System.out.println("No Arguments");
        }

        int sum=0;
        for(int i=0;i<args.length;i++){
            sum+=Integer.parseInt(args[i]);
        }

        double avg=0;

        if(args.length!=0){
             avg = (double)sum/args.length;
        }
       
        System.out.println("Average:"+avg);
    }
}