import java.util.Scanner;

public class CodeOptimizer{

    public static void main(String args[]){

        Scanner input = new Scanner(System.in);
        char replacingCharacter,replacementCharacter;
        int n;
        System.out.println("Enter the number of instructions");
        n = input.nextInt();


        String []instructionSet = new String[n];

        System.out.println("Enter the Instructions");
        for(int i=0;i<n;i++)
            instructionSet[i] = input.next();

        for(int i=0;i<n;i++){
            String firstString = instructionSet[i].substring(2,5);
            for(int j=0;j<n;j++){
                String secondString = instructionSet[j].substring(2,5);
                if(i==j)    
                    continue;
                else{
                    if(firstString.equals(secondString)){
                        replacementCharacter = instructionSet[i].charAt(0);
                        replacingCharacter = instructionSet[j].charAt(0);
                        /*System.out.println("Replacing Character "+replacingCharacter);
                        System.out.println("Replacement Character "+replacementCharacter);*/
                        
                         
                        for(int k=0;k<n;k++)
                            instructionSet[k] = instructionSet[k].replace(replacingCharacter,replacementCharacter);
                    }
                }
                
            }
        }

        //System.out.println(n);
        for(String instruction:instructionSet)
            System.out.println(instruction);

    }
}