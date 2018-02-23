import java.util.*;

public class BinaryRadixSort {
	public static void binaryRadixSort(ArrayList<Integer> a) {
		int n = a.size(); ArrayList<Integer> a1 = a;
		Integer[] one = new Integer[n];
		Integer[] zero = new Integer[n];
		int value, tmp;
		
		for(int bit = 0; bit < 32; bit++) { 
			int onec = 0, zerc = 0;
			for(int i = 0; i < a1.size(); i++) {
				value = a1.get(i);
				tmp = 1 << bit;
				if((value & tmp) == 0) {
					zero[zerc] = value; zerc++;
				}
				else {
					one[onec] = value; onec++;
					
				}
				//System.out.println(zero.length);	
			}
			for(int i = 0; i < zerc; i++) { a1.set(i,zero[i]);}
			for(int i = 0; i < onec; i++) { a1.set(zerc + i,one[i]);}
		}
		a = a1;
	}
	public static void main(String[] args) {
		ArrayList<Integer> a = new ArrayList<Integer>(Arrays.asList(1, -4 , 2, 4, -6, 6, 0));
		ArrayList<Integer> a1 = new ArrayList<Integer>();
		ArrayList<Integer> a2 = new ArrayList<Integer>();
 		for(Integer i : a) {
 			if(i < 0) a1.add(i);
 			if(i >= 0) a2.add(i);
		}
		binaryRadixSort(a1); binaryRadixSort(a2);
		for(Integer i : a2) {
			a1.add(i);
		}
		System.out.println(a1);
	}
}