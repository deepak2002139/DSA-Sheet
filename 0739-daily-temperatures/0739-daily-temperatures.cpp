class Solution {
    void printvec(vector<int> &temperatures){
        for(int i =0;i<temperatures.size();i++){
            cout<<" i = "<<  i << " value= "<< temperatures[i]<<endl;
        }
        cout<<endl;
    }
    void printstack(stack<pair<int,int>> s1){
        pair<int,int> p;
        while(!s1.empty()){
            p=s1.top();
            s1.pop();
            cout<< p.first<<"  "<<p.second<<endl;
        }
        cout<<endl;
    }
    
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s1;
        for(int i =temperatures.size()-1;i>=0;i--){
            
            while(!s1.empty()){
                pair<int,int>temp;
                temp=s1.top();
                if(temp.first>temperatures[i]){
                    pair<int,int>temp2(temperatures[i],i);
                    s1.push(temp2);
                    temperatures[i]=temp.second-i;
                    break;
                }
                else{
                    s1.pop();
                }  
            }

            if(s1.empty()){
                pair<int,int>p(temperatures[i],i);
                s1.push(p);
                temperatures[i]=0;
            }
            // cout<<" this value of temperatures for i = "<< i <<endl;
            // printvec(temperatures);
            // printstack(s1);


        }

        return temperatures;
    }
};
