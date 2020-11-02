#include<bits/stdc++.h>
#include<string>
#include<climits>
using namespace std;

class BigInteger
{
    public: string n1,n2;
    public: string add(string n1, string n2)
                {
                    long long int l1=n1.length();
                    long long int l2=n2.length();
                    long long int diff=abs(l1-l2);
                    if(l1>l2)
                    {
                        string t="";
                        t.append(diff,'0');
                        t+=n2;
                        n2=t;
                    }
                    else if(l1<l2)
                    {
                        string t="";
                        t.append(diff,'0');
                        t+=n1;
                        n1=t;
                    }
                    l1=n1.length();
                    l2=n2.length();
                    int carry=0,temp;
                    string res=n1;
                    for(long long int i=l1-1;i>=0;i--)
                    {
                        temp=(n1[i]-'0')+(n2[i]-'0')+carry;
                        carry=0;
                        if(temp>=10)
                        {
                            carry=temp/10;
                            temp-=10;
                        }
                        res[i]=(temp+'0');
                    }
                    if(carry>0)
                    {
                        res.insert(0,1,'1');
                    }
                    return res;
                }
    
    
    
            string subtract(string n1, string n2)
            {
                string res="";
                long long int l1=n1.length();
                long long int l2=n2.length(); 
                reverse(n1.begin(),n1.end()); 
                reverse(n2.begin(),n2.end()); 
                //cout<<n1<<" "<<n2<<endl;
                int carry = 0,diff;
                long long int i=0;
                for (i=0;i<l2;i++) 
                { 
                    diff=(n1[i]-'0')-(n2[i]-'0')-carry; 
                    if(diff<0) 
                    { 
                        diff=diff+10; 
                        //cout<<diff<<" ";
                        carry=1; 
                    } 
                    else
                    {
                        carry = 0;
                    }
                    res.push_back(diff+'0'); 
                } 
  
                while(i<l1) 
                { 
                    diff=((n1[i]-'0')-carry); 
                    if(diff<0) 
                    { 
                        diff=diff+10; 
                        //cout<<diff<<" ";
                        carry=1; 
                    } 
                    else
                    {
                        carry=0; 
                    }
                    res.push_back(diff+'0'); 
                    i++;
                } 

                reverse(res.begin(), res.end()); 
                res.erase(0, min(res.find_first_not_of('0'), res.size()-1));
                return res;
            }
    
            string multiply(string n1, string n2)
            {
                long long int l1=n1.length();
                long long int l2=n2.length();
                if(l1<l2)
                {
                    string temp=n1;
                    n1=n2;
                    n2=temp;
                }
                //cout<<n1<<" "<<n2<<" ";
                string res="0";
                l2=n2.length();
                l1=n1.length();
                int x;
                for(long long int i=l2-1;i>=0;i--)
                {
                    int curr=n2[i]-'0';
                    //cout<<curr<<" ";
                    int carry=0;
                    string t=n1;
                    for(long long int j=l1-1;j>=0;j--)
                    {
                        x=((t[j]-'0')*curr)+carry;
                        carry=0;
                        if(x>=10)
                        {
                            carry=x/10;
                            x=x%10;
                        }
                        t[j]=x+'0';
                    }
                    if(carry>0)
                    {
                        string z="";
                        z+=(carry+'0');
                        z.append(t);
                        t=z;
                    }
                    t.append((l2-i-1),'0'); //append zero of length l2-i-1 at the end 

                    res=add(res,t); //add t string to res
                }
                return res;
            }
    
            string gcd(string n1, string n2)
            {
                if(greater(n2,n1))
                {
                    swap(n1,n2);
                }
                if(n2=="0") return n1;
                else
                {
                    string rem  = divide(n1,n2);
                    // cout<<"rem : "<<rem<<endl<<endl;
                    return gcd(n2,rem);
                }
            }

            bool greater(string n1, string n2)
            {
                long long int l1=n1.length();
                long long int l2=n2.length();
                if(l1>l2)
                    return true;
                else if(l1<l2)
                    return false;
                else if(l1==l2)
                {
                    for(long long int i=0;i<l1;i++)
                    {
                        if(n1[i]>n2[i])
                            return true;
                        else if(n1[i]<n2[i])
                            return false;
                    }
                }
                    return true;
            }

            string divide(string n1, string n2)
            {
                long long int l1=n1.length();
                long long int l2=n2.length();
                if(n2=="0")
                {
                    return "0";
                }   
                //return "hey";
                if(l2>19)
                {
                    return repeatsub(n1,n2);
                }
                else
                {
                    return bigdivision(n1,n2);
                }
                    
            }

            string bigdivision(string n1,string n2)
            {
                long long  d=stoll(n2);
                string res; 
                long long int rem;
                long long int i=0; 
                long long int l1=n1.length();
                long long int l2=n2.length();
                long long int num=(n1[i]-'0'); 

                while(num<d) 
                {
                    i++;
                    num=(num*10) + (n1[i]-'0'); 
                }
                    
                
                while (i<l1) { 

                    res+=(num/d)+'0'; 
  	                rem=num%d;
                    i++;
                    num=(num%d)*10 + (n1[i]-'0'); 
                } 
                
                return to_string(rem); 
            }

            string repeatsub(string n1,string n2)
            {
                string rem=n1;
                while(greater(rem,n2))
                {
                    rem=subtract(rem,n2);
                }
                return rem;
            }

            string factorial(string s)
            {
                string f="1";
                long n=stol(s);
                for(long int i=1;i<=n;i++)
                {
                    f=multiply(f,(to_string(i)));
                }
                return f;
            }

            string FastExpo(string x, long long int y)
            {
                string res="1";
                int flag=0;
                if(x[0]=='-')
                {
                    x.erase(0,1);
                    if(y%2!=0)
                        flag=1;
                }
                string a=x;
                while(y>0)
                {
                    if(y&1!=0)
                    {
                        res=multiply(res,a);
                    }
                    a=multiply(a,a);
                    y=y>>1;
                }
                if(flag==1)
                {
                    res.insert(0,1,'-');
                }
                return res;
            }

};

int main()
{
    BigInteger c;
    long long int n;
    cin>>n;
    int q;
    string a,b; 
    for(long long int i=0;i<n;i++)
    {
        cin>>q;
        if(q==1)
        {
            cin>>a>>b;
            long long int n2=stoll(b);
            string m=c.FastExpo(a,n2);
            cout<<m<<endl;
        }
        else if(q==2)
        {
            cin>>a>>b;
            string m=c.gcd(a,b);
            cout<<m<<endl;
        }
        else if(q==3)
        {
            cin>>a;
            string m=c.factorial(a);
            cout<<m<<endl;
        }
    }
}
            
            
            
            
            
            
            
            
        }
    }
}
