import java.util.Random;

public class RandomizedQuickSort {
    public static void main(String[] args) {
        int[] unsorted = {4,2,7,3,9,1};
        RandomizedQuickSort randomizedQuickSort = new RandomizedQuickSort();
        randomizedQuickSort.quickSort(unsorted, 0, unsorted.length - 1);
        for (int x : unsorted) {
            System.out.print(x + ",");
        }
    }

    public int randomPartition(int[] array, int start, int end) {
        Random random = new Random();
        int split = random.nextInt(end - start) + start;
        int temp = array[split];
        array[split] = array[end];
        array[end] = temp;
        int median = temp;


        while (true) {
            while (end >= 0 && array[end] >= median) {
                --end;
            }
            while (start < array.length && array[start] < median) {
                ++start;
            }
            if (start < end) {
                temp = array[start];
                array[start] = array[end];
                array[end] = temp;
            } else {
                return end;
            }
        }
    }


    public void quickSort(int[] array, int start, int end) {
        if (start < end) {
            int split = randomPartition(array, start, end);
            quickSort(array, start, split);
            quickSort(array, split+1, end);
        }
    }


}



















/*
 public int partitionRandom(int[] array, int low, int high) {
        Random rand = new Random();
        int randomIdx = rand.nextInt(high - low) + low;

        int median = array[randomIdx];
        array[randomIdx] = array[high];
        array[high] = median;

        int start = low;
        int end = high;
        while(true) {
            while (start <= high && array[start] <= median) {
                ++start;
            }
            while (end >= 0 && array[end] > median) {
                --end;
            }

            if (start < end) {
                int temp = array[start];
                array[start] = array[end];
                array[end] = temp;
            } else {
                return end;
            }
        }
    }

    public void quickSort(int[] unsorted, int start, int end) {
        if (start < end) {
            int middle = partitionRandom(unsorted, start, end);
            quickSort(unsorted, start, middle );
            quickSort(unsorted, middle +1, end);
        }
    }
 */