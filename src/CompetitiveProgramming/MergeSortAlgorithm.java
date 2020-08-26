package CompetitiveProgramming;

public class MergeSortAlgorithm {
    static int counter = 0;

    public static void main(String[] args) {
        int[] unsorted = {10,9,8,7,6,5,4,3,2,1};
        MergeSort(unsorted, 10);
        for (int x : unsorted) {
            System.out.print(x + " ");
        }
        System.out.println("counter is " + counter);
    }

    static void shellSort(int[] numbers) {
        int h = 1;
        while (h < numbers.length / 3) {
            h = 3 * h + 1;
        }

        while (h > 0) {
            for (int i = h; i < numbers.length; i += h) {
                for (int n = i; n > 0; n -= h) {
                    if (numbers[n] < numbers[n-h]) {
                        ++counter;
                        break;
                    } else {
                        ++counter;
                        int number = numbers[n];
                        numbers[n] = numbers[n - h];
                        numbers[n - h] = number;
                    }
                }
            }
            h = --h / 3;
        }
    }


    public static void MergeSort(int[] array, int length) {
        if (length < 2) {
            return;
        }
        int med = length / 2;
        int[] left = new int[med];
        int[] right = new int[length - med];


        for (int i = 0; i < med; i++) {
            left[i] = array[i];
        }

        for (int j = med; j < length; j++) {
            right[j - med] = array[j];
        }

        MergeSort(left, med);
        MergeSort(right, length - med);

        Merge(array, left, right);

    }

    public static void Merge(int[] array, int[] left, int[] right) {
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < left.length && j < right.length) {
            ++counter;
            if (left[i] < right[j]) {
                array[k++] = left[i++];
            } else {
                array[k++] = right[j++];
            }
        }
        while (i < left.length) {
            array[k++] = left[i++];
        }
        while (j < right.length) {
            array[k++] = right[j++];
        }
    }

    static void sort(int arr[])
    {
        int n = arr.length;
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;

            /* Move elements of arr[0..i-1], that are
               greater than key, to one position ahead
               of their current position */
            while (j >= 0 && arr[j] > key) {
                counter++;
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
}
