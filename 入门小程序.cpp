
//最大公约数
min=i<j?i:j;
for (k=min;k>=1;k--)
{if (i%k==0&&j%k==0) break;}

//最小公倍数
max=i>j?i:j;
for (k=max;1;k++)
{if (k%i==0&&k%j==0) break;}

//100~200间的素数
int counter=0;
for (n=100;n<=200;n++)
{
	for (m=n-1;m>=1;m--)
	{
		if (n%m==0) break;
	}
	if (m==1)
	{
		counter++;
		if (counter%5==0) {cout<<endl;}
		cout<<setw(6)<<n;
	}
}

//换硬币  100=m+2n+5k
int m,n,k,counter=0;
for (m=1;m<=93;m++)
for (n=1;n<=47;n++)
for (k=1;k<=19;k++)
{if (m+2*n+5*k==100) counter++;}
cout<<counter;

//大夫排班
int a,b,c,d,e,g;
for (a=6;a<=7;a++)
for (b=1;b<=3;b++)
for (c=5;c<=6;c++)
for (d=3;d<=7;d++)
for (g=5;g<=7;g++)
{if (a==c+1&&d==e+2&&b+3==g) goto f;}
f:for (ch='A';ch<="G';ch++)
cout<<setw(4)<<ch;

//i大j小
if (i<j)
{
	temp=i;
	i=j;
	j=temp;
}

//辗转相除法 (i>j)
do
{
	k=i%j;
	i=j;
	j=k;
}while (j!=0);
cout<<i;

//把正整数各位数字逆序输出
do
{
	digit=n%10;
	cout<<digit;
	n=n/10;
}while (n>0);

//乘法九九表
for (row=1;row<=9;row++)
{
	cout<<setw(4)<<row;
	for (col=1;col<=row;col++)
		cout<<setw(4)<<row*col;
	cout<<endl<<endl;
}

//字母塔
for (centralch='A';centralch<=lastch;centralch++)
{
	for (i=1;i<='Z'-centralch+10;i++)
		cout<<BLANK;
	for (ch='A';ch<=centralch;ch++)
		cout<<ch;
	for (ch=centralch-1;ch>='A';ch--)
		cout<<ch;
	cout<<endl;
}

//穷举法求最大公约数
min=i<j?i:j;
for (k=min;k>=1;k--)
if (i%k==0&&j%k==0) break;

//数组元素值逆序排列
for (i=0;i<n/2;i++)
{
	temp=a[i];
	a[i]=a[n-1-i];
	a[n-1-i]=temp;
}

//排序
for (i=0;i<n-1;i++)
{
	k=i;
	for (j=i+1;j<n;j++)
		if (a[k]>a[j])
			k=j;
	if (k!=i)
	{
		temp=a[i];
		a[i]=a[k];
		a[k]=temp;
	}
}
for (i=n;i>=1;i--)
for (j=1;j<=n-i+1;j++)
{
	a[j][i+j-1]=k;k++;
}
for (i=2;i<=n;i++)
for (j=1;j<=n-i+1;j++)
{a[i+j-1][j]=k;k++;}

//计算最大、最小数及其对应位置
for (counter=2;counter<=num;counter++)
{
	current=ia[counter];
	if (current>maxi)
	{
		maxi=current;
		nmax=counter;
	}
	else if (current<mini)
	{
		mini=current;
		nmin=counter;
	}
}
