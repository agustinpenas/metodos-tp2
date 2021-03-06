
#ifndef KNN_H_
#define KNN_H_

#include <bits/stdc++.h>

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::priority_queue;

typedef struct {
	int group;
	vector<double> vectorImage;
	double diff;
}imageDiff;

class KNN {
public:

	KNN() : groups_(vector<int>()),images_(vector<vector<double> >()) {
    }

	void train(vector<int> groups, vector<vector<double> > images);

	const vector<int> &getGroups();
	const vector<vector<double> > &getImages();

	int getGroupOf(vector<double>&, int);

private:
	vector<int> groups_; //lista de grupos, groups[i] tiene el grupo al que pertenece la imagen i.
	vector<vector<double> > images_; //lista de vectores de R^m.

	double getDifference(const vector<double> &a,const vector<double> &b);
};

#endif /* KNN_H_ */
