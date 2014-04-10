#include <iostream>
#include <vector>
#include "KDTree.h"
#include <cassert>
using namespace std;

int main()
{
	KDTree<float> kdtree;

	vector<float> testSet1;
	testSet1.push_back(1);
	testSet1.push_back(2);

	vector<float> testSet2;
	testSet2.push_back(2);
	testSet2.push_back(1);

	vector<float> testSet3;
	testSet3.push_back(4);
	testSet3.push_back(1);

	vector<float> testSet4;
	testSet4.push_back(3);
	testSet4.push_back(3);

	vector<float> testSet5;
	testSet5.push_back(1);
	testSet5.push_back(4);

	vector<float> testSet6;
	testSet6.push_back(6);
	testSet6.push_back(3);

	vector<vector<float>> testSets;
	testSets.push_back(testSet1);
	testSets.push_back(testSet2);
	testSets.push_back(testSet3);
	testSets.push_back(testSet4);
	testSets.push_back(testSet5);
	testSets.push_back(testSet6);

	vector<float> labels;
	labels.push_back(0);
	labels.push_back(0);
	labels.push_back(1);
	labels.push_back(0);
	labels.push_back(1);
	labels.push_back(1);

	//construct
	kdtree.train_kd(testSets, labels);


	vector<float> nntest;
	nntest.push_back(2);
	nntest.push_back(2);

	//find 1 nn
	//vector<float> nn = kdtree.FindNearestNeighbor(nntest);

	//find 3 nn
	//vector<vector<float>> testKNN = kdtree.FindNearestNNeighbor(nntest, 3);
	
	int get_class = kdtree.ClassifyKNierestNeighbor(nntest, 3);

	//assert(get_class == 1);

	cout << get_class << endl;

	system("pause");
	return 0;
}