class Solution {
public:
    string tens[10]={"Zero","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    string digits[20]={"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
  
    string int2string(int n)
    {
        if(n>=1000000000)
            return int2string(n/1000000000) + " Billion" + int2string(n%1000000000);
        
        else if(n>=1000000)
            return int2string(n/1000000)+ " Million" + int2string(n%1000000);
        
        else if(n>=1000)
            return int2string(n/1000)+ " Thousand" + int2string(n%1000);
        
        else if(n>=100)
            return int2string(n/100)+ " Hundred" + int2string(n%100);
        
        else if(n>=20)
            return " " + tens[n/10] + int2string(n%10);
        
        else if(n>=1)
            return " " + digits[n];
        
        else
            return "";
    }
    
    string numberToWords(int num) 
    {
        if(num==0)
            return "Zero";
        else
        {
            string res=int2string(num);
            return res.substr(1,res.size()-1);
        }
    }
};
