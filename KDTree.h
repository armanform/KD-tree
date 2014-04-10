/*
* This program is free software and you can redistribute it and/or modify
* it under the terms of the GNU General Public License
* This class implements simple KD tree structure without using Shogun or other 
* extrenal libraries(from scratch).
*
* Written (W) 2014 Zharmagambetov Arman armanform@gmail.com
*/

#include <cmath>
#include <vector>
#include <cassert>

#ifndef _KDTREE_H_
#define _KDTREE_H_

using namespace std;

// Forward references
template <typename T> class KDTree;
template <typename T> class KDTNode;

template <typename T>
class KDTNode {
	friend class KDTree<T>;

protected:
	KDTNode *left, *right;	// left/right child
	vector<T> data;		// the actual data item
	// access to the node contents
	// this is a bit dangerous, hence private
	inline vector<T>& content() {
		return data;
	}

public:
	KDTNode(const vector<T>& x) : left(NULL), right(NULL), data(x) {}

	inline KDTNode* get_left() {
		return left;
	}
	inline KDTNode* get_right() {
		return right;
	}
	inline vector<T> get_data() {
		return data;
	}

	// remove whole subtree
	// note that one must unlink a node
	// before destroying it in KDTree::remove()
	// otherwise the whole subtree will disappear
	~KDTNode() {
		if (left) {
			delete left;
		}
		if (right) {
			delete right;
		}
	}
};

/*!Begin Snippet:interface*/
template <typename T>
class KDTree {

protected:
	KDTNode<T> *root;	// root of tree
	int count;        // size of tree
	int dimensionOfFeatures;

public:
	KDTree() : root(NULL), count(0) {}

	inline int size() const {
		return count;
	}

	void train_kd(vector<vector<T>> elements, vector<T> labels);
	vector<T> FindNearestNeighbor(vector<T> location);
	vector<vector<T>> FindNearestNNeighbor(vector<T> location, int numNeighbors);
	T ClassifyKNierestNeighbor(vector<T> location, int k_nn);
	
protected:
	bool vectorComparer(vector<T> v1, vector<T> v2);
	KDTNode<T>* construct_helper(KDTNode<T>*& nodep, int dimension, int startIndex, int endIndex, 
								int depth, vector<vector<T>> elements);
	void sortByDimension(vector<vector<T>>& elements, int start, int end, int currentDim);
	int sortPartition(vector<vector<T>>& elements, int start, int end, int currentDim);
	double distanceByEuclidean(vector<T> v1, vector<T> v2);
	vector<T> FindNearestNeighborHelper(vector<T> location, KDTNode<T>*& nodep, 
		vector<T> bestValue, double bestDistance, int depth);
	void FindNearestNNeighborHelper(vector<T> location, KDTNode<T>*& nodep, vector<T>& bestValue, double& bestDistance, 
		int numNeighbors, vector<vector<T>>& valuesList, int depth);
	void sortByDistance(vector<vector<T>>& valuesList, int start, int end, vector<T> location);
	int sortDistancePartition(vector<vector<T>>& valuesList, int start, int end, vector<T> location);
};

#include "KDTree.hpp"

#endif