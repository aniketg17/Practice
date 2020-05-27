
public class MergeSortAlgorithm {
    public static void main(String[] args) {
        int[] unsorted = {4,5,2,8,3,1,7,9};
        MergeSort(unsorted, unsorted.length);
        for (int x : unsorted) {
            System.out.print(x + " ");
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
}
