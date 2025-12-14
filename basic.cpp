#include <iostream>
#include <thread>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>

typedef struct {
    int x;
    int y;
} Point2d;


class RANSAC {
 private:
    int n; // numbers of inliners
    int m; // max iterations
    std::vector<Point2d> data;
    int threshold; // threshold for determining a good fit
    int k; // number of close points required for a good model fit
    int bestfit;
    int i = 0;

public:
    void execute();
    void insertdata(std::vector<Point2d>& insert);
};

void RANSAC::execute(){
    std::mt19937 rng{std::random_device{}()};
    std::uniform_int_distribution<size_t> dist(0, data.size() - 1);

    for (size_t j = 0; j < data.size(); j++) {
        size_t idx = dist(rng);
        std::cout << idx << std::endl;
    }
}

void RANSAC::insertdata(std::vector<Point2d>& insert){
    data = insert;
}



int main() {
std::vector<Point2d> test {
    {1, 0},
    {2, 0},
    {3, 0},
    {5, 0},
    {9, 9}
};
RANSAC testclass;
testclass.insertdata(test);
testclass.execute();
}