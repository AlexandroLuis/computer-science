public class MinMax {
	public static void main (String[] args) {
		int[] nums = { 99, -10, 100, 19, 977, -562, 463, -9, 287, 49 };
		int min, max;
		min = max = nums[0];
		for(int i: nums) {
			if(i < min)
				min = i;
				if(i > max)
					max = i;
		}
		System.out.println("Min e Max: " + min + " " + max);
	}
}
