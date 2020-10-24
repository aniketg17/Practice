package CP2;

import java.io.*;
import java.util.*;

public class BuildDependencies {

    static HashMap<String, Integer> degree = new HashMap<>();
    static HashMap<String, Boolean> seen = new HashMap<>();

    public static void main(String[] args) throws IOException {
        Main.FastReader sc = new Main.FastReader();
        int n = sc.nextInt();
        HashMap<String, HashSet<String>> graph = new HashMap<>();

        for (int i = 0; i < n; i++) {
            String[] input = sc.nextLine().split(" ");
            input[0] = input[0].substring(0, input[0].indexOf(":"));
            for (int j = 1; j < input.length; j++) {
                if (!graph.containsKey(input[j]) || graph.get(input[j]) == null) {
                    graph.put(input[j], new HashSet<>());
                }
                graph.get(input[j]).add(input[0]);
            }
        }
        String start = sc.nextLine();
        degree.put(start, 0);
        seen.put(start, true);
        dfs(start, graph);
        topoSort(graph, start);
    }

    private static void topoSort(HashMap<String, HashSet<String>> graph, String start) {
        Deque<String> deq = new ArrayDeque<>();
        deq.add(start);
        while (!deq.isEmpty()) {
            String curr = deq.poll();
            System.out.println(curr);
            HashSet<String> next = graph.get(curr);
            if (next != null) {
                for (String s : next) {
                    int deg = degree.getOrDefault(s, 1) - 1;
                    degree.put(s,  deg);
                    if (deg == 0) {
                        deq.addLast(s);
                    }
                }
            }
        }
    }

    public static void dfs(String node, HashMap<String, HashSet<String>> graph) {
        Stack<String> stack = new Stack<>();
        stack.add(node);
        while (!stack.isEmpty()) {
            HashSet<String> neighbours = graph.get(stack.pop());
            if (neighbours != null) {
                for (String x : neighbours) {
                    if (!degree.containsKey(x)) {
                        degree.put(x, 1);
                        seen.put(x, true);
                        dfs(x, graph);
                    } else {
                        degree.put(x, degree.get(x) + 1);
                    }
                }
            }
        }
    }
}

class Main {
    static Comparator<int[]> comp = new Comparator<int[]>() {
        public int compare(int[] a, int[] b) {
            for (int i=0; i<a.length; i++) {
                if (a[i] < b[i])       return -1;
                else if (a[i] > b[i])  return 1;
            }
            return 0;
        }
    };

    public static void main(String[] args) throws IOException {
        // Use either of FastReader or Scanner for input.
        FastReader in = new FastReader();
        // Scanner in = new Scanner(System.in);

        PrintWriter out = new PrintWriter(System.out);

        out.close();
    }

    /* FastReader code from Method 4 in the post https://www.geeksforgeeks.org/fast-io-in-java-in-competitive-programming/
       Modified nextLine() to allow arbitrary long lines,
       Modified fillBuffer(), read() to fix some issues
       Added next(), and hasNext()
       Use nextInt(), nextLong(), or nextDouble() to read numbers
       Use next() to read a string.
       Use nextLine() to read in the next line that is not empty (i.e., it
           contains at least one character that is > 32 (' ').
    */
    static class FastReader {
        final private int BUFFER_SIZE = 1 << 16;
        private int MAX_LINE_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer, lineBuf;
        private int bufferPointer, bytesRead;

        public FastReader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            lineBuf = new byte[MAX_LINE_SIZE];
            bufferPointer = bytesRead = 0;
        }
        public FastReader(String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
        public boolean hasNext() throws IOException {
            byte c;
            while ((c = read()) != -1) {
                if (c > ' ') {      // Find first byte bigger than ' '
                    bufferPointer--;
                    return true;
                }
            }
            return false;
        }
        // return the next line that contains at least one character > ' '
        public String nextLine() throws IOException {
            int ctr = 0;
            byte c;
            boolean empty = true;
            while ((c = read()) != -1) {
                if (c == '\r')        continue;     // ignore '\r'
                if (c == '\n') {
                    if (empty)  { ctr = 0;   continue;  } // read only spaces etc. until \n
                    else        break;
                }
                if (ctr == MAX_LINE_SIZE) {
                    MAX_LINE_SIZE *= 2;
                    lineBuf = Arrays.copyOf(lineBuf, MAX_LINE_SIZE);
                }
                lineBuf[ctr++] = c;
                if (c > ' ')  empty = false;
            }
            return new String(lineBuf, 0, ctr);
        }
        public String next() throws IOException {
            int ctr = 0;
            byte c = read();
            while (c <= ' ')    c = read();
            while (c > ' ') {
                if (ctr == MAX_LINE_SIZE) {
                    MAX_LINE_SIZE *= 2;
                    lineBuf = Arrays.copyOf(lineBuf, MAX_LINE_SIZE);
                }
                lineBuf[ctr++] = c;
                c = read();
            }
            return new String(lineBuf, 0, ctr);
        }
        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ')   c = read();
            boolean neg = (c == '-');
            if (neg)           c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg)           return -ret;
            return ret;
        }
        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')    c = read();
            boolean neg = (c == '-');
            if (neg)            c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)            return -ret;
            return ret;
        }
        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)    c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }
            if (neg)     return -ret;
            return ret;
        }
        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
        }
        private byte read() throws IOException {
            if (bufferPointer == bytesRead)     fillBuffer();
            if (bytesRead <= 0)  return -1;  // No data
            return buffer[bufferPointer++];
        }
        public void close() throws IOException {
            if (din == null)       return;
            din.close();
        }
    }
}