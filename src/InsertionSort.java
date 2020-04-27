public class InsertionSort {
    public int[] sort(int[] input) {
        for (int i = 1; i < input.length; i++) {
            int j = i - 1;
            int insert = input[i];

            while (j >= 0 && input[j] > insert) {
                input[j+1] = input[j];
                --j;
            }

            input[j+1] = insert;
        }
        return input;
    }

    public static void main(String[] args) {
        InsertionSort sortThis = new InsertionSort();
        int[] unsorted = new int[]{9,8,5,3,2,1};
        int[] sorted = sortThis.sort(unsorted);
        for (int num : sorted) {
            System.out.println(num);
        }
    }
}
