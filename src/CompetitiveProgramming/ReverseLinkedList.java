package CompetitiveProgramming;

public class ReverseLinkedList {
    private static class Node {
        int val;
        Node next;

        public Node(int val) {
            this.val = val;
            next = null;
        }
    }

    public static Node reverseList(Node head) {
        Node prev = null;
        Node curr = head;
        Node next = head.next;

        while (next != null) {
            curr.next = prev;
            prev = curr;
            curr = next;
            next = next.next;
        }

        curr.next = prev;

        return curr;
    }

    public static void main(String[] args) {
        Node head = new Node(4);
        head.next = new Node(5);
        head.next.next = new Node(6);
        head.next.next.next = new Node(7);

        head = reverseList(head);

        while (head != null) {
            System.out.print(head.val);
            head = head.next;
        }
    }
}
