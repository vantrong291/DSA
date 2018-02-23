import java.util.*;

public class MergeSort {
	public static int compare(int a, int b) {
		int c = a >= b ? -1 : 1;
		return c;
	}
	public static void merge(int[] a1, int[] a2, int[] a) {
		int i = 0, j = 0;
		while(i + j < a.length){
			if(j == a2.length || (i < a1.length && compare(a1[i], a2[j]) > 0)) {
				a[i+j] = a1[i]; i++;
			}
			else {a[i+j] = a2[j]; j++;}
		}
	}
	public static void mergeSort(int[] a, int n) {
		if(n <= 1) return;
		else {
			int mid = n/2;
			int[] a1 = Arrays.copyOfRange(a, 0, mid);
			int[] a2 = Arrays.copyOfRange(a, mid, n);
			
			mergeSort(a1, a1.length);
			mergeSort(a2, a2.length);
			merge(a1, a2, a);
		}
	}
	public static void main(String[] args) {
		int[] a = {1, 7, 4, -3};
		mergeSort(a, a.length);
		for(int i : a) {
			System.out.println(i);
		}
	}
}

/*1    6      4    2     3
   1 6       4   2 3
   16       234
   6  234   1
   6  34     12
   6 4      123
   6        1234
            12346*/