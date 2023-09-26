
#include <stdio.h>

int main()

{
    int k;
    printf("Enter 1 for FCFS \nEnter 2. for SJF \nEnter 3. for RR");
    printf("\nYour choice is:");
    scanf("%d", &k);
    switch (k)
    {
    case 1:
        printf("FCFS");
        int n, bt[20], wt[20], tat[20], avwt = 0, avtat = 0, i, j;
        printf("\nEnter total number of processes(maximum 20):");
        scanf("%d", &n);
        printf("\nEnter Process Burst Time:");
        for (i = 0; i < n; i++)
        {
            printf("P[%d]:", i + 1);
            scanf("%d", &bt[i]);
        }
        wt[0] = 0;
        for (i = 1; i < n; i++)
        {
            wt[i] = 0;
            for (j = 0; j < i; j++)
                wt[i] += bt[j];
        }
        printf("\nProcessttBurst TimetWaiting TimetTurnaround Time");
        for (i = 0; i < n; i++)
        {
            tat[i] = bt[i] + wt[i];
            avwt += wt[i];
            avtat += tat[i];
            printf("\nP[%d]\t\t%d\t\t%d\t\t%d", i + 1, bt[i], wt[i], tat[i]);
        }
        avwt /= i;
        avtat /= i;
        printf("\nAverage Waiting Time:%d", avwt);
        printf("\nAverage Turnaround Time:%d", avtat);

        return 0;
        break;
    // sjf
    case 2:
        printf("SJF");
        int  b_t[20], p[20], w_t[20], t_at[20], a, b, m, total = 0, pos, temp;
        float avg_wt, avg_tat;
        printf("\nEnter number of process:");
        scanf("%d", &m);
        printf("Enter Burst Time:");
        for (a = 0; a < m; a++)
        {
            printf("p%d:", a + 1);
            scanf("%d", &b_t[a]);
            p[a] = a + 1;
        }
        for (a = 0; a < m; a++)
        {
            pos = a;
            for (b = a + 1; b < m; b++)
            {
                if (b_t[b] < b_t[pos])
                    pos = b;
            }
            temp = b_t[a];
            b_t[a] = b_t[pos];
            b_t[pos] = temp;

            temp = p[a];
            p[a] = p[pos];
            p[pos] = temp;
        }

        w_t[0] = 0;
        for (a= 1; a < m; a++)
        {
            w_t[a] = 0;
            for (b = 0; b < a; b++)
                w_t[a] += b_t[b];

            total += w_t[a];
        }
        avg_wt = (float)total / m;
        total = 0;
        printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
        for (a = 0; a < m; a++)
        {
            t_at[a] = b_t[a] + w_t[a];
            total += t_at[a];
            printf("\np%d\t\t  %d\t\t    %d\t\t\t%d", p[a], b_t[a], w_t[a], t_at[a]);
        }

        avg_tat = (float)total / m;
        printf("\nAverage Waiting Time=%f", avg_wt);
        printf("\nAverage Turnaround Time=%f", avg_tat);
        return 0;
        break;
    // rr
    case 3:
        printf("ROUND ROBIN");
        int c, limit, to_tal = 0, x, counter = 0, time_quantum;
        int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp1[10];
        float average_wait_time, average_turnaround_time;
        printf("\nEnter Total Number of Processes:");
        scanf("%d", &limit);
        x = limit;
        for (c = 0; c < limit; c++)
        {
            printf("\nEnter Details of Process[%d]", c + 1);
            printf("\nArrival Time:");
            scanf("%d", &arrival_time[c]);
            printf("\nBurst Time:");
            scanf("%d", &burst_time[c]);
            temp1[c] = burst_time[c];
        }
        printf("\nEnter Time Quantum:");
        scanf("%d", &time_quantum);
        printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time");
        for (to_tal = 0, c = 0; x != 0;)
        {
            if (temp1[c] <= time_quantum && temp1[c] > 0)
            {
                to_tal = to_tal + temp1[c];
                temp1[c] = 0;
                counter = 1;
            }
            else if (temp1[c] > 0)
            {
                temp1[c] = temp1[c] - time_quantum;
                to_tal = to_tal + time_quantum;
            }
            if (temp1[c] == 0 && counter == 1)
            {
                x--;
                printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", c + 1, burst_time[c], to_tal - arrival_time[c], to_tal - arrival_time[c] - burst_time[c]);
                wait_time = wait_time + to_tal - arrival_time[c] - burst_time[c];
                turnaround_time = turnaround_time + to_tal - arrival_time[c];
                counter = 0;
            }
            if (c == limit - 1)
            {
                c = 0;
            }
            else if (arrival_time[c+ 1] <= to_tal)
            {
                c++;
            }
            else
            {
                c = 0;
            }
        }
        average_wait_time = wait_time * 1.0 / limit;
        average_turnaround_time = turnaround_time * 1.0 / limit;
        printf("\nAverage Waiting Time:t%f", average_wait_time);
        printf("\nAvg Turnaround Time:t%f", average_turnaround_time);
        return 0;
        break;
    default:
        printf("invalid");
    }
}

