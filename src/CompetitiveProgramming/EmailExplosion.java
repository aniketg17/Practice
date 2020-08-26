package CompetitiveProgramming;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

/*
You have a ton of emails from the first week of school, and don't know in what
order to read and handle them. They come from professors, clubs, classmates, and companies.
They can have assignments, competitions, and applications with due dates, or
just notifications from social media. Some are longer than others.
Sort your emails so you can decide where to start.
image The most important part of the email is the purpose.
Application > Assignment > Competition > Notification
If it has a due date (Applications, Assignments, and Competitions),
hat is the next most important part. Lower due dates are more important than higher due dates.
The next most important part is the source.
Company > Professor > Classmate > Club
The least important part is the length. Shorter emails are more important than longer emails.
If two emails are equally important, keep them in the order they arrived in.

Input Format

You will be given the number of emails on the first line.
Each email will be a line with the purpose, due date if necessary, source, and length.
The due date will be in the format mmdd, so 0124 is january 24th.
Assume all dates are in one year, and you are at the start of the year.

Constraints

10 < Emails < 1000
Purpose = {Application, Assignment, Competition, Notification}
00 <= mm <= 12
00 <= dd <= 31
Source = {Company, Professor, Classmate, Club}
0 < Length < 65536
 */

public class EmailExplosion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numEmails = sc.nextInt();
        sc.nextLine();
        Comparator<Email> comparator = new EmailComparator();
        PriorityQueue<Email> emails = new PriorityQueue<>(comparator);
        for (int i = 0; i < numEmails; i++) {
            String line = sc.nextLine();
            String[] tokens = line.split(" ");
            Email mail;
            if (tokens[0].equals("Notification")) {
                mail = new Email(tokens[0], tokens[1], -10, Integer.parseInt(tokens[2]), i);
            } else {
                mail = new Email(tokens[0], tokens[2], Integer.parseInt(tokens[1]), Integer.parseInt(tokens[3]), i);
            }
            emails.add(mail);
        }

        while (!emails.isEmpty()) {
            System.out.println(emails.poll().idx);
        }
    }

    private static class EmailComparator implements Comparator<Email> {

        @Override
        public int compare(Email mail1, Email mail2) {
            if (mail1.purpose > mail2.purpose) {
                return -1;
            } else if (mail2.purpose > mail1.purpose) {
                return 1;
            } else {
                if (mail1.month < mail2.month) {
                    return -1;
                } else if (mail1.month > mail2.month){
                    return 1;
                } else if (mail1.date < mail2.date) {
                    return -1;
                } else if (mail1.date > mail2.date) {
                    return 1;
                } else {
                    if (mail1.source < mail2.source) {
                        return 1;
                    } else if (mail1.source > mail2.source){
                        return -1;
                    } else {
                        if (mail1.length < mail2.length) {
                            return -1;
                        } else if (mail2.length < mail1.length) {
                            return 1;
                        } else {
                            if (mail1.idx < mail2.idx) {
                                return -1;
                            } else {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }

    private static class Email {
        private int purpose;
        private int source;
        private int month;
        private int date;
        private int length;
        private int idx;

        public Email(String purpose, String source, int date, int length, int idx) {
            switch (purpose) {
                case "Notification":
                    this.purpose = 1;
                    break;
                case "Competition":
                    this.purpose = 2;
                    break;
                case "Assignment":
                    this.purpose = 3;
                    break;
                case "Application":
                    this.purpose = 4;
                    break;
            }

            if (purpose.equals("Notification")) {
                this.month = -1;
                this.date = -1;
            } else {
                this.month = date / 100;
                this.date = date % 100;
            }

            switch (source) {
                case "Company":
                    this.source = 4;
                    break;
                case "Professor":
                    this.source = 3;
                    break;
                case "Classmate":
                    this.source = 2;
                    break;
                case "Club":
                    this.source = 1;
                    break;
            }

            this.idx = idx;
            this.length = length;
        }
    }
}

/*
3
Notification Company 61736
Notification Club 53040
Notification Club 17204
 */