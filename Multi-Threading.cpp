//Created by: Alex Thomas
//Date: 2/27/2025
//Assignment: Project 1 Multi-Threading Programming

#include <iostream>
#include <mutex>
#include <thread>
#include <random>
#include <future>
#include <chrono>

//Shared resource for the threads
int savings = 1000;
int debit = 1000;
int transactionCount = 0;
//mutexes
std::timed_mutex m1;
std::timed_mutex m2;


void transfer(int amount, const std::string& from, const std::string& to ) {

    //lock the resources
    std::unique_lock<std::timed_mutex> lock1(m1, std::defer_lock);
    std::unique_lock<std::timed_mutex> lock2(m2, std::defer_lock);

    //lock acquisition order
    std::lock(lock1, lock2);

    //track the amount of transactions
    transactionCount ++;
    std::cout << "Transaction " << transactionCount << ": " << std::endl;

    //Balance before the transaction
    std::cout << "Savings before transfer: " << savings << std::endl;
    std::cout << "Debit before transfer: " << debit << std::endl;

    //determine what account the money withdrawals from and transfers to
    if (from == "savings" && to == "debit") {
        savings -= amount;
        debit += amount;
        std::cout << "Amount transferred to debit from savings : " << amount << std::endl;
    } else if (from == "debit" && to == "savings") {
        savings += amount;
        debit -= amount;
        std::cout << "Amount transferred to savings from debit : " << amount << std::endl;
    }

    //Balance after the transaction
    std::cout << "Savings after transfer: " << savings << std::endl;
    std::cout << "Debit after transfer: " << debit << std::endl;
    std::cout << "-------------------------" << std::endl;
}
int main() {

    //Title and initial balance
    std::cout << "Transfer Between Accounts: " << std::endl;
    std::cout << "Initial savings balance: " <<savings << std::endl;
    std::cout << "Initial debit balance: " <<debit << std::endl;
    std::cout << "-------------------------" << std::endl;

    //how many threads will be created
    int threadAmount = rand() % 100;

    //Hold the threads made by the random generator
    std::vector<std::thread> threads;

    //determine what the threads created will do based on the id they get
    for (int i = 0; i < threadAmount; i++) {
        //decide how much money to transfer between the accounts
        int transferAmount = rand()%100;
        if (i % 2 == 0) {
            threads.emplace_back(transfer, transferAmount, "savings", "debit");
        }
        else {
            threads.emplace_back(transfer, transferAmount, "debit", "savings");
        }
    }

    //join all the threads to ensure they complete before the main thread continues
    for (auto& thread : threads) {
        thread.join();
    }

    //spacer for the final balance of each account
    std::cout << "-------------------------" << std::endl;



    //Final balance of the accounts
    std::cout << "Final savings balance: " <<savings << std::endl;
    std::cout << "Final debit balance: " <<debit << std::endl;
    return 0;
}

