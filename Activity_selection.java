import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Activity_selection {
    
    public class Activity{
       
       int start;
       int end;
    }
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        int n=input.nextInt();

        // Activityactivity=new Activity[n];
        // Arrays<Activity> sc=new Arrays(n);
        for(int i=0;i<n;i++)
        {
            activity[i].start=input.nextInt(); 
            activity[i].end=input.nextInt(); 
        }
        Arrays.sort(activity,Comparator.comparingInt(e->e.end));
        for(int i=0;i<n;i++)
        {
            System.out.println(activity[i].start+" "+activity[i].end);
        }
        
    }

    
}
