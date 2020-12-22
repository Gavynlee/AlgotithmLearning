//
// Created by Gavyn on 2020/9/15.
//
#include<bits/stdc++.h>
using namespace std;

struct Node{
    float x, y;
};

vector<float> ransac(vector<Node>& vec,float outlier_prob,float accept_prob=1e-3,float threshold=10.0)
{
    default_random_engine random_num;
    int n_sample = vec.size();
    int n = 2;
    float inlier_prob = 1 - outlier_prob;
    float sample_fail = 1 - inlier_prob*inlier_prob;
    int k = log(accept_prob) / log(sample_fail);

    float res_a, res_b, res_c;
    float min_error = numeric_limits<float>::max();
    while(k--){
        uniform_int_distribution<int> sampler(0, n_sample-1);
        int idx1=0, idx2=0;
        while(idx1==idx2){
            idx1 = sampler(random_num);
            idx2 = sampler(random_num);
        }
        Node p1=vec[idx1], p2=vec[idx2];
        float a = p2.y - p1.y;
        float b = p1.x - p2.x;
        float c = (p2.x * p1.y) - (p2.y * p1.x);
        float error = 0.0;
        int n_inlier = 0;
        for(int i=0; i<n_sample; ++i){
            float err_i = fabs(a*vec[i].x + b*vec[i].y + c);
            if(err_i < threshold){
                ++n_inlier;
                error += err_i;
            }
        }
        if(static_cast<float>(n_inlier)/static_cast<float>(n_sample) > 0.7){
            if(error < min_error){
                min_error = error;
                res_a = a;
                res_b = b;
                res_c = c;
            }
        }
    }
    return {res_a, res_b, res_c};
}

int main(){
    int N=0;
    cin >> N;
    vector<Node> vec(N, {0,0});
    for(int i=0; i< N; ++i)
        cin>> vec[i].x >> vec[i].y;
    double x;
    cin >> x;
    auto res = ransac(vec, x, 1e-4, 10);
    cout<< res[0] << " " << res[1] << " " << res[2] << endl;
}

//第二题
#include<bits/stdc++.h>
using namespace std;

typedef struct{
    int min_row;
    int min_col;
    int max_row;
    int max_col;
}Rectangle;

typedef struct{
    Rectangle box;
    float score;
    int index;
}BoundingBox;
bool compScore(BoundingBox a, BoundingBox b) {
    if(a.score>b.score)
        return true;
    else
        return false;
}
static float get_boxs_IOU(Rectangle Rectangle1, Rectangle Rectangle2)
{
    int xx1, yy1, xx2, yy2;

    xx1 = max(Rectangle1.min_row, Rectangle2.min_row);
    yy1 = max(Rectangle1.min_col, Rectangle2.min_col);
    xx2 = min(Rectangle1.max_row - 1, Rectangle2.max_row - 1);
    yy2 = min(Rectangle1.max_col - 1, Rectangle2.max_col - 1);

    int insection_width, insection_height;
    insection_width = max(0, xx2 - xx1 + 1);
    insection_height = max(0, yy2 - yy1 + 1);

    float insection_area, union_area, IOU;
    insection_area = float(insection_width) * insection_height;
    union_area = float((Rectangle1.max_row-Rectangle1.min_row)* (Rectangle1.max_col-Rectangle1.min_col) +
                       (Rectangle2.max_row-Rectangle2.min_row)* (Rectangle2.max_col-Rectangle2.min_col) -
                       insection_area);
    IOU = insection_area / union_area;
    return IOU;
}

void nms(vector<Rectangle>&boxes,vector<float>&scores,float confThreshold, float nmsThreshold, vector<int> &indices )
{
    BoundingBox b_;
    vector<BoundingBox> b_s;
    int i,j;
    for(i=0;i<boxes.size();i++){
        b_.box=boxes[i];
        b_.score=scores[i];
        b_.index=i;
        b_s.push_back(b_);
    }
    sort(b_s.begin(),b_s.end(),compScore);

    int b_s_size=b_s.size();
    for(i=0;i<b_s_size;i++){
        if(b_s[i].score<confThreshold)
            continue;
        indices.push_back(i);
        for(j=i+1;j<b_s_size;j++){
            float IOU=get_boxs_IOU(b_s[i].box,b_s[j].box);
            if(IOU>nmsThreshold){
                b_s.erase(b_s.begin()+j);
                b_s_size=b_s.size();
            }
        }
    }
}
