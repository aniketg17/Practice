public class InsertionSort {
    public int[] sort(int[] input) {
        for (int i = 0; i < input.length; i++) {
            int j = i - 1;
            int val = input[i];
            while (j >= 0 && input[j] > val) {
                input[j+1] = input[j];
                --j;
            }
            input[j+1] = val;
        }
        return input;
    }

    public static void main(String[] args) {
        InsertionSort sortThis = new InsertionSort();
        int[] unsorted = new int[]{4,3,2,1};
        int[] unsorted4 = new int[]{4,3,2,1};
        int[] sorted = sortThis.bubbleSORT(unsorted);
        int[] sorted2 = sortThis.exchangeSort(unsorted4);
      /*  for (int num : sorted) {
            System.out.println(num);
        }*/
    }


    public int[] bubbleSORT(int[] nums) {
        int x = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = 0; j < nums.length - i - 1; j++) {
             //   System.out.println(++x);
                if (nums[j] > nums[j+1]) {
                    System.out.println(++x);
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
        }
        return nums;
    }

    public int[] exchangeSort(int[] nums) {
        int x = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < i; j++) {
             //   System.out.println(++x);
                if (nums[j] > nums[i]) {
                    System.out.println(++x);
                    int temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                }
            }
        }
        return nums;
    }
}

















/*
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
 */