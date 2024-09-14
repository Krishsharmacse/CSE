public class quickFind{

    private int id[];

    public quickFind(int n){
        id = new int[n];
        for(int i = 0; i<n; i++){
            id[i] = i;
        }

        for(int i:id){
            System.out.print(" "+ i +" ");
        }
        System.out.println();
    }

    public boolean isConnected(int p, int q){
        return id[p] == id[q];
    }

    public String union(int a, int b){
        if(a>id.length || b>id.length){
            return "invalid";
        }

        int temp = id[a];
        id[a] = id[b];
        for(int i=0;i<id.length;i++){
            if(id[i] == temp){
                id[i] = id[b];
            }
        }
        for(int i:id){
            System.out.print(" "+ i +" ");
        }
        System.out.println();

        return String.format("(%d, %d)", a,b);
    }


    public static void main(String args[]){

        quickFind qf = new quickFind(10);

        System.out.println(qf.isConnected(0, 1));
        
        qf.union(1,2);
        qf.union(4,2);
        qf.union(4,9);
        
        System.out.println(qf.isConnected(0, 1));

    }
}