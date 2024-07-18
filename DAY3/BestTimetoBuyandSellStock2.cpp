int i=0;
int j=0;

while(j<n)
{
    if(j+i-1 < m)
        j++;
        
    else if(j+i-1==m)
    {
        int diff=a[i]-a[j];
        if(diff < mindiff)
            {
                mindiff=diff;
                i++;
                j++;
            }
    }
}
  return mindiff;  

}   
