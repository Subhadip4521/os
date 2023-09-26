import java.util.Scanner;

public class SJF {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter number of process: ");
        int n = sc.nextInt();
        int pid[] = new int[n];   
        int ar[] = new int[n];     
        int bt[] = new int[n];     
        int ct[] = new int[n];     
        int ta[] = new int[n];     
        int wt[] = new int[n];     
        int temp;
        float avgwt=0,avgtat=0;

        for(int i = 0; i < n; i++)
        {
            System.out.println("enter process " + (i+1) + " arrival time: ");
            ar[i] = sc.nextInt();
            System.out.println("enter process " + (i+1) + " burst time: ");
            bt[i] = sc.nextInt();
            pid[i] = i+1;
        }

        for(int i=0; i<n; i++){
            wt[i]=0; ta[i]=0;
        }


        for(int i=0; i<n; i++){
            for(int j=0; j<n-i-1; j++){
                if(bt[j]>bt[j+1]){
                    temp=bt[j];
                    bt[j]=bt[j+1];
                    bt[j+1]=temp;
                    temp=pid[j];
                    pid[j]=pid[j+1];
                    pid[j+1]=temp;
                }
            }
        }


        for(int i=0; i<n; i++){
            ta[i]=bt[i]+wt[i];
            wt[i+1]=ta[i];

        }

        ta[n]=wt[n]+bt[n];

        for(int j=0; j<n; j++){
            ta[j]=wt[j]+bt[j];
            avgwt+=wt[j];
        }



        System.out.println("\nPid  Arrival  Burst  Complete Turn Waiting");
        for(int  i = 0 ; i< n;  i++)
        {
        System.out.println(pid[i] + "   " + ar[i] + "   " + bt[i] + "   " + ct[i] + "   " + ta[i] + "   "  + wt[i] ) ;
        }
        sc.close();
        System.out.println("\naverage waiting time: "+ (avgwt/n));     
        System.out.println("average turn around time:"+(avgtat/n)); 
    }
}
