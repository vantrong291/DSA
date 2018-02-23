import java.util.*;

public class QuickSort {
	public static void swap(int a, int b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	public static void quickSort(ArrayList<Integer> a) {
		int n = a.size();
		if(n <= 1) return;
		else {
		int key = a.get(a.size() - 1);
		ArrayList<Integer> greater = new ArrayList<Integer>();
		ArrayList<Integer> smaller = new ArrayList<Integer>();
		ArrayList<Integer> equals = new ArrayList<Integer>();
		for(int i = 0; i < a.size(); i++) {
			if(a.get(i) < key) smaller.add(a.get(i));
			if(a.get(i) > key) greater.add(a.get(i));
			if(a.get(i) == key) equals.add(a.get(i));
		}
		quickSort(smaller);
		quickSort(greater);
		//quickSort(equals);
		a.clear();
		
		for(Integer i : smaller) a.add(i);
		for(Integer i : equals) a.add(i);
		for(Integer i : greater) a.add(i);
		}
	}
	public static void main(String[] args) {
		ArrayList<Integer> arr = new ArrayList<Integer>(Arrays.asList(1, 6, 4, 3, 7));
		quickSort(arr);
		for(Integer i : arr) { System.out.println(i);}
		
	}
}