package com.faizan.CodeChef;
import java.util.*;
public class AdaKing {
    public static void main (String[] args) {

        Scanner sc=new Scanner(System.in);
        int tc=sc.nextInt();
        for(int t=0;t<tc;t++){
            int i=0;
            int k=sc.nextInt();
            {
                System.out.print("O");
                for(i=2;i<=k;i++){
                    System.out.print(".");
                    if(i%8==0){System.out.println();}
                }
                for(int j=i;j<=64;j++){
                    System.out.print("X");
                    if(j%8==0){System.out.println();}

                }
            }

        }
    }
}
