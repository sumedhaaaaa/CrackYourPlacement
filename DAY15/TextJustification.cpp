class Solution {
public:
    int MAX_WIDTH;
    
    string solve(int i,int j,int spacebetweenwords,int extraspacebetweenwords,vector<string>&words)
    {
        string s;
        
        for(int k=i;k<j;k++)
        {
            s+=words[k];
            
            if(k==j-1)
                continue;
            
            for(int space=1;space<=spacebetweenwords;space++)
                s+=" ";
            
            if(extraspacebetweenwords > 0)
            {
                s+=" ";
                extraspacebetweenwords--;
            }
        }
        
        while(s.length() < MAX_WIDTH)
            s+=" ";
        
        return s;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>res;
        int n=words.size();
        MAX_WIDTH=maxWidth;
        int i=0;
        while(i<n)
        {
            int letter=words[i].size();
            int j=i+1;
            int space=0;
            
            while(j<n && words[j].size()+1+letter+space <= maxWidth)
            {
                letter+=words[j].size();
                space++;
                j++;
            }
            
            int remaining=maxWidth-letter;
            
            int spacebetweenwords= space ==0?0: remaining/space;
            int extraspacebetweenwords= space ==0?0:remaining%space;
            
            if(j==n)
            {
                spacebetweenwords=1;
                extraspacebetweenwords=0;
            }
            
            res.push_back(solve(i,j,spacebetweenwords,extraspacebetweenwords,words));
            i=j;
        }
        
        return res;
    }
};
