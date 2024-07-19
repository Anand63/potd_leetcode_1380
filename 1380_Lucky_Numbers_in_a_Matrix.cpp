class Solution {
public:



     //approach-1...........
     //finding the minimum element from each row and storing that into a vector min_element and in a same 
    //way visiting the array from colum wise and storig the max element of the every colum in a max_element
    //vector and simply visiting the array and finding the common element from this 2 vector
        void solve(int n,int m,vector<vector<int>>&matrix,vector<int>&min_element,vector<int>&max_element)
    {
            for(int i=0; i<n; i++)
            {   int min_ele=INT_MAX;
                for(int j=0; j<m; j++)
                {
                   min_ele=min(min_ele,matrix[i][j]);
                }
                min_element[i]=min_ele;
            }


            for(int j=0; j<m; j++)
            {   int max_ele=INT_MIN;
                for(int i=0; i<n; i++)
                {
                    max_ele=max(max_ele,matrix[i][j]);
                }
                max_element[j]=max_ele;
            }
    }
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>ans;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>min_element(n),max_element(m);
        solve(n,m,matrix,min_element,max_element);
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(min_element[i]==max_element[j])
                {
                    ans.push_back(min_element[i]);
                }
            }
        }
        return ans;
    }



    // approach 2.........
    // let suppose that we are having 2 lucky elements in a matrix called A,B and 
    //if A is lucky no then in its row it is smaller no and in its col it is the larger no in
    // a same way it apply for B also now consider for the element having row equal to row of B 
    // and col equal to col of A so let it be variable C so conclusion from that is A>C and C>B ===>A>B

    //NOW let a element D lying in row of A and col of B so from that we can conclude that D<B and D>A ===>B>A
    // hence it is contradicting the above condition that is A>B hence we can conclude that no more then 
    // 1 lucky element will lie in the matrix so will traverse to matrix untill we get a single lucky element 
};