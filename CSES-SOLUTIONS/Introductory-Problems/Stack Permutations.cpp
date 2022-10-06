class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int> s;
        int p=0;
        if(A.size()!=B.size())return 0;
        for(int i=0;i<N;i++){
            if(s.empty() || B[p]!=s.top()){
                s.push(A[i]);
            }
            
            while(!s.empty() && s.top()==B[p]){
                s.pop();
                p++;
            }
        }
        return (s.empty());
        }
};
