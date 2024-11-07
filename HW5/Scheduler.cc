#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Process
{

public:
    int id;
    int arrival_time;
    int burst;
    int priority;
    int final_burst;

    Process() {}

    Process(int processAttributes[])
    {
        id = processAttributes[0];
        arrival_time = processAttributes[1];
        burst = processAttributes[2];
        priority = processAttributes[3];
        final_burst = burst;
    }
};

class Scheduler
{

public:
    vector<Process> processes;

    Scheduler(vector<Process> process_vector)
    {
        processes = process_vector;
    }

    string FCFS()
    {

        // compute turnaround time
        double total_time = 0;
        double completion_timer = 0; // time elapsed

        for (size_t i = 0; i < processes.size(); i++)
        {
            completion_timer += processes[i].burst;
            total_time += completion_timer - processes[i].arrival_time;
        }

        double avg_tat = total_time / processes.size();

        // compute avg waiting time
        total_time = 0;
        int start_timer = 0;

        for (size_t i = 0; i < processes.size(); i++)
        {
            total_time += start_timer - processes[i].arrival_time;
            start_timer += processes[i].burst;
        }

        double avg_wait_time = total_time / processes.size();

        // compute throughput
        double throughput = processes.size() / (completion_timer);

        cout << fixed << setprecision(3) << "--- FCFS ---"
             << "\nAverage Turnaround Time: " << avg_tat
             << "\nAverage Waiting Time: " << avg_wait_time
             << "\nThroughput: " << throughput << endl;
        return "";
    }

    string SJFP()
    {
        int current_time = 0;
        int total_time = 0;   // total burst time
        double total_tat = 0; // for avg turnaround time
        double tat = 0;
        double avg_tat = 0;
        double total_wait = 0; // for avg wait time
        double avg_wait = 0;
        double throughput = 0;

        vector<Process> process_queue;
        size_t at_index = 0; // arrival time

        for (size_t i = 0; i < processes.size(); i++)
        {
            // get total burst time
            total_time += processes[i].burst;
        }

        while (current_time < total_time + 1)
        {
            if (!process_queue.empty()){
                process_queue[0].burst--;
                //cout << "current p index burst: " << process_queue[0].burst << endl;
            }

            //cout << "current time: " << current_time << endl;
            // add processes with current time to queue
            while (at_index < (processes.size()) && processes[at_index].arrival_time == current_time)
            {
                if (process_queue.empty())
                {
                    process_queue.push_back(processes[at_index]);
                }
                else
                {
                    bool smallerburst = false;
                    for (size_t i = 0; i < process_queue.size(); i++)
                    {
                        if (processes[at_index].burst < process_queue[i].burst)
                        {
                            process_queue.insert(process_queue.begin() + i, processes[at_index]);
                            smallerburst = true;
                            break;
                        }
                    }
                    if (!smallerburst)
                    {
                        process_queue.push_back(processes[at_index]);
                    }
                }
                at_index++;
            }
            //cout << "process q size: " << process_queue.size() << endl;

            // if current process is done (remaining burst is 0)
            //   remove from queue & add completion time to total
            if (!process_queue.empty() && process_queue[0].burst == 0)
            {
                // add turnaround time to sum for avg tat
                tat = current_time - process_queue[0].arrival_time;
                total_tat += tat;

                // add wait time to sum for avg wait
                total_wait += tat - process_queue[0].final_burst;

                // remove from queue
                process_queue.erase(process_queue.begin());
            }
            
            current_time++;
        }

        avg_tat = total_tat / processes.size();
        avg_wait = total_wait / processes.size();
        throughput = processes.size() / static_cast<double> (total_time);

        cout << fixed << setprecision(3) << "--- SJFP ---"
             << "\nAverage Turnaround Time: " << avg_tat
             << "\nAverage Waiting Time: " << avg_wait
             << "\nThroughput: " << throughput << endl;
        return "";
    }

    string priority()
    {
        int current_time = 0;
        int total_time = 0;   // total burst time
        double total_tat = 0; // for avg turnaround time
        double tat = 0;
        double avg_tat = 0;
        double total_wait = 0; // for avg wait time
        double avg_wait = 0;
        double throughput = 0;

        vector<Process> process_queue;
        size_t at_index = 0; // arrival time

        for (size_t i = 0; i < processes.size(); i++)
        {
            // get total burst time
            total_time += processes[i].burst;
        }

        while (current_time < total_time + 1)
        {
            if (!process_queue.empty()){
                process_queue[0].burst--;
                // cout << "current process id: " << process_queue[0].id << endl;
                // cout << "current p index burst: " << process_queue[0].burst << endl;
            }

            // if current process is done (remaining burst is 0)
            //   remove from queue & add completion time to total
            if (!process_queue.empty() && process_queue[0].burst == 0)
            {
                // add turnaround time to sum for avg tat
                tat = current_time - process_queue[0].arrival_time;
                total_tat += tat;

                // add wait time to sum for avg wait
                total_wait += tat - process_queue[0].final_burst;

                // remove from queue
                process_queue.erase(process_queue.begin());
            }

            // cout << "current time: " << current_time << endl;
            // add processes with current time to queue
            while (at_index < (processes.size()) && processes[at_index].arrival_time == current_time)
            {
                if (process_queue.empty())
                {
                    process_queue.push_back(processes[at_index]);
                }
                else
                {
                    bool highpriority = false;
                    for (size_t i = 0; i < process_queue.size(); i++)
                    {
                        if (processes[at_index].priority < process_queue[i].priority)
                        {
                            process_queue.insert(process_queue.begin() + i, processes[at_index]);
                            highpriority = true;
                            break;
                        }
                    }
                    if (!highpriority)
                    {
                        process_queue.push_back(processes[at_index]);
                    }
                }
                at_index++;
            }
            //cout << "process q size: " << process_queue.size() << endl;
            
            current_time++;
        }

        avg_tat = total_tat / processes.size();
        avg_wait = total_wait / processes.size();
        throughput = processes.size() / static_cast<double> (total_time);


        cout << fixed << setprecision(3) << "--- Priority ---"
             << "\nAverage Turnaround Time: " << avg_tat
             << "\nAverage Waiting Time: " << avg_wait
             << "\nThroughput: " << throughput << endl;
        return "";
    }
};

Process tokenizer(string line)
{
    int processAttributes[4] = {
        -1,
        -1,
        -1,
        -1,
    };
    stringstream ss(line);
    string attribute;
    char del = ',';

    for (int i = 0; i < 4; i++)
    {
        getline(ss, attribute, del);
        processAttributes[i] = stoi(attribute);
    }

    // //TEST: confirms string input has been parsed
    // cout << "processAttribute tokenizer check: ";
    // for (int i = 0; i < 4; i++){
    //     cout << processAttributes[i] << " ";
    // }
    // cout << endl;

    Process process = Process(processAttributes);
    return process;
}

void sortProcesses(vector<Process> &processes)
{
    int min_index;
    for (size_t i = 0; i < processes.size() - 1; i++)
    {
        min_index = i;
        for (size_t j = i + 1; j < processes.size(); j++)
        {
            if (processes[j].arrival_time < processes[min_index].arrival_time)
            {
                min_index = j;
            }
        }
        Process temp = processes[min_index];
        processes[min_index] = processes[i];
        processes[i] = temp;
    }
}

void printProcess(Process process)
{
    cout << process.id << " ";
    cout << process.arrival_time << " ";
    cout << process.burst << " ";
    cout << process.priority << endl;
}

void printProcesses(vector<Process> processes)
{
    for (size_t i = 0; i < processes.size(); i++)
    {
        printProcess(processes[i]);
    }
}

int main(int argc, char *argv[])
{

    vector<Process> processes;

    ifstream inputFile(argv[1]);

    if (argc < 2)
    {
        cerr << "Missing filename" << endl;
    }

    if (!inputFile.is_open())
    {
        cerr << "Error opening the file : " << argv[1] << endl;
        return 1;
    }

    string line; // store each line of the file

    // process input file
    while (getline(inputFile, line))
    {
        Process process = tokenizer(line);
        processes.push_back(process);
    }

    // //TEST: selection sort method
    // printProcesses(processes);

    // sort by arrival time
    sortProcesses(processes);

    // cout << endl;
    // printProcesses(processes);

    Scheduler scheduler = Scheduler(processes);
    scheduler.FCFS();
    scheduler.SJFP();
    scheduler.priority();

    // //TEST: checks that process objects have been added to vector
    // int count = 0;
    // for (size_t i = 0; i < processes.size(); i++){
    //     count++;
    // }
    // cout << count << " processes were added to vector" << endl;

    inputFile.close();

    return 0;
}