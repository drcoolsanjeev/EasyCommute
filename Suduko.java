/**
 * Author: Sanjeev Kumar
 */

 /*
    Question: https://www.interviewbit.com/problems/valid-sudoku
 */

 /*
    Test Case 1:
    Input :
        53..7....
        6..195...
        .98....6.
        8...6...3
        4..8.3..1
        7...2...6
        .6....28.
        ...419..5
        ....8..79
    Output : Valid Suduko!!!
    Test Case 2:
    Input :
        53..7....
        6..191...
        .98....6.
        8...6...3
        4..8.3..1
        7...2...6
        .6....28.
        ...419..5
        ....8..79
    Output : Invalid Suduko!!!
 */
import java.util.*;

public class Suduko {
    
    public static int isValidSuduko(final List<String> A) { 
        char[][] arr = new char[9][9];
        int i=0,j=0;
        //check valid input 
        for (String s:A){
            for (j=0;j<s.length();j++){
                arr[i][j]=s.charAt(j);
                if (!Character.isDigit(arr[i][j]) && arr[i][j]!='.'){
                    return 0;
                }
            }
            i++;
        }
        HashSet<Character> set = new HashSet<Character>();

        for (j=0;j<9;j++){ //checking column
            set.clear();
            for (i=0;i<9;i++){
                if (!set.contains(arr[i][j]) && arr[i][j]!='.') {
                    set.add(arr[i][j]);
                } else if (arr[i][j]!='.'){
                    return 0;
                }
            }
        }

        for (i=0;i<9;i++){ // checking row
            set.clear();
            for (j=0;j<9;j++){
                if (!set.contains(arr[i][j]) && arr[i][j]!='.') {
                    set.add(arr[i][j]);
                } else if (arr[i][j]!='.'){
                    return 0;
                }
            }
        }

        
        for (i=0;i<9;i=i+3){// checking 9*9 small box
            for (j=0;j<9;j=j+3){
                set.clear();
                for (int k=0;k<3;k++)
                    for (int l=0;l<3;l++){
                        if (!set.contains(arr[i+k][j+l]) && arr[i+k][j+l]!='.') {
                            set.add(arr[i+k][j+l]);
                        } else if (arr[i+k][j+l]!='.'){
                            return 0;
                        }	                    
                    }
            }
        }
        return 1;
    }

    public static void main(String[] args)throws Exception {
        List<String> list = new ArrayList<String>();
        Scanner sc = new Scanner(System.in);
        for(int i=0;i<9;i++) {
            String s = sc.nextLine();
            list.add(s);
        }
        if (isValidSuduko(list)==0) {
            System.out.println("Invalid Suduko!!!");
        } else {
            System.out.println("Valid Suduko!!!");
        }
    }
}